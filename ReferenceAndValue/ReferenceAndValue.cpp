#include <iostream>

using namespace std;

void CallByValue(double Value) // Kopie wird verwendet call by Value
{
	cout << "Value = " << Value << endl;
	Value = 4;
	cout << "Value = " << Value << endl;
}

void CallByReferencePtr(double* pValue) // braucht Addressoperatoren
{
	cout << "Value = " << *pValue << endl; 
	*pValue = 4; // Verweisoperator
	cout << "Value = " << *pValue << endl;
}

void CallByReference(double& Value) // braucht keine Adressoperatoren
{
	cout << "Value = " << Value << endl;
	Value = 4;
	cout << "Value = " << Value << endl;
}

void CallByRefPtrIN(double const* pValue)
{
	cout << "Value = " << *pValue << endl;
	//*pValue = 4; // geht nicht da der Wert konstant ist
}

void CallByRefIN(const double& Value)
{
	cout << "Value = " << Value << endl;
	//Value = 4; // geht nicht da der Wert konstant ist
}

int main()
{
	double Value = 2;
	CallByValue(Value);
	cout << "Value = " << Value << endl;

	Value = 2;
	CallByReferencePtr(&Value); // Adressoperator
	cout << "Value = " << Value << endl;

	Value = 2;
	CallByReference(Value);
	cout << "Value = " << Value << endl;
}