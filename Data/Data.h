#ifndef DATA_H
#define DATA_H // include header nur einmal

#pragma once // include header nur einmal von MS

#define MaxTextSize 20

struct SomeDataInStruct	 // alle Felder vorhanden und belegen Speicher
{
	float fValue;
	int iValue;
	char Text[MaxTextSize];
};

union SomeDataInUnion	// alle Felder belegen einen gemeinsamen Speicherplatz
{
	float fValue;
	int iValue;
	char Text[MaxTextSize];
};

struct ABitfield	// optimierte Bitablage im Speicher
{
	unsigned int Day : 5;		// 1..31 == 2^5 -> [0..31]
	unsigned int Month : 4;		// 1..12 == 2^4 -> [0..15]
	unsigned int Year : 12;		// 1..4095 = 2^12 -> [0..4095]
};

enum class DayOfWeek // eine Aufzählung
{
	Sunday = 0,
	Monday,
	Tueseday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,

};

#endif // DATA_H