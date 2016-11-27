#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "ctor A()" << endl;
	}
	A(const A& /*Src*/)
	{
		cout << "ctor A(const A& Src)" << endl;
	}
	~A()
	{
		cout << "dtor ~A()" << endl;
	}

	void CallA()
	{
		cout << "called CallA()" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "ctor B()" << endl;
	}
	B(const B& /*Src*/)
	{
		cout << "ctor B(const B& Src)" << endl;
	}
	~B()
	{
		cout << "dtor ~B()" << endl;
	}

	void CallB()
	{
		cout << "called CallB()" << endl;
	}
};

class AB : public A, public B
{
public:
	AB()
	{
		cout << "ctor AB()" << endl;
	}
	AB(const AB& /*Src*/)
	{
		cout << "ctor AB(const AB& Src)" << endl;
	}
	~AB()
	{
		cout << "dtor ~AB()" << endl;
	}

	void CallAB()
	{
		cout << "called CallAB()" << endl;
	}
};

void OnA(A& data)
{
	data.CallA();
}

void OnB(B& data)
{
	data.CallB();
}

void OnB(B* data)
{
	data->CallB();
}

void OnAB(AB data)
{
	data.CallB();
}

void WorkInBlockWithAB()
{
	AB ab;
	ab.CallA();
	ab.CallB();
	ab.CallAB();

	AB copy = ab;
	copy.CallAB();

	// Polymorphy von AB auf A und B
	B& refB = ab;
	refB.CallB();
	A& refA = ab;
	refA.CallA();

	OnA(ab);
	OnB(ab);
	OnB(&ab);
	OnAB(ab);
}

int main()
{
	WorkInBlockWithAB();
}