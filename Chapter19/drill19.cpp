#include "std_lib_facilities.h"

template<typename T> struct S // Feladat #1
{
	// S() {} ---- konstruktorok

	S(T t = 0) : val(t) {} // Feladat #2
	T& get(); // Feladat #5

	// ---- módszerek
	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) { cin >> val; }

	void set(T t) { val = t; } // Feladat #9
	const T& get() const { return val; } // Feladat #11

	// visszatéríti a nem-konstans referenciákat a val értékbe
	T& getRef() { return val; }

private:
	// ---- változók
	T val;
};

// Feladat #5 & Feladat #6
template<typename T>
const T& get(S<T>& s)
{
	return s.get();
}

// Feladat #12
template<typename T>
void read_val(T& v)
{
	cin >> v;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vt)
{
	T temp;
	string s;
	while (is >> s)
	{
		if (s == "}")
			break;
		if (is.fail())
		{
			is.clear();
			is.ignore(INT_MAX, '\n');
		}
		if (s != "{" && s != " " && s != ",")
		{
			s.erase(remove(s.begin(), s.end(), ','));

			stringstream ss;
			ss << s;
			ss >> temp;
			vt.push_back(temp);
		}
	}

	return is;
}

// Feladat #14
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vt)
{
	os << "{ ";
	for (uint32_t i = 0; i < vt.size() - 1; ++i)
	{
		os << vt[i] << ", ";
	}
	os << vt[vt.size() - 1] << " }" << endl;
	return os;
}

int main()
{
	S<vector<int>> svi; // Feladat #3
	cout << "Enter ints in format { val, val, val } etc., : "; // Feladat #4 & Feladat #8
	cin >> svi.getRef();
	cout << svi.getRef();

	S<vector<char>> svc; // Feladat #3
	cout << "Enter chars in format { val, val, val } etc., : "; // Feladat #4 & Feladat #8
	cin >> svc.getRef();
	cout << svc.getRef();

	S<vector<double>> svd; // Feladat #3
	cout << "Enter doubles in format { val, val, val } etc., : "; // Feladat #4 & Feladat #8
	cin >> svd.getRef();
	cout << svd.getRef();

	S<vector<double>> svf; // Feladat #3
	cout << "Enter floats in format { val, val, val } etc., : "; // Feladat #4 & Feladat #8
	cin >> svf.getRef();
	cout << svf.getRef();

	S<vector<string>> svs; // Feladat #3
	cout << "Enter strings in format { val, val, val } etc., : "; // Feladat #4 & Feladat #8
	cin >> svs.getRef();
	cout << svs.getRef();

	cout << endl;

	keep_window_open();
	return 0;
}
