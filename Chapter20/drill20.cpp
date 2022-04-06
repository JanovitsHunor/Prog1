#include "std_lib_facilities.h"
#include <iterator>

template<typename Iter1, typename Iter2>
Iter2 IterCopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

int main()
{
	// intek tömbje
	int intArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// intek vektora
	vector<int> intVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// intek listája
	list<int> intList{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// másolatok
	int intArray2[10];
	copy(begin(intArray), end(intArray), begin(intArray2));

	vector<int> intVector2 = intVector;

	list<int> intList2 = intList;

	// értékek növelése
	for (int& i : intArray)
		i += 2;

	for (int& i : intVector)
		i += 3;

	for (int& i : intList)
		i += 5;

	// IterCopy operáció tesztelése
	IterCopy(intArray.begin(), intArray.end(), intVector2.begin());
	if (intArray[0] != intVector2[0])
		cout << "Error: intArray[0] && intVector2[0] are not the same!" << endl;

	IterCopy(intList.begin(), intList.end(), intArray2.begin());
	if (*(intList.begin()) != intArray2[0])
		cout << "Error: intList[0] && intArray2[0] are not the same!" << endl;

	// a 3 megtalálása a vektorban
	auto vecResult = find(begin(intVector), end(intVector), 3);
	if (vecResult != end(intVector))
		cout << "intVector contains 3 at position " << distance(intVector.begin(), vecResult) << endl;
	else
		cout << "intVector does not contain 3" << endl;
	intVector.push_back(3);

	// a 27-es megtalálása a listában
	auto listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult contains 27 at position " << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult does not contain 27" << endl;

	intList.push_back(27);
	listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult contains 27 at position " << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult does not contain 27" << endl;

	keep_window_open();
	return 0;
}