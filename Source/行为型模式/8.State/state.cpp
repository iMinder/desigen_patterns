/** 	
　　State模式的实现
  　File		:state.cpp 
	Author		:singmelody 
	Date		:2012.11.25
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Context;

class State
{
public:
	State() { FUNCINFO; }
	virtual ~State() { FUNCINFO; }
	virtual void Handle(Context *context) = 0;
};

class ConcreteStateA : public State
{
public:
	ConcreteStateA() { FUNCINFO; }
	~ConcreteStateA() { FUNCINFO; }
	void	Handle(Context *context);
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB() { FUNCINFO; }
	~ConcreteStateB() { FUNCINFO; }
	void	Handle(Context *context);
};

class Context
{
public:
	Context(State* state):m_state(state){ FUNCINFO;}
	~Context() { FUNCINFO; delete m_state; }
	void ChangleState(State *state)
	{
		FUNCINFO;
		if(NULL != m_state)
		{
			delete m_state;
			m_state = NULL;
		}

		m_state = state;
	}

	void Request() 
	{ 
		FUNCINFO; 
		if (NULL != m_state)
		{
			m_state->Handle(this); 
		}
	}
private:
	State*	m_state;
};

void	ConcreteStateA::Handle(Context *context)
{
	FUNCINFO; 
	context->ChangleState(new ConcreteStateB() );
}

void	ConcreteStateB::Handle(Context *context)
{
	FUNCINFO; 
	context->ChangleState(new ConcreteStateA() );
}

int main()
{
	State *pState = new ConcreteStateA();
	Context *pContext = new Context(pState);
	pContext->Request();
	pContext->Request();
	pContext->Request();

	delete pContext;
	
	return 0;
}