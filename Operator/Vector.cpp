#include "Vector.h"

size_t Vector::enlargeSize = 4;

Vector::Vector() : bufferFill(0), bufferSize(0), dataBuffer(nullptr)
{
}

Vector::Vector(const Vector& Src) : Vector() // Kopie erzeugen
{
	dataBuffer = new int[Src.bufferSize];
	CopyBufferData(dataBuffer, Src.dataBuffer, Src.bufferFill);
	bufferFill = Src.bufferFill;
	bufferSize = Src.bufferSize;
}

Vector::~Vector()
{
	delete[] dataBuffer; // Array delete
	dataBuffer = nullptr;

	bufferSize = bufferFill = 0;
}

Vector::Vector(Vector& rVal)
{
	*this = std::move(rVal);
}

void Vector::pushBack(const int dataItem)
{
	if (bufferSize <= bufferFill)
		EnlargeBuffer();
	dataBuffer[bufferFill++] = dataItem; // Zuweisungsoperator!!
}

void Vector::EnlargeBuffer()
{
	auto newBuffer = new int[bufferSize + enlargeSize];
	CopyBufferData(newBuffer, dataBuffer, bufferSize);

	delete[] dataBuffer; // Array delete
	dataBuffer = newBuffer;

	bufferSize += enlargeSize;
}

void Vector::CopyBufferData(int *targetBuffer, int const* sourceBuffer, const size_t len)
{
	for (size_t i = 0; i < len; i++)
		targetBuffer[i] = sourceBuffer[i]; // Zuweisungsoperator!!
}

Vector& Vector::operator=(const Vector& Src)
{
	if (this == &Src) // Eigenzuweisung
		return *this;

	auto newBuffer = new int[Src.bufferSize];
	CopyBufferData(newBuffer, Src.dataBuffer, Src.bufferFill);
	bufferFill = Src.bufferFill;
	bufferSize = Src.bufferSize;

	delete[] dataBuffer; // Array delete
	dataBuffer = newBuffer;

	return *this;
}

Vector& Vector::operator=(Vector& rVal)
{
	if (this == &rVal)
		return *this;

	// aufräumen
	delete[] dataBuffer;

	// Daten von rVal stehlen
	dataBuffer = rVal.dataBuffer;
	bufferSize = rVal.bufferSize;
	bufferFill = rVal.bufferFill;

	// rVal für Destruktor aufbereiten
	rVal.dataBuffer = nullptr;
	rVal.bufferSize = rVal.bufferFill = 0;

	return *this;
}

int& Vector::operator[](size_t Index)
{
	if (Index >= bufferFill)
		throw std::exception("index out of range");
	return dataBuffer[Index];
}

void Vector::operator()(Function Fnc)
{
	for (size_t i = 0; i < bufferFill; i++)
		dataBuffer[i] = Fnc(dataBuffer[i]); // Änderung der Daten mit Funktion
}

std::ostream& operator<<(std::ostream& out, const Vector& data)
{
	char sep = '\n';
	out << "*** Vector ***" << sep;
	out << "Size = " << data.bufferSize << sep;
	out << "Fill = " << data.bufferFill << sep;
	for (size_t i = 0; i < data.bufferFill; i++)
		out << "[" << i << "] = " << data.dataBuffer[i] << sep;
	return out;
}
