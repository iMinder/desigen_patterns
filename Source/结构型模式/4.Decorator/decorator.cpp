/** 	
　　Decorator模式的实现
  　File		:decorator.cpp 
	Author		:singmelody 
	Date		:2012.11.23 
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Component
{
public:
	Component(){ FUNCINFO; }
	virtual ~Component() { FUNCINFO; }

	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	ConcreteComponent() { FUNCINFO; }
	~ConcreteComponent() { FUNCINFO; }

	void Operation() { FUNCINFO; }
};

class Decorator : public Component
{
public:
	Decorator(Component * component):m_component(component) { FUNCINFO; }
	~Decorator() { FUNCINFO; delete m_component; }

	void Operation() { m_component->Operation(); }
protected:
	Component *	m_component;
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component * component) : Decorator(component) { FUNCINFO; }
	~ConcreteDecoratorB() { FUNCINFO; }

	void Operation() { FUNCINFO;  Decorator::Operation(); AddedBehavior(); }
	void AddedBehavior() { FUNCINFO; }
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component * component) : Decorator(component) { FUNCINFO; }
	~ConcreteDecoratorA() { FUNCINFO; }

	void Operation() {  FUNCINFO; Decorator::Operation(); AddedState(); }
	void AddedState() { FUNCINFO; }
};

int main()
{
	Component* pComponent = new ConcreteComponent();
	Decorator* pDecorator = new ConcreteDecoratorA(pComponent);

	pDecorator->Operation();

	delete pDecorator;
	return 0;
}