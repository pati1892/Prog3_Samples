#pragma once

#include <memory>
#include "IPrimitive.h"

using PrimitivePtr = std::shared_ptr < IPrimitive > ;

class IPrimitiveFactory
{
public:
	virtual ~IPrimitiveFactory();

	virtual PrimitivePtr getEllipse() = 0;
	virtual PrimitivePtr getRectangle() = 0;
	virtual PrimitivePtr getLine() = 0;
};

