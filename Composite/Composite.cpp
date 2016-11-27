#include <iostream>
#include <memory>

using namespace std;

#include "Drawing.h"
#include "EllipseDrawing.h"
#include "LineDrawing.h"
#include "RectangleDrawing.h"

unique_ptr<Drawing> BuildDrawing()
{
	unique_ptr<Drawing> result(new Drawing());
	auto item = std::static_pointer_cast<IDrawingItem>(std::make_shared<LineDrawing>(10, 11, 5, 6));
	result->AddItem(item);
	item = std::static_pointer_cast<IDrawingItem>(std::make_shared<EllipseDrawing>(10, 11, 5, 6));
	result->AddItem(item);
	item = std::static_pointer_cast<IDrawingItem>(std::make_shared<RectangleDrawing>(10, 11, 5, 6));
	result->AddItem(item);
	return result;
}

int main()
{
	auto drawing = BuildDrawing();
	auto subDrawing = BuildDrawing();
	drawing->AddItem(DrawingItemPtr(subDrawing.release()));

	drawing->DrawItem();
}