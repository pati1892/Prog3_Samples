#pragma once
#include "../Fabric/Ellipse.h"
#include "IDrawingItem.h"

class EllipseDrawing :
	public Ellipse, public IDrawingItem
{
public:
	EllipseDrawing();
	EllipseDrawing(int X, int Y, int width, int height);
	virtual ~EllipseDrawing() override;

	virtual void DrawItem() override;
	virtual void AddItem(DrawingItemPtr item) override;
};

