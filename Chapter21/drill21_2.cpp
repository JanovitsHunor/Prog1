#include <iostream>
#include <stdexcept>
#include <set>
#include <vector>
#include <string>

using namespace std;

struct Fruit {
	string name;
	int quantity;
	double unit_price;
	
	Fruit(const string& n, int q = 0, double p = 0.0) : name{n}, 
	quantity{q}, unit_price{p} {} // konstruktor

};

struct Fruit_ptr_cmp { 
	bool operator()(const Fruit* a, const Fruit* b){ // funktor - úgy tud viselkedni, mint egy függvény (a zárójel operátora felül lesz írva!)
		// return a->name < b->name; // nyílat kell használni, mert "a" és "b" pointerek!
		return a->quantity < b->quantity;
	}

};

int main() 
try {

	vector<Fruit> vf {
		Fruit{"Plum", 3}, // "Plum" - string, "3" - int, "" - double értékek!
		Fruit{"Grape", 33},
		Fruit{"Banana", 21},
		Fruit{"Apple", 3},
		Fruit{"Orange", 3},
		Fruit{"Cherry", 398},
		Fruit{"Plum", 74},
		Fruit{"Kiwi", 54}	
	};
	
	cout << "Vector values: " << endl;
	for (auto& f : vf) {
		cout << f.name << endl;
	}
	cout << endl;
	
	set<Fruit*, Fruit_ptr_cmp> sf;
	
	for (auto& f : vf) {
		sf.insert(&f);
	}
	
	cout << "Set values: " << endl;
	for (auto& f : sf) {
		cout << f->name << ", " << f->quantity << endl; // Set-nél erre ügyelni kell, mert őt csak nyíllal lehet elérni, mivel pointer típus!
	}
	cout << endl;
	
} catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
	return 1;
	
} catch (...) {
	cerr << "ERROR! Unknown exception!" << endl;
	return 2;
}
