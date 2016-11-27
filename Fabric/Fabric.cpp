#include <iostream>
#include <memory>
#include <array>
using namespace std;

#include "IPrimitive.h"
#include "PrimitiveFactory.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__) // new operator mit Zeileninformation
#define new DEBUG_CLIENTBLOCK
#endif // _DEBUG


unique_ptr<IPrimitiveFactory> getFactory()
{
	return make_unique<PrimitiveFactory>();
}

void CheckHeap()
{
#ifdef _DEBUG
	if (_CrtDumpMemoryLeaks())
		cout << "MEM PANIC\n";
#endif
}

int main()
{
	{
		auto factory = getFactory(); // hole framework
		array<PrimitivePtr, 3> drawing;
		drawing[0] = factory->getEllipse();
		drawing[0]->setRect(1, 1, 10, 10);
		drawing[1] = factory->getRectangle();
		drawing[1]->setRect(5, 5, 20, 10);
		drawing[2] = factory->getLine();
		drawing[2]->setRect(7, 3, 14, 15);

		for (auto item : drawing)
			item->Draw();
	}
	CheckHeap();
}
