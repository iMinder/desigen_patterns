/** 	
　　Mediator模式的实现
  　File		:mediator.cpp 
	Author		:singmelody 
	Date		:2012.11.28 
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Colleage
{
public:
	Colleage() { FUNCINFO; }
	virtual ~Colleage() { FUNCINFO; }

	virtual void Command() = 0;
};

class ConcreteColleage1 : public Colleage
{
public:
	ConcreteColleage1(){ FUNCINFO; }
	~ConcreteColleage1(){ FUNCINFO; }

	void Command() { FUNCINFO; }
};

class ConcreteColleage2 : public Colleage
{
public:
	ConcreteColleage2(){ FUNCINFO; }
	~ConcreteColleage2(){ FUNCINFO; }

	void Command() { FUNCINFO; }
};

class Mediator
{
public:
	Mediator(){ FUNCINFO; }
	virtual ~Mediator() { FUNCINFO; }

	virtual void Execute() = 0;
};

class ConcreteMediator : public Mediator
{
public:
	ConcreteMediator(Colleage* p,Colleage* q):m_colleage1(p),m_colleage2(q){ FUNCINFO; }
	~ConcreteMediator(){ FUNCINFO; }

	void Execute()
	{
		FUNCINFO;
		m_colleage1->Command();
		m_colleage2->Command();
	}
private:
	Colleage * m_colleage1;
	Colleage * m_colleage2;
};

int main()
{
	Colleage * colleage1 = new ConcreteColleage1();
	Colleage * colleage2 = new ConcreteColleage1();

	Mediator * mediator = new ConcreteMediator(colleage1,colleage2);

	mediator->Execute();
	
	delete colleage1;
	delete colleage2;
	delete mediator;
	return 0;
}