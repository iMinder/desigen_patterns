/** 	
　　Chain 0f Responsibility模式的实现
  　File		:chain of responsibility.cpp 
	Author		:singmelody 
	Date		:2012.11.25
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Handler
{
public:
	Handler(Handler * handler):m_successor(handler) {  FUNCINFO; }
	virtual ~Handler() { FUNCINFO; 	}
	virtual void HandleRequest() = 0;
protected:
	Handler*	m_successor;
};

class ConcreteHandler1 : public Handler
{
public:
	ConcreteHandler1(Handler * handler = NULL):Handler(handler){ FUNCINFO; }
	~ConcreteHandler1() { FUNCINFO; }

	void HandleRequest() 
	{  	
		FUNCINFO;
		if (NULL != m_successor)
		{
			m_successor->HandleRequest();
		}
	}
};

class ConcreteHandler2 : public Handler
{
public:
	ConcreteHandler2(Handler * handler = NULL ):Handler(handler){ FUNCINFO; }
	~ConcreteHandler2() { FUNCINFO; }

	void HandleRequest() 
	{  	
		FUNCINFO;
		if (NULL != m_successor)
		{
			m_successor->HandleRequest();
		}
	}
};

int main()
{
	Handler *p2 = new ConcreteHandler2();
	Handler *p1 = new ConcreteHandler1(p2);

	p1->HandleRequest();

	delete p1;
	delete p2;

	return 0;
}