#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <stdexcept>

using namespace std;

void read_map(map<string, int> m) {
	string s;
	int i = 0;
	
	while(m.size() < 10) {
		cin >> s >> i;
	//	m[s] = i;
		m.insert(make_pair(s,i));
	}

}

template<typename K, typename V>

void print(const map<K,V>& m) {
	int sum = 0;
	for(std::pair<K,V> a: m) { // value_type (ami itt V) ==>	std::pair<const Key, T>
	// for(auto& a : m) {
		cout << a.first << '\t' << a.second << endl;
		sum += a.second;
	}
	cout << "Az msi egész értékeinek összege: " << sum << endl;
}

int main() {
try {

	map<string, int> msi; // számít a lexikografikus sorrend, ezzel garantáható a rendezettség!
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 45;
	msi["X"] = 23;
	msi["g"] = 41;
	msi["wert"] = 92;
	msi["j"] = 30;
	msi["po"] = 11;
	msi["py"] = 67;
	msi["ac"] = 4; // ha egy meglévő kulcsra hivatkozunk, akkor felülírja az előző értékét!!
	
	print(msi);
	
	msi.erase("a"); // a értékű kulcspáros törlése a map-ből
	cout << "a elem törlése után: " << endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	cout << "A teljes törlés után: " << endl;
	print(msi);
	
	cout << "10 név_érték pár megadása: " << endl;
	read_map(msi);
	cout << "msi tartalma: " << endl;
	print(msi);
	
	
	/*int total = accumulate(msi.begin(), msi.end(), 0,
		[](int sum, const pair<string, int>& p)
		(return sum += p.second;)
		);
		
	total = accumulate(msi.begin(), msi.end(), 0);
	
	int total2 = 0;
	for(pair<string, int> a : msi) {
		total2 += a.second;
	}
	
	cout << "msi egész értékeinek összege: " << total << total2 << endl; */
	
	map<int, string> mis;
	
	for(pair<string, int> a : msi) {
		mis[a.second] = a.first;
		// mis.insert(make_pair<a.second, a.first>)); - ez is jó megoldás!
	}
	
	cout << endl << "mis map: " << endl;
	print(mis);
		
} catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
	return 1;
	
} catch (...) {
	cerr << "ERROR!" << endl;
	return 2;
	}
}
