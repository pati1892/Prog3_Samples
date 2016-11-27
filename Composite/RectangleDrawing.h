#pragma once
#include "../Fabric/Rectangle.h"
#include "IDrawingItem.h"

class RectangleDrawing :
	public Rectangle, public IDrawingItem
{
public:
	RectangleDrawing();
	RectangleDrawing(int X, int Y, int width, int height);
	virtual ~RectangleDrawing() override;
	
	virtual void DrawItem() override;
	virtual void AddItem(DrawingItemPtr item) override;
};

