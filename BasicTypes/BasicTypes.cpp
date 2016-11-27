#include <iostream>
#include <climits> // Zeichen und ganzen Zahlen Wertebereich
#include <cfloat> // Gleitkommazahlen Wertebereich
#include <limits> // Templates für Wertebereiche

using namespace std;

int main()
{
	// classic init
	bool logVal = true;
	char cA = 'a';		
	short sVal = 99;
	int iVal = 100;		
	long lVal = 101;	
	long long llVal = 102;
	float fValue = 103; 
	double dValue = 104;

	double dValue2(42);

	// C11 init
	bool logFalse{ false };
	char cB{ 'b' };

	cout << logVal << endl
		<< cA << endl
		<< sVal << endl
		<< iVal << endl
		<< lVal << endl
		<< llVal << endl
		<< fValue << endl
		<< dValue << endl
		<< dValue2 << endl
		<< logFalse << endl
		<< cB << endl;

	wchar_t wcA = 'A';
	// C11 char types, minimal support
	char16_t c16A = 'A';
	char32_t c32A = 'A';

	cout << wcA << endl // stream gibt ganze Zahlen aus
		<< c16A << endl
		<< c32A << endl;

	wcout << wcA << endl // wchar_t stream
		<< c16A << endl
		<< c32A << endl;

	// climits und cfloat
	cout << "bool = [" << true << "," << false << "]\n";
	cout << "char = [" << SCHAR_MIN << "," << SCHAR_MAX << "]\n";
	cout << "short = [" << SHRT_MIN << "," << SHRT_MAX << "]\n";
	cout << "int = [" << INT_MIN << "," << INT_MAX << "]\n";
	cout << "long = [" << LONG_MIN << "," << LONG_MAX << "]\n";
	cout << "long long = [" << LLONG_MIN << "," << LLONG_MAX << "]\n";
	cout << "float = [" << FLT_MIN << "," << FLT_MAX << "]\n";
	cout << "double = [" << DBL_MIN << "," << DBL_MAX << "]\n";

	// limits 
	cout << "int = [" << numeric_limits<int>::min() << "," << numeric_limits<int>::max() << "]\n";
	cout << "int precision digits = " << numeric_limits<int>::digits << "\n";
	cout << "int signed = " << numeric_limits<int>::is_signed << "\n";
}