#include <iostream>

using namespace std;

void Sequence()
{
	auto a = 42 + 42;	// Anweisung
	{ // Anweisungsblock
		auto b = a * 2;
		a = b / 2;
	} // ab hier gibt es b nicht mehr
	cout << "a = " << a << endl;
}

void IfAlternative()
{
	auto a = 0;
	if (0 == a) // linke Seite Konstante; Zuweisung ausschließen
		cout << "a == 0\n";
	else if (1 == a) 
		cout << "a == 1\n";
	else
		cout << "a !=1 && a != 0\n";
}

void Conditional()
{
	auto a(5), b(12);
	cout << "max = " << ((a > b) ? a : b) << endl;
}

void SwitchAlernative()
{
	auto a = 1;
	switch (a)
	{
	case 0:
		cout << "a == 0\n";
		break;
	case 1:
		cout << "a == 1\n";
		break;
	default:
		cout << "a !=1 && a != 0\n";
		break;
	}
}

void Iteration()
{
	auto start = 10;
	while (start > 0) // laufe bis start gleich 0
	{
		--start;
		cout << ".";
	}
	cout << "start = " << start << endl;

	bool end = false;
	do
	{
		end = ++start >= 10; // end wird true wenn start >= 10 ist
		cout << ".";
	} while (!end); // laufe bis end == true
	cout << "start = " << start << endl;

	for (int i = 0; i < 10; ++i) // laufe bis i >= 10 ist
	{
		--start;
		cout << ".";
	}
	cout << "start = " << start << endl;
}

void IterationContinueBreak()
{
	for (int i = 0; i < 10; ++i)
	{
		if (0 == (i % 2))
			continue; // gerade Werte überspringen
		cout << "i = " << i << endl;
		if (7 == i)
			break; // bei 7 raus aus der Schleife
	}
}

void GotoLabel()
{
	auto a = 100;

	if (a > 50) 
		goto High; // springe nach Label High

	return;

High:
	cout << "a > 50\n";
}

void Procedure(int Value1, int Value2, int Value3 = 0) // Prozedur mit Standardparameter
{
	cout << "Sum = " << Value1 + Value2 + Value3 << endl;
}

void Procedure(double v1, int v2, int v3 = 0) // überladene Prozedur
{
	cout << "Sum = " << v1 + v2 + v3 << endl;
}

int Function(int Value1, int Value2, int Value3 = 0) // Funktion mit Standardparameter
{
	return Value1 + Value2 + Value3;
}

void Exception(int Value)
{
	try
	{
		if (Value == 0)
			throw -1; // einfacher Datentyp
		cout << "div = " << 12 / Value << endl;
	}
	catch (int ex) 
	{
		cout << "Divison by Zero not alowed = " << ex << endl;
	}
	catch (...)
	{
		cout << "any Exception\n";
	}
}

int main() // main ist eine Funktion mit int Rückgabe
{
	Sequence();
	IfAlternative();
	Conditional();
	SwitchAlernative();
	Iteration();
	IterationContinueBreak();
	GotoLabel();

	Procedure(1, 2);
	Procedure(1, 2, 3);

	Procedure(1.2, 2);

	cout << "FSum = " << Function(1, 2) << endl;
	cout << "FSum = " << Function(1, 2, 3) << endl;

	Exception(0);
}