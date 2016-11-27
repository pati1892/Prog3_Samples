#include <iostream>

#include "Line.h"


Line::Line()
{
}


Line::~Line()
{
}

void Line::Draw()
{
	std::cout << "-- Line at [" << x << "," << y << "] Size=(" << width << "," << height << ")\n";
}
