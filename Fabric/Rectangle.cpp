#include <iostream>

#include "Rectangle.h"


Rectangle::Rectangle()
{
}


Rectangle::~Rectangle()
{
}

void Rectangle::Draw()
{
	std::cout << "[] Rectangle at [" << x << "," << y << "] Size=(" << width << "," << height << ")\n";
}
