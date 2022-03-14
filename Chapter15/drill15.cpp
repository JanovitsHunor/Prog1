#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		Person(){}
		// Person( string n, int a ) : n{n}, a{a} {
		Person( string f, string l, int a ) : f{f}, l{l}, a{a} {
			if( a < 0 || a >= 150) {
				throw runtime_error("Invalid age!"); }
		{	
			for( i = 0; i < name.length; i++)
		{
			if( name[i] == ';' || name[i] == '"' || name[i] == '`' || name[i] == '[]' ||
			name[i] == '*' || name[i] == '&' || name[i] == '^' || name[i] == '%' || name[i] == '$' || name[i] == '#'
			|| name[i] == '@' || name[i] == '!')
			{
				throw runtime_error("Invalid name!"); }
			}
		}
		};
		
		string name() const{ return name; }
		int age() const{ return age; }

	private:
		// string n;
		string f;
		string l;
		int a;
};

ostream& operator << ( ostream os, const Person& p ) {
	return os << p.name() << " " << p.age();
};

istream& operator << ( istream is, Person& p) {
	string n;
	int a;
	is >> n >> a;
	
	p = Person(n,a);
	return is;

};
int main(){
	
	Person p("Goofy", 63);
	cout << p.name() << ", " << p.age() << endl;

	//p1 neve="Goofy";
	//p.a=63;	
	
	Person p2;
	cin >> p2;
	cout << p2 << endl;
	
	vector<Person> vec;
	for(Person p2; cin >> p2;) {
		if(p.name() == endl) break;
		vec.push_back(p);
		}

	for (Person p2; vec) {
	cout << p2 << endl;
	}

}
