#include <iostream>

using namespace std;

int main()
{
	cout << "bool       = " << sizeof(bool) << " bytes \n";
	cout << "char       = " << sizeof(char) << " bytes \n";
	cout << "short      = " << sizeof(short) << " bytes \n";
	cout << "int        = " << sizeof(int) << " bytes \n";
	cout << "long       = " << sizeof(long) << " bytes \n";
	cout << "long long  = " << sizeof(long long) << " bytes \n";
	cout << "float      = " << sizeof(float) << " bytes \n";
	cout << "double     = " << sizeof(double) << " bytes \n";

	double dValue = 42;
	cout << "dValue     = " << sizeof(dValue) << " bytes \n";
}