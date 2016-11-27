#include <iostream>
#include <cassert>

using namespace std;

#include "Vector.h"

void CheckMemory()
{
	assert(_CrtCheckMemory());
	assert(!_CrtDumpMemoryLeaks());
}

void PressEnterToExit()
{
	cout << "press enter to exit ";
	char buffer[1];
	cin.getline(buffer, 1);
}

int Add100(const int currentValue)
{
	return 100 + currentValue;
}

void Usevector()
{
	Vector vec;
	for (size_t i = 0; i < 17; i++)
		vec.pushBack(i + 1);
	cout << vec << endl; // benutze überladenen Out Stream Operator

	Vector copy = vec; // Kopier Konstruktor
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
	Usevector();

	CheckMemory();
	PressEnterToExit();
}