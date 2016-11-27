#include "Drawing.h"


Drawing::Drawing()
{
}


Drawing::~Drawing()
{
}

void Drawing::DrawItem()
{
	for (auto item : items)
		item->DrawItem();
}

void Drawing::AddItem(DrawingItemPtr item)
{
	items.push_back(item);
}
