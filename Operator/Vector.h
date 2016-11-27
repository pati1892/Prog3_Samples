#pragma once
#include <iostream>

using Function = int(*)(const int); // Funktionszeiger

class Vector
{
public:
	Vector();
	Vector(const Vector& Src); // Klasse hat dynamischen Anteil daher ist der Kopierkonstruktor nötig
	~Vector();

	Vector& operator=(const Vector& Src); // lokaler Zuweisungsoperator; Klasse hat dynmischen Anteil daher ist der Zuweisungsoperator nötig

	// moves!!, richtig und gut
	Vector(Vector& rVal);
	Vector& operator=(Vector& rVal);

	int& operator[](size_t Index); // Indexoperator
	void operator()(Function Fnc); // Funktionsoperator

	int getSize() const { return bufferSize; }
	int getFill() const { return bufferFill; }

	void pushBack(const int dataItem); // Wert am Ende einfügen

protected:
	static size_t enlargeSize;

private:
	size_t bufferSize;	// Größe des Puffers
	size_t bufferFill; // gefüllte Länge des Puffers
	int* dataBuffer; // Zeiger auf Feld für Werte

	void EnlargeBuffer(); // Puffer für neue Werte vergrößern
	static void CopyBufferData(int *targetBuffer, int const* sourceBuffer, size_t len); // Werte im Puffer kopieren

	friend std::ostream& operator<<(std::ostream& out, const Vector& data); // operator ist Freund
};

std::ostream& operator<<(std::ostream& out, const Vector& data); // globaler überladener Operator für streaming

