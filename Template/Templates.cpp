#include <iostream>

using namespace std;

#include "Maximum.h" // Funktionstemplate
#include "Vector.h" // Klassentemplate

void UseMaximum()
{
	auto max = maximum(1, 2); // automatische typisiert auf int
	cout << max << endl;
	auto dmax = maximum<double>(2, 1); // direkt typisiert auf double
	cout << dmax << endl;
	auto str = maximum("AAA", "BBB"); // spezialisiert auf const char*
	cout << str << endl;

	char *pa = "AAA", *pb = "BBB";
	str = maximum(pb, pa); // Achtung kein const char* und daher nicht spezialisiert
	cout << str << endl;
}

double Add100(const double& currentValue)
{
	return 100 + currentValue;
}

void Usevector()
{
	using fVector = Vector < double, 10 > ;

	fVector vec;
	for (size_t i = 0; i < 17; i++)
		vec.pushBack(i + 1 / 10.0);
	cout << vec << endl; // benutze überladenen Out Stream Operator

	fVector copy = vec; // Kopier Konstruktor
	copy[0] = copy[16]; // Indexoperator
	cout << copy << endl;

	copy = vec; // Zuweisungsoperator
	cout << copy << endl;

	//Änderung der Daten
	copy(Add100);
	cout << copy << endl;
}

int main()
{
	UseMaximum();
	Usevector();
}