#include <iostream>
#include <cassert> // Deklaration der assert Makros

// MS C-Runtime Debug Tools 
#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__) // new operator mit Zeileninformation
#define new DEBUG_CLIENTBLOCK
#endif // _DEBUG


using namespace std;

class A
{
public:
	A() { cout << "ctor A()" << endl; }
	A(const A&) { cout << "ctor A(const A&)" << endl; }
	~A() { cout << "dtor ~A()" << endl; }
};

using Action = void(*)(void);

void TestCreate(Action ToDo)
{
	try
	{
		ToDo();
	}
	catch (bad_alloc e)
	{
		cout << e.what() << endl;
	}
}

void CreateObject()
{
	A *pa = new A();
	delete pa;
	pa = nullptr; // zur Vorsicht
}

void CreateObjectArray()
{
	A *pa = new A[10];
	delete[] pa;
	pa = nullptr; // zur Vorsicht
}

void MakeMemoryLeak()
{
	size_t len = 100;
	auto pArray = new int[len];
	for (size_t i = 0; i < len; i++)
		*(pArray + i) = i + 1;

	//delete[] pArray;
	//pArray = nullptr;
}

void CheckMemoryLeaks()
{
	assert(_CrtCheckMemory()); // Heap defekt
	_CrtDumpMemoryLeaks(); // Leaks
}

int main()
{
	TestCreate(CreateObject);
	TestCreate(CreateObjectArray);

	MakeMemoryLeak();
	CheckMemoryLeaks();
}