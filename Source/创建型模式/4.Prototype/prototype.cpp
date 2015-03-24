/** 	
　　Prototype模式的实现
　　File		:prototype.cpp 
　　Author		:singmelody 
　　Date		:2012.11.21 
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Prototype
{
public:
	Prototype() { FUNCINFO; }
	virtual ~Prototype() { FUNCINFO; }

	virtual Prototype* Clone() = 0;
};


class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1() { FUNCINFO; }
	~ConcretePrototype1() { FUNCINFO; }

	Prototype * Clone() { FUNCINFO; return new ConcretePrototype1(); }
};

class ConcretePrototype2 : public Prototype
{
public:
	ConcretePrototype2() { FUNCINFO; }
	~ConcretePrototype2() { FUNCINFO; }

	Prototype*	Clone() { FUNCINFO; return new ConcretePrototype2(); }
};

int main()
{
	Prototype* prototype = new ConcretePrototype1();
	Prototype* first = prototype->Clone();

	Prototype* prototype1 = new ConcretePrototype2();
	Prototype* second = prototype1->Clone();

	delete prototype;
	delete prototype1;
	delete first;
	delete second;
	return 0;
}