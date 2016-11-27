#include <iostream>
#include <iomanip>
#include <cstring>

#include "Data.h"	// füge die Deklarationen ein


using namespace std;

bool TrueOnMultiple10(int i)
{
	return 0 == ((i + 1) % 10);
}

typedef unsigned char byte;
using word = unsigned short;

void DumpBytes(void* pData, size_t len)
{
	auto pByte = reinterpret_cast<byte*>(pData);
	auto orgFlags = cout.flags();
	for (size_t i = 0; i < len; i++)
	{
		cout << setw(2) << setbase(16) << setfill('0') << static_cast<word>(*(pByte + i)) << " ";
		if (TrueOnMultiple10(i))
			cout << endl;
	}
	cout << endl;
	cout.flags(orgFlags);
}

void StructHandling()
{
	SomeDataInStruct data = {1.2f, 42, "Mein Text"}; // Definition und Initialisierung
	cout << "data.fValue = " << data.fValue << endl; // Zugriff auf Strukturelemente mit Punktoperator
	cout << "data.iValue = " << data.iValue << endl;
	cout << "data.Text = " << data.Text << endl;
	cout << "sizeof(data) = " << sizeof(data) << endl;

	auto pData = &data; // Zeiger auf Data mit Addressoperator
	pData->fValue = 2.4f; // Strukturoperator setzt fValue auf 2.4

	SomeDataInStruct& rData = data; // Referenz auf Data
	rData.fValue = 4.8f; // Referenz arbeitet mit Punktoperator

	DumpBytes(&data, sizeof(data));
	auto copyData = data; // Zuweisung
	DumpBytes(&copyData, sizeof(copyData));
}

void UnionHandling()
{
	SomeDataInUnion data = { 1.2f }; // nur das 1. Element
	cout << "data.fValue = " << data.fValue << endl; // Zugriff auf Strukturelemente mit Punktoperator
	cout << "data.iValue = " << data.iValue << endl;
	cout << "data.Text = " << data.Text << endl;
	cout << "sizeof(data) = " << sizeof(data) << endl;

	auto pData = &data; // Zeiger auf Data mit Addressoperator
	pData->fValue = 2.4f; // Strukturoperator setzt fValue auf 2.4

	auto& rData = data; // Referenz auf Data
	rData.fValue = 4.8f; // Referenz arbeitet mit Punktoperator

	DumpBytes(&data, sizeof(data));
	auto copyData = data;
	DumpBytes(&copyData, sizeof(copyData));
}

void BitfieldHandling()
{
	const char sep = '.';
	ABitfield data = { 1, 2, 2002 };
	auto orgFlags = cout.flags();
	cout << setfill('0') << setw(2) << data.Day << sep
		<< setw(2) << data.Month << sep
		<< setw(4) << data.Year << endl;
	cout.flags(orgFlags);

	cout << "sizeof(data) = " << sizeof(data) << endl;
	DumpBytes(&data, sizeof(data));
	auto copyData = data;
	DumpBytes(&copyData, sizeof(copyData));
}

void EnumHandling()
{
	DayOfWeek sunday = DayOfWeek::Sunday;
	DayOfWeek saturday = DayOfWeek::Saturday;

	cout << "sunday = " << static_cast<int>(sunday) << endl;
	cout << "saturday = " << static_cast<int>(saturday) << endl;
}

void main()
{
	StructHandling();
	UnionHandling();
	BitfieldHandling();
	EnumHandling();
}