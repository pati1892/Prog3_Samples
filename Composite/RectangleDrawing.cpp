#include "RectangleDrawing.h"


RectangleDrawing::RectangleDrawing()
{
}

RectangleDrawing::RectangleDrawing(int X, int Y, int width, int height)
{
	setRect(X, Y, width, height);
}

RectangleDrawing::~RectangleDrawing()
{
}

void RectangleDrawing::DrawItem()
{
	Draw();
}

void RectangleDrawing::AddItem(DrawingItemPtr item)
{
	throw std::exception("AddItem to Rectangle not possible");
}
