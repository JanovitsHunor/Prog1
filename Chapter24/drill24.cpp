#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

// Feladat #4 

void ex04()
{
    int i;
    cout << "\nEnter ints (char to exit): ";

    while (cin >> i) {
        errno = 0;
        double d = sqrt(i);
        if (errno == EDOM)
            cout << "Doesn't have an accurate square root!\n";
        else
            cout << "sqrt(" << i << ") = " << d << '\n';
    }
}

// Feladat #5

void ex05()
{
    cin.clear();
    cin.ignore(); // memória felszabadítás 
    cout << "\nEnter 10 floating point values: ";
    Matrix<double> m(10);
    double d;
    for (int i = 0; i < m.size(); ++i) {
        cin >> d;
        if (!cin) throw runtime_error("Problem reading from cin:");
        m[i] = d; // mátrix i-edik elemével egyenlítjük a megadott lebegőpontos értéket!
    }
    cout << "Matrix:\n" << m << '\n';
}

// Feladat #6 - Szorzótábla (2D mátrixként)

void ex06()
{
    cout << "\n Multiplication table \nEnter n: "; // szorzótábla!!
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;
    Matrix<int, 2> mtable(n, m);
    for (Index i = 0; i < mtable.dim1(); ++i) {
        for (Index j = 0; j < mtable.dim2(); ++j) {
            mtable(i, j) = (i + 1) * (j + 1);
            cout << setw(5) << mtable(i, j); // setw függvény miatt kell meghívnunk az iomanip-t!
        }
        cout << '\n';
    }
}

// 7. feladat

void ex07()
{
    Matrix<complex<double>> m(10);
    cout << "\nEnter 10 complex numbers (Re,Im): ";
    complex<double> c;
    for (int i = 0; i < 10; ++i) {
        cin >> c;
        if (!cin) throw runtime_error("Problem with reading complex number!");
        m[i] = c;
    }
    complex<double> sum;
    for (Index i = 0; i < m.size(); ++i)
        sum += m[i];
    cout << "Sum: " << sum << '\n';
}

// Feladat #8 - 6 integert kell beolvasni egy 2x3-mas mátrixba.

void ex08()
{
    Matrix<int, 2> m3 (2,3);
    cout << "Enter six numbers of integers: " << '\n';
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> m3(i,j);
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << m3(i,j) << '\t';
		}
		cout << endl;
	}
}

//------------------------------------------------------------------------------

int main()
try
{
    // Feladat #1 - Típusok memóriaméreteinek kiíratása.
    cout << "sizeof:\n";
    cout << "char\t" << sizeof(char) << '\n';
    cout << "short\t" << sizeof(short) << '\n';
    cout << "int\t" << sizeof(int) << '\n';
    cout << "long\t" << sizeof(long) << '\n';
    cout << "float\t" << sizeof(float) << '\n';
    cout << "double\t" << sizeof(double) << '\n';
    cout << "int*\t" << sizeof(int*) << '\n';
    cout << "double*\t" << sizeof(double*) << '\n';

    // Feladat #2 - Kiírjuk a mátrixok memóriaméreteit.
    cout << "\n Matrix sizes: \n";
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);
    cout << "1D int, 10 elements\t\t" << sizeof(a) << '\n';
    cout << "1D int, 100 elements\t\t" << sizeof(b) << '\n';
    cout << "1D double, 10 elements\t\t" << sizeof(c) << '\n';
    cout << "2D int, 10x10 elements\t\t" << sizeof(d) << '\n';
    cout << "3D int, 10x10x10 elements\t" << sizeof(e) << '\n';

    // Feladat #3 - A #2-es feladatban lévő mátrixok elemeit kiírjuk.
    cout << "\n Number of elements (same order): \n";
    cout << "a:\t" << a.size() << '\n';
    cout << "b:\t" << b.size() << '\n';
    cout << "c:\t" << c.size() << '\n';
    cout << "d:\t" << d.size() << '\n';
    cout << "e:\t" << e.size() << '\n';

    // Feladat #4: vegyen be inteket a cin-ből, és adjon ki sqrt-t mindegyikből, vagy "nincs négyzetgyök", ha ez illegális!
    ex04();

    // Feladat #5: olvassa be tíz lebegőpontos értéket a bemenetből, és helyezze el egy Mátrix<double>-ba; nyomtassa ki a mátrixot!
    ex05();

    // Feladat #6: számítson ki egy szorzótáblát [0,n)*[0,m-hez), ábrázolja 2D mátrixként. Vegyünk n-t és m-t cinből, és nyomtassuk ki szépen a táblázatot!
    ex06();

    // Feladat #7: olvass be tíz complex<double>-t a cinből, tedd be őket egy mátrixba, számítsd ki és add ki a tíz komplex szám összegét!
    ex07();

    // Feladat #8: olvass be hat int egy Mátrix<int,2> m(2,3)-ba és nyomtasd ki!
    ex08();
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "ERROR! Unknown exception!" << '\n';
}
