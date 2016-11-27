#include "EllipseDrawing.h"


EllipseDrawing::EllipseDrawing()
{
}

EllipseDrawing::EllipseDrawing(int X, int Y, int width, int height)
{
	setRect(X, Y, width, height);
}

EllipseDrawing::~EllipseDrawing()
{
}

void EllipseDrawing::DrawItem()
{
	Draw();
}

void EllipseDrawing::AddItem(DrawingItemPtr item)
{
	throw std::exception("AddItem to Ellipse not possible");
}
