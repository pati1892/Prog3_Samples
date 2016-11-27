#include <iostream>
#include <iomanip> // stream Formatierer

using namespace std;

int main()
{
	auto sum = 10 + 12 * 2; // sum wird als int erkannt
	cout << "sum = " << sum << endl;
	sum = (10 + 12) * 2;
	cout << "sum = " << sum << endl;

	auto inc = 5;
	inc %= 3;
	cout << "inc mod 3 = " << inc << endl;

	inc = 1;
	cout << "inc   = " << inc << endl;
	cout << "++inc = " << ++inc << endl;
	cout << "inc++ = " << inc++ << endl;
	cout << "inc   = " << inc << endl;

	auto bits = 0x01u; // bits wird als unsigned int erkannt
	cout << "bits = " << setbase(16) << bits << endl; 
	
	bits <<= 1; // shift left 1 = bits * 2
	cout << "bits = " << bits << endl;
	
	cout << "NOT bits = " << ~bits << endl;
	bits = bits ^ bits;
	cout << "XOR bits = " << bits << endl;
}