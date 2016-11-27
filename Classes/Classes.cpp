#include <iostream>
#include "Date.h"

using namespace std;


void CallByValue(Date date)
{
	cout << "Year = " << date.getYear() << endl;
} // Destruktion

void CallByRef(const Date& date)
{
	cout << "Year = " << date.getYear() << endl;
}

void fullAccess(Date& Src)
{
	cout << Src.DayOfMonth << endl;
}

int main()
{
	Date date(1, 1, 2014);		// Konstruktor
	auto day = date.getDay();	// Instanzenmethode
	cout << "day = " << day << endl;
	date.setDay(31);
	cout << "day = " << date.getDay() << endl;

	char* nextDay = "12";
	date.setDay(nextDay);

	if (!Date::TestEmpty(date)) // statische Methode
		cout << "date is not empty" << endl;
	cout << "Class Name = " << Date::getClassName() << endl;

	CallByValue(date); // Konstruktion
	CallByRef(date);

	fullAccess(date);

	cout << "last line of code" << endl;
} // Destruktor