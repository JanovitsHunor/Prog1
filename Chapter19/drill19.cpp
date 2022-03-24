#include "std_lib_facilities.h"

template<typename T>
struct S
{
	// ---- konstruktorok
	S() {}

	S(T t)
		: val(t)
	{}

	// ---- módszerek
	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) { cin >> val; }

	void set(T t) { val = t; }
	const T& get() const { return val; }

	// visszatéríti a nem-konstans referenciákat a val értékbe
	T& getRef() { return val; }

private:
	// ---- változók
	T val;
};

template<typename T>
const T& get(S<T>& s)
{
	return s.get();
}

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
	S<vector<int>> svi;
	cout << "Enter ints in format { val, val, val } etc., : ";
	cin >> svi.getRef();
	cout << svi.getRef();

	S<vector<char>> svc;
	cout << "Enter chars in format { val, val, val } etc., : ";
	cin >> svc.getRef();
	cout << svc.getRef();

	S<vector<double>> svd;
	cout << "Enter doubles in format { val, val, val } etc., : ";
	cin >> svd.getRef();
	cout << svd.getRef();

	S<vector<double>> svf;
	cout << "Enter floats in format { val, val, val } etc., : ";
	cin >> svf.getRef();
	cout << svf.getRef();

	S<vector<string>> svs;
	cout << "Enter strings in format { val, val, val } etc., : ";
	cin >> svs.getRef();
	cout << svs.getRef();

	cout << endl;

	keep_window_open();
	return 0;
}