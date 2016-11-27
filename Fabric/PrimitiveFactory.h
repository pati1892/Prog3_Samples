#pragma once
#include "IPrimitiveFactory.h"

class PrimitiveFactory : public IPrimitiveFactory
{
public:
	PrimitiveFactory();
	~PrimitiveFactory();

	virtual PrimitivePtr getEllipse() override;
	virtual PrimitivePtr getRectangle() override;
	virtual PrimitivePtr getLine() override;

};

