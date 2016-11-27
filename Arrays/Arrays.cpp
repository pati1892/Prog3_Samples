#include <iostream>

using namespace std;

int SumArray()
{
	const int MaxValues = 99;
	int LittleGaus[MaxValues]; // ein eindimensionales Integerfeld mit 99 Werten

	for (int i = 0; i < MaxValues; ++i)
		LittleGaus[i] = i + 1; // Werte für Feld 1..99

	register int Sum = 0;
	for (int i = 0; i < MaxValues; i++)
		Sum += LittleGaus[i];

	return Sum;
}

void ShowValues(int Array[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << Array[i];
		if (i < (len - 1))
			cout << ", ";
	}
	cout << endl;
}

void SomeArrays()
{
	int Single[100];	// ein Feld mit 100 Werten
	int TwoDim[10][10]; // ein 2d Feld mit 100 Werten
	int ThreeDim[10][2][5]; // ein 3d Feld mit 100 Werten

	// Größe in Bytes
	cout << "Single sizeof() = " << sizeof(Single) << endl;
	cout << "TwoDim sizeof() = " << sizeof(TwoDim) << endl;
	cout << "ThreeDim sizeof() = " << sizeof(ThreeDim) << endl;

	// gesamte Elementeanzahl
	cout << "Single Items = " << sizeof(Single) / sizeof(Single[0]) << endl;
	ShowValues(Single, 100); // nicht initialisiert

	cout << "TwoDim Items = " << sizeof(TwoDim) / sizeof(TwoDim[0][0]) << endl;
	TwoDim[0][0] = 0;
	cout << "ThreeDim Items = " << sizeof(ThreeDim) / sizeof(ThreeDim[0][0][0]) << endl;

	// Iteration eines Feldes mit Schleifen
	int value = 0;
	for (int dim1 = 0; dim1 < 10; ++dim1)
	{
		for (int dim2 = 0; dim2 < 2; dim2++)
		{
			for (int dim3 = 0; dim3 < 5; dim3++)
				ThreeDim[dim1][dim2][dim3] = ++value;
		}
	}
}

void InitArrays()
{
	int Array[5] = { 1, 2, 3, 4, 5 }; // alle initialisiert
	int OtherArray[] = { 1, 2, 3 }; // alle initialisiert
	int MoreArray[10] = { 1, 2, 3 }; // nur der Anfang initialisiert, der Rest ist default 0 Wert

	auto size = sizeof(Array) / sizeof(Array[0]);
	cout << "Array Items = " << size << endl;
	ShowValues(Array, size);

	size = sizeof(OtherArray) / sizeof(OtherArray[0]);
	cout << "OtherArray Items = " << size << endl;
	ShowValues(OtherArray, size);

	size = sizeof(MoreArray) / sizeof(MoreArray[0]);
	cout << "MoreArray Items = " << size << endl;
	ShowValues(MoreArray, size);
}

int main()
{
	cout << "SumArray = " << SumArray() << endl;
	SomeArrays();
	InitArrays();
}