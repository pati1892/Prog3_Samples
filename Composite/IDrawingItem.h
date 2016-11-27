#pragma once
#include <memory>
#include <exception>

class IDrawingItem;
using DrawingItemPtr = std::shared_ptr < IDrawingItem > ;

class IDrawingItem // Komponente
{
public:
	IDrawingItem();
	virtual ~IDrawingItem();

	virtual void DrawItem() = 0;
	virtual void AddItem(DrawingItemPtr item) = 0;
};

