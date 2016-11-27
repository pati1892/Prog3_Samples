#include <iostream>
#include <memory>
#include <functional>
#include <array>

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__) // new operator mit Zeileninformation
#define new DEBUG_CLIENTBLOCK
#endif // _DEBUG

using namespace std;

void CheckHeap()
{
	_CrtCheckMemory(); // validiere Heap
	_CrtDumpMemoryLeaks(); // prüfe auf Speicherlecks
}

class IntItem // für Test mit Klasse
{
public:
	IntItem() {}
	IntItem(int a) { this->a = a; }
	~IntItem() {}
	int& operator*() { // Adressoperator
		return a;
	}
	operator int() { // Konvertierungsoperator
		return a;
	}
private:
	int a;
};

const int usedLen = 10;

using Action = function < void(int) > ; // fur lambda Funktoren

void IterateItems(int len, Action DoFnc)
{
	for (int i = 0; i < len; ++i)
		DoFnc(i);
}

void BadAlloc()
{
	auto pArray = new int[usedLen] {}; // alle 0
	auto fnc = [pArray](int i)
	{
		*(pArray + i) = i + 1;
		cout << "pArray[" << i << "]=" << *(pArray + i) << endl;
	};
	IterateItems(usedLen, fnc);
	// delete[] pArray;
}

void SmartPointerAlloc()
{
	// C-Array sollte nicht mit smart pointer bearbeitet werden
	// aber zum Verständnis
	typedef IntItem MyInt;
	auto deltor = [](MyInt* p) {delete[] p; };
	shared_ptr<MyInt> pArray{new MyInt[usedLen], deltor}; // alle 0
	IterateItems(usedLen,
		[pArray](int i)
		{
			*(pArray.get() + i) = i + 1;
			cout << "pArray[" << i << "]=" << *(pArray.get() + i) << endl;
		}
	);
} // Destruktion macht das delete[]

void AllSmartPointers()
{
	const auto size = 100;
	auto uPtr = make_unique<int[]>(size); // nicht mehr zuweisbar, unique_ptr
	uPtr[0] = 1;
	uPtr[99] = 100;

	using IntArray = array<int, size>; // zuweisbar mit Referenzzählung, shared_ptr
	auto sPtr = make_shared<IntArray>();
	(*sPtr)[0] = 1;
	(*sPtr)[99] = 100;

	auto wPtr = weak_ptr<IntArray>(sPtr); // keine Referenzzählung, aber Validierung
	cout << "Counter =" << sPtr.use_count() << endl;
	if (wPtr.expired())
		cout << "invalid data\n";

	sPtr.reset(); // manuell freigeben
	cout << "Counter =" << sPtr.use_count() << endl;
	if (wPtr.expired())
		cout << "invalid data\n";
}

int main()
{
	BadAlloc();
	SmartPointerAlloc();
	AllSmartPointers();
	CheckHeap();
}