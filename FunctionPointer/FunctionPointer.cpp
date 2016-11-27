#include <iostream>

using namespace std;

typedef int(*pFnc)(int, int); // Funktionszeigertyp pFnc
using pAFnc = int (*)(int, int); // Alias Template pAFnc

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int main()
{
	int(*pAdd)(int, int) = Add; // Funktionszeiger Instanz pAdd
	cout << "Sum = " << pAdd(1, 2) << endl;

	pAFnc pSub = Sub;
	cout << "Sub = " << pSub(1, 2) << endl;

	pFnc Lib[] { Add, Sub }; // Feld von Funktionszeigern
	auto size = sizeof(Lib) / sizeof(Lib[0]);
	for (size_t i = 0; i < size; i++)
		cout << "Result = " << Lib[i](1, 2) << endl;

}