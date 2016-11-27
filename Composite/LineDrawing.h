#pragma once
#include "../Fabric/Line.h"
#include "IDrawingItem.h"

class LineDrawing :
	public Line, public IDrawingItem
{
public:
	LineDrawing();
	LineDrawing(int X, int Y, int width, int height);
	virtual ~LineDrawing() override;

	virtual void DrawItem() override;
	virtual void AddItem(DrawingItemPtr item) override;
};

