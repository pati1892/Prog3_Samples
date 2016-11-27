#include "IPrimitive.h"

IPrimitive::~IPrimitive()
{
}

void APrimitive::setWidth(int widthVal)
{
	width = widthVal;
}

void APrimitive::setHeight(int heightVal)
{
	this->height = heightVal;
}

void APrimitive::setLeftUpper(int X, int Y)
{
	x = X;
	y = Y;
}

void APrimitive::setRect(int X, int Y, int widthVal, int heightVal)
{
	setLeftUpper(X, Y);
	setWidth(widthVal);
	setHeight(heightVal);
}
