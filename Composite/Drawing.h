#pragma once
#include "IDrawingItem.h"
#include <vector>

class Drawing : // Kompositum
	public IDrawingItem
{
public:
	Drawing();
	virtual ~Drawing();

	virtual void DrawItem() override;
	virtual void AddItem(DrawingItemPtr item) override;

private:
	using DrawingItemCol = std::vector < DrawingItemPtr > ;

	DrawingItemCol items;
};

