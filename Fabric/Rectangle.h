#pragma once
#include "IPrimitive.h"

class Rectangle : public APrimitive
{
public:
	Rectangle();
	virtual ~Rectangle() override;

	virtual void Draw() override;
};

