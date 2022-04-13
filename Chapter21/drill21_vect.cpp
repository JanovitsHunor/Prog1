#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>

using namespace std;

class Less_than {
	double v;
	public:
		Less_than(double vv) : v{vv} {}
		bool operator() (const double val) {return val < v;}
};

template<typename C>
void print(const C& c, char sep = '\n') {
	cout << "Elements of container: \n";
	
	for(const auto elem: c) {
		cout << elem << sep;
	}
	cout << endl;
	
}

int main() 
try {

	string iname {"input_floats.txt"};
	ifstream ifs {iname}; // állomány beolvasása a mappából!
	if ( !ifs ) throw runtime_error("Could not read from: " +iname);
	
	vector<double> vd;
	for(double d; ifs >> d;) {
		vd.push_back(d);
	}
	print(vd);
	
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i = 0; i < vd.size(); i++) {
		cout << vd[i] << '\t' << vi[i] << endl;
	
	}
	
	double vd_sum = accumulate(vd.begin(), vd.end(), 0.0);
	int prt = inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, plus<double>(), minus<double>());
	// inner_product = Kiszámítja a belső szorzatot (azaz a termékek összegét), vagy végrehajtja a rendezett leképezési/kicsinyítési műveletet a [first1, last1) tartományon és a first2-től kezdődő tartományon.
	
	cout << "The difference between vd and vi: " << prt << endl;
	
	reverse(vd.begin(), vd.end()); // vektor megforgatása!
	print(vd);
	
	double vd_mean = vd_sum / vd.size();
	cout << vd_mean << endl;
	
	vector<double> vd2(vd.size());
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean)); // szintakszis a copy_if függvényhez!
	vd2.resize(distance(vd2.begin(), it));
	
	print(vd2);
	
	sort(vd.begin(), vd.end());
	print(vd);
	
} catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
	return 1;
	
} catch (...) {
	cerr << "ERROR! Unknown exception!" << endl;
	return 2;
}
