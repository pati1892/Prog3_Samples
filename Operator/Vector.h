#pragma once
#include <iostream>

using Function = int(*)(const int); // Funktionszeiger

class Vector
{
public:
	Vector();
	Vector(const Vector& Src); // Klasse hat dynamischen Anteil daher ist der Kopierkonstruktor n�tig
	~Vector();

	Vector& operator=(const Vector& Src); // lokaler Zuweisungsoperator; Klasse hat dynmischen Anteil daher ist der Zuweisungsoperator n�tig

	// moves!!, richtig und gut
	Vector(Vector& rVal);
	Vector& operator=(Vector& rVal);

	int& operator[](size_t Index); // Indexoperator
	void operator()(Function Fnc); // Funktionsoperator

	int getSize() const { return bufferSize; }
	int getFill() const { return bufferFill; }

	void pushBack(const int dataItem); // Wert am Ende einf�gen

protected:
	static size_t enlargeSize;

private:
	size_t bufferSize;	// Gr��e des Puffers
	size_t bufferFill; // gef�llte L�nge des Puffers
	int* dataBuffer; // Zeiger auf Feld f�r Werte

	void EnlargeBuffer(); // Puffer f�r neue Werte vergr��ern
	static void CopyBufferData(int *targetBuffer, int const* sourceBuffer, size_t len); // Werte im Puffer kopieren

	friend std::ostream& operator<<(std::ostream& out, const Vector& data); // operator ist Freund
};

std::ostream& operator<<(std::ostream& out, const Vector& data); // globaler �berladener Operator f�r streaming

