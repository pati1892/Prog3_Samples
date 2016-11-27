#include <iostream>
#include "Ellipse.h"

Ellipse::Ellipse()
{
}


Ellipse::~Ellipse()
{
}

void Ellipse::Draw()
{
	std::cout << "O Ellipse at [" << x << "," << y << "] Size=(" << width << "," << height << ")\n";
}
