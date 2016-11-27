#pragma once
#include <iostream>

#include <chrono>

template<class T>
using Function = T(*)(const T&); // Funktionszeiger

template<class T, int enlargeSize = 4>
class Vector
{
public:

	Vector();
	Vector(const Vector& Src); // Klasse hat dynamischen Anteil daher ist der Kopierkonstruktor nötig
	~Vector();

	Vector& operator=(const Vector& Src); // lokaler Zuweisungsoperator; Klasse hat dynmischen Anteil daher ist der Zuweisungsoperator nötig

	Vector(Vector& rVal) { *this = std::move(rVal);	}
	Vector& operator=(Vector& rVal)
	{
		if (this == &rVal)
			return *this;
		delete[] dataBuffer;
		dataBuffer = rVal.dataBuffer;
		bufferSize = rVal.bufferSize;
		bufferFill = rVal.bufferFill;
		rVal.dataBuffer = nullptr;
		rVal.bufferSize = rVal.bufferFill = 0;
	}

	T& operator[](size_t Index); // Indexoperator
	void operator()(Function<T> Fnc); // Funktionsoperator

	int getSize() const { return bufferSize; }
	int getFill() const { return bufferFill; }

	void pushBack(const T& dataItem); // Wert am Ende einfügen

protected:

private:
	size_t bufferSize;	// Größe des Puffers
	size_t bufferFill; // gefüllte Länge des Puffers
	T* dataBuffer; // Zeiger auf Feld für Werte

	void EnlargeBuffer(); // Puffer für neue Werte vergrößern
	static void CopyBufferData(T *targetBuffer, T const* sourceBuffer, size_t len); // Werte im Puffer kopieren

	template<class T, int enlargeSize>
	friend std::ostream& operator<<(std::ostream& out, const Vector<T, enlargeSize>& data); // operator ist Freund
};


template<class T, int enlargeSize>
Vector<T, enlargeSize>::Vector() : bufferFill(0), bufferSize(0), dataBuffer(nullptr)
{
}

template<class T, int enlargeSize>
Vector<T, enlargeSize>::Vector(const Vector<T, enlargeSize>& Src) : Vector<T, enlargeSize>() // Kopie erzeugen
{
	dataBuffer = new T[Src.bufferSize]; // new operator auf Typ
	CopyBufferData(dataBuffer, Src.dataBuffer, Src.bufferFill);
	bufferFill = Src.bufferFill;
	bufferSize = Src.bufferSize;
}

template<class T, int enlargeSize>
Vector<T, enlargeSize>::~Vector()
{
	delete[] dataBuffer; // Array delete; delete operator auf Typ
	dataBuffer = nullptr;

	bufferSize = bufferFill = 0;
}

template<class T, int enlargeSize>
void Vector<T, enlargeSize>::pushBack(const T& dataItem)
{
	if (bufferSize <= bufferFill)
		EnlargeBuffer();
	dataBuffer[bufferFill++] = dataItem; // Zuweisungsoperator!!
}

template<class T, int enlargeSize>
void Vector<T, enlargeSize>::EnlargeBuffer()
{
	auto newBuffer = new T[bufferSize + enlargeSize]; // new operator auf Typ
	CopyBufferData(newBuffer, dataBuffer, bufferSize);

	delete[] dataBuffer; // Array delete
	dataBuffer = newBuffer;

	bufferSize += enlargeSize;
}

template<class T, int enlargeSize>
void Vector<T, enlargeSize>::CopyBufferData(T *targetBuffer, T const* sourceBuffer, const size_t len)
{
	for (size_t i = 0; i < len; i++)
		targetBuffer[i] = sourceBuffer[i]; // Zuweisungsoperator!!
}

template<class T, int enlargeSize>
Vector<T, enlargeSize>& Vector<T, enlargeSize>::operator=(const Vector<T, enlargeSize>& Src)
{
	if (this == &Src) // Eigenzuweisung
		return *this;

	auto newBuffer = new T[Src.bufferSize]; // new operator auf Typ
	CopyBufferData(newBuffer, Src.dataBuffer, Src.bufferFill);
	bufferFill = Src.bufferFill;
	bufferSize = Src.bufferSize;

	delete[] dataBuffer; // Array delete
	dataBuffer = newBuffer;

	return *this;
}

template<class T, int enlargeSize>
T& Vector<T, enlargeSize>::operator[](size_t Index)
{
	if (Index >= bufferFill)
		throw std::exception("index out of range");
	return dataBuffer[Index];
}

template<class T, int enlargeSize>
void Vector<T, enlargeSize>::operator()(Function<T>	Fnc)
{
	for (size_t i = 0; i < bufferFill; i++)
		dataBuffer[i] = Fnc(dataBuffer[i]); // Änderung der Daten mit Funktion
}

template<class T, int enlargeSize>
std::ostream& operator<<(std::ostream& out, const Vector<T, enlargeSize>& data)
{
	char sep = '\n';
	out << "*** Vector ***" << sep;
	out << "Size = " << data.bufferSize << sep;
	out << "Fill = " << data.bufferFill << sep;
	for (size_t i = 0; i < data.bufferFill; i++)
		out << "[" << i << "] = " << data.dataBuffer[i] << sep;
	return out;
}
