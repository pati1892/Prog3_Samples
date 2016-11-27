#pragma once
#include "IPrimitive.h"

class Line : public APrimitive
{
public:
	Line();
	virtual ~Line() override;

	virtual void Draw() override;
};

