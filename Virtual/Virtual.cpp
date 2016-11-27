#include <iostream>
#include <cstring>

using namespace std;

const int NameLen = 20;

class Object
{
public:
	Object()
	{
		setName("Object");
	}
	Object(char const* Name)
	{
		setName(Name);
	}

	char const* getName() const
	{
		return Name;
	}

protected:
	void setName(char const* Name)
	{
		strncpy_s(this->Name, Name, NameLen); // secure code
	}

private:
	char Name[NameLen];
};

class A : public Object
{
public:
	A() : Object("A") {}
};

class B : public Object
{
public:
	B() : Object("B") {}
};

class AB : public A, public B, public Object // Klasse erbt Object 3x
{
public:
	AB() : Object("AB") {}
};

class vA : public virtual Object
{
public:
	vA() : Object("vA") {}
};

class vB : public virtual Object
{
public:
	vB() : Object("vB") {}
};

class vAB final : public vA, public vB, public virtual Object // keine weiteren Ableitungen von AB mehr möglich, Object ist virtuelle Basisklasse
{
public:
	vAB() : Object("vAB") {}
};

void NormalVirtualBaseClass()
{
	Object obj;
	cout << "obj Name = " << obj.getName() << endl;
	A a;
	cout << "a Name = " << a.getName() << endl;
	B b;
	cout << "b Name = " << b.getName() << endl;
	AB ab;
	cout << "ab Name = " << ab.B::getName() << endl;
	cout << "ab Name = " << ab.A::getName() << endl;
	cout << "ab Name = " << ab.Object::getName() << endl;
	vAB vab;
	cout << "vab Name = " << vab.getName() << endl;
}

class vbA
{
public:
	virtual int getValue() { return 42; }
};

class obA : public vbA
{
public:
	virtual int getValue() final override { return 84; } // override auf vbA::getValue()
														// wenn virtual in vbA verschwindet wirft der Compiler einen Fehler
														// weitere Überschreibungen sind nicht mehr möglich
	int getBaseValue() { return vbA::getValue();  }
};

void VirtualMethod()
{
	obA oba;
	cout << oba.getValue() << endl;
	vbA& ref = oba;
	cout << ref.getValue() << endl;
	cout << oba.vbA::getValue() << endl;
	cout << oba.getBaseValue() << endl;
}

class abA
{
public:
	int getValue(int value) { return value;  }
	virtual int getValue() = 0; // abstrakte Methode -> abstrakte Klasse
};

class ibA : public abA
{
public:
	virtual int getValue() override { return 42; } // implementiere abstrakte Methode
};

void AbstractClass()
{
	ibA iba;
	abA& aba = iba; // polymorph 
	cout << aba.getValue() << endl;
}

class iA // rein virtuelle Basisklasse == interface
{
public:
	virtual int FuncA() = 0;
	virtual int FuncB() = 0;
	virtual ~iA() {};
};

class iiA : public iA
{
public:
	virtual int FuncA() override { return 42; };
	virtual int FuncB() override { return 84; };
};

void InterfaceUse()
{
	iiA iia;
	iA* pia = &iia;
	cout << pia->FuncA() << endl;
	cout << pia->FuncB() << endl;
}

int main()
{
	NormalVirtualBaseClass();
	VirtualMethod();
	AbstractClass();
	InterfaceUse();
}