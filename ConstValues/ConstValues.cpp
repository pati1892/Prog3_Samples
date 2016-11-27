#include <iostream>

using namespace std;

int main()
{
	const char CR = '\n';
	const double pi = 3.141592;
	const auto e = 2.71828;

	cout << "pi = " << pi << CR;
	cout << "e  = " << e << CR;
	// Compiler Fehler
	//pi = 3;
}