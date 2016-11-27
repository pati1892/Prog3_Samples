#include <iostream>
#include "../StaticLib/StaticLib.h"

using namespace std;

class StaticLibEx : public CStaticLib // Ableitung von lib Klasse
{
};

int main()
{
	StaticLibEx ex;
	CStaticLib &rEx = ex; // Polymorphie mit lib

	cout << "rEx.getValue() = " << rEx.getValue() << endl;
	cout << "fnStaticLib() = " << fnStaticLib() << endl; // Funktion aus lib
	cout << "nStaticLib = " << nStaticLib << endl; // globaler Wert aus lib
}