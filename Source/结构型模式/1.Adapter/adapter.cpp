/** 	
　　Adapter模式的实现
  　File		:Adapter.cpp 
	Author		:singmelody 
	Date		:2012.11.23
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Adaptee
{
public:
	Adaptee() { FUNCINFO; }
	virtual ~Adaptee() { FUNCINFO; }

	void SpecificRequest(){ FUNCINFO; }
};

class Target
{
public:
	Target() { FUNCINFO; }
	virtual ~Target() { FUNCINFO;  }
	
	virtual void Request() = 0;
};


class Adapter : public Target
{
public:
	Adapter(Adaptee *adaptee) : m_adaptee(adaptee){ FUNCINFO; }
	~Adapter(){ FUNCINFO; delete m_adaptee;}

	void Request() { FUNCINFO; m_adaptee->SpecificRequest(); }
protected:
	Adaptee*		m_adaptee;
};

int main()
{
 	Adaptee*	adaptee	= new Adaptee();
 	Target*		target	= new Adapter(adaptee);
 	target->Request();
 
 	delete target;

	return 0;
}