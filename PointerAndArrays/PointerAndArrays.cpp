#include <iostream>

using namespace std;

void Pointer()
{
	double Value = 12;
	double* pValue = &Value;
	double* pOther{ nullptr };

	cout << "sizeof(pValue) = " << sizeof(pValue) << endl;
	cout << "sizeof(pOther) = " << sizeof(pOther) << endl;
	cout << "pOther = " << pOther << endl;

	cout << "Value = " << Value << endl;
	cout << "pValue = " << pValue << endl;

	*pValue = 30;
	cout << "Value = " << Value << endl;
	cout << "pValue = " << *pValue << endl;
}

void PointerAndArray()
{
	int Array[10];
	int* pArray = Array;

	cout << "Array = " << Array << endl;
	cout << "pArray = " << pArray << endl;

	auto size = sizeof(Array) / sizeof(Array[0]);
	for (size_t i = 0; i < size; i++)
	{
		pArray[i] = i + 1;
		*(Array + i) = i + 1;
	}

	int TwoDim[10][10];
	int* pTwoDim = reinterpret_cast<int*>(TwoDim); // bad guy!!
	void* pVoid = TwoDim; // ohne Typ
	auto* pAuto = TwoDim; // int[10]* Typ

	cout << "TwoDim = " << TwoDim << endl;
	cout << "TwoDim[0] = " << TwoDim[0] << endl;
	cout << "pTwoDim = " << pTwoDim << endl;
	cout << "pVoid = " << pVoid << endl;
	cout << "pAuto = " << pAuto << endl;

	pTwoDim = TwoDim[0];
}

void PointerMath()
{
	int Array[] = {20, 40, 60, 80};
	int* pItem(Array);
	auto size = sizeof(Array) / sizeof(Array[0]);

	if (pItem == Array) // Vergleich 
		cout << "pItem equal Array" << endl;

	for (size_t i = 0; i < size; ++i)
	{
		cout << "Array[" << i << "]=" << Array[i] << endl;
		cout << "pItem = " << pItem << " *pItem = " << *pItem << endl;
		++pItem; // Addition
	}

	cout << "Diff = " << pItem - Array << endl; // Differenz von zwei Zeigern

	pItem -= size; // Subtraktion
	cout << "pItem = " << pItem << " *pItem = " << *pItem << endl;
}

int main()
{
	Pointer();
	PointerAndArray();
	PointerMath();
}