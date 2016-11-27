#include <iostream>
#include "../DynamicLib/DynamicLib.h"

using namespace std;

class DynamicLibEx : public CDynamicLib // Ableitung von dll Klasse
{
};

int main()
{
	DynamicLibEx ex;
	CDynamicLib &rEx = ex; // polymorphie zu dll Klasse

	cout << "rEx.getValue() = " << rEx.getValue() << endl;
	cout << "fnDynamicLib() = " << fnDynamicLib() << endl; // Funktion aus dll
	cout << "nDynamicLib = " << nDynamicLib << endl; // globaler Wert aus dll
}