#include "PrimitiveFactory.h"

#include "Ellipse.h"
#include "Rectangle.h"
#include "Line.h"


PrimitiveFactory::PrimitiveFactory()
{
}


PrimitiveFactory::~PrimitiveFactory()
{
}

PrimitivePtr PrimitiveFactory::getEllipse()
{
	return std::static_pointer_cast<IPrimitive>(std::make_shared<Ellipse>());
}

PrimitivePtr PrimitiveFactory::getRectangle()
{
	return std::static_pointer_cast<IPrimitive>(std::make_shared<Rectangle>());
}

PrimitivePtr PrimitiveFactory::getLine()
{
	return std::static_pointer_cast<IPrimitive>(std::make_shared<Line>());
}
