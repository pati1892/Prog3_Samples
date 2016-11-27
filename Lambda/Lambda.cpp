#include <iostream>

using namespace std;

using voidFnc = void(*)(void); // Prozedurzeigertyp

void SimpleLambda()
{
	auto fnc = []() { cout << "lambda\n"; }; // einfache Prozedur
	fnc();
	voidFnc vFnc = fnc; // lambda ist Funktionszeiger verträglich
	vFnc();
}

void FunctionLambda()
{
	auto rFnc1 = []() throw() ->int{ return 42; }; // einfache Funktion int(*)(void)
	int(*fnVoid)(void) = rFnc1;
	cout << rFnc1() << endl;
	cout << fnVoid() << endl;

	auto rFnc2 = [](int value) throw() ->int{return 2 * value; }; // einfache Funktion mit Parameter int(*)(int*)
	int(*fnInt)(int) = rFnc2;
	cout << rFnc2(21) << endl;
	cout << fnInt(21) << endl;
}

void ContextLambda() // Funktoren sind nicht mehr Funktionszeigerkompatibel
{
	int localData = 42;
	char* localText = "Hallo";
	auto rFnc1 = [=]() mutable ->int { // [=] Zugriff auf vollständigen lokalen Kontext mit call by Value
		cout << localText << " len =" << strlen(localText) << " localData = ";
		localData *= 2;
		return localData;
	};
	cout << rFnc1() << endl;
	cout << localData << endl; // localData ist nicht verändert

	auto rFnc2 = [localData]() { // [localData] call by Value Zugriff auf lokale Variable
		cout << "localData = " << localData;
	};
	rFnc2();
	cout << endl;

	auto rFnc3 = [&localData]() mutable { // [localData] call by Reference Zugriff auf lokale Variable
		localData *= 2;
	};
	rFnc3();
	cout << localData << endl; // localData ist verändert

	rFnc2(); // hat noch seinen alten Kontext
	cout << endl;

	rFnc3(); // hat einen neuen Kontext da Referenz verwndet wurde
	cout << localData << endl; // localData ist verändert
}

void C14Lambda()
{
	auto v1 = 1;
	auto v2 = 2.2;
	auto lambda = [](auto s1, auto s2) { return s1 + s2; };
	cout << v1 << " + " << v2 << " = " << lambda(v1, v2) << endl;
}

int main()
{
	SimpleLambda();
	FunctionLambda();
	ContextLambda();
	C14Lambda();
}