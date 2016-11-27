#pragma once
#include "IPrimitive.h"

class Ellipse : public APrimitive
{
public:
	Ellipse();
	virtual ~Ellipse() override;

	virtual void Draw() override;
};

