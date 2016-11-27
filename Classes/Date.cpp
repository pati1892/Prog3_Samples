#include <iostream>
#include <exception> // Standard für alle C++ Exceptions
#include <cstdlib>

#include "Date.h"

using namespace std;

// Definition der Methoden

char* Date::ClassName = "class Date"; // definition des statischen Elements

Date::Date() : DayOfMonth(0), MonthOfYear(0), Year(0)
{
	cout << "ctor Date()" << endl;
}

Date::Date(int Day, int Month, int Year) : Date() // Konstruktor Weiterleitung
{
	cout << "ctor Date(Day, Month, Year)" << endl;
	setDay(Day);
	setMonth(Month);
	setYear(Year);
}

Date::Date(const Date& Src) : Date(Src.DayOfMonth, Src.MonthOfYear, Src.Year)
{
	cout << "ctor Date(const Date& Src)" << endl;
}

Date::~Date()
{
	cout << "dtor ~Date()" << endl;
}

// nur zur Vollständigkeit, nicht von Vorteil
Date& Date::operator=(const Date& Src)
{
	cout << "operator=(const Date& Src)" << endl;

	if (this == &Src)
		return *this;

	DayOfMonth  = Src.DayOfMonth;
	MonthOfYear = Src.MonthOfYear;
	Year = Src.Year;

	return *this;
}

Date::Date(Date& rVal) 
{
	cout << "ctor Date(Date& rVal)" << endl;
	*this = std::move(rVal); // rufe Move Zuweisung
}

Date& Date::operator=(Date& rVal)
{
	cout << "operator=(Date& rVal)" << endl;
	if (this == &rVal)
		return *this;

	// nichts für move, keine dynamischen Teile die gestohlen werden könnten
	DayOfMonth = rVal.DayOfMonth;
	MonthOfYear = rVal.MonthOfYear;
	Year = rVal.Year;

	return *this;
}

void Date::setDay(const int day)
{
	if (day < DayMin || day > DayMax)
		throw exception("day out of range");
	DayOfMonth = static_cast<word>(day);
}

void Date::setDay(const char* day)
{
	auto iday = atoi(day); // runtime library ascii to integer
	setDay(iday);
}

void Date::setMonth(const int month)
{
	if (month < MonthMin || month > MonthMax)
		throw exception("month out of range");
	MonthOfYear = static_cast<word>(month);
}

void Date::setYear(const int Year)
{
	if (Year < YearMin || Year > YearMax)
		throw exception("year out of range");
	this->Year = static_cast<word>(Year); // Zugriff mit this und Strukturoperator
}

bool Date::TestEmpty(const Date& Src)
{
	return Src.IsEmpty(); // Zugriff mit Punktoperator
}
