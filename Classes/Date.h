#pragma once

using word = unsigned short;

const int DayMin = 1;
const int DayMax = 31;
const int MonthMin = 1;
const int MonthMax = 12;
const int YearMin = 1582;
const int YearMax = 9999;

class Date;
void fullAccess(Date& Src);

// Deklaration der Klasse
class Date
{
public:
	// Konstruktion
	Date();
	Date(int Day, int Month, int Year);
	Date(const Date& Src);
	// Destruktion
	~Date();
	// Zuweisung
	Date& operator=(const Date& Src);

	// Move Erweiterungen
	Date(Date& rVal);
	Date& operator=(Date& rVal);

	// Instanzen Methoden
	int getDay() const { return DayOfMonth; } // inline Methode
	void setDay(const int day);
	void setDay(const char* day); // Überladung
	int getMonth() const { return MonthOfYear; }
	void setMonth(const int month);
	int getYear() const { return Year; }
	void setYear(const int Year);
	bool IsEmpty() const { return 0 == DayOfMonth && 0 == MonthOfYear && 0 == Year; }

	// statische Methoden
	static bool TestEmpty (const Date& Src);
	static const char* getClassName() { return ClassName; }

protected:
	// statisches Feld
	static char* ClassName; 

private:
	// Instanzen Felder
	word DayOfMonth;
	word MonthOfYear;
	word Year;

	friend void fullAccess(Date& Src); // Freund der Klasse
};

