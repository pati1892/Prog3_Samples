#include "LineDrawing.h"


LineDrawing::LineDrawing()
{
}

LineDrawing::LineDrawing(int X, int Y, int width, int height)
{
	setRect(X, Y, width, height);
}

LineDrawing::~LineDrawing()
{
}

void LineDrawing::DrawItem()
{
	Draw();
}

void LineDrawing::AddItem(DrawingItemPtr item)
{
	throw std::exception("AddItem to Line not possible");
}

