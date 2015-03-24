/** 	
　　memento模式的实现
  　File		:memento.cpp 
	Author		:singmelody 
	Date		:2012.11.28
*/
#include <iostream>
#include <assert.h>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
#define SAFE_DELETE(p) if(NULL != p){ delete p,p=NULL;}

enum STATE
{
	STATE_WAIT,
	STATE_WALK,
	STATE_RUN,
	
	STATE_SUM
};

char * StateStr[] = {"WAIT","WALK","RUN"};

class Memento
{
public:
	~Memento() { FUNCINFO; }
private:
	friend class Originator;
	Memento(STATE state = STATE_WAIT):m_state(state){ FUNCINFO; }

	void SetState(STATE state) { 
		FUNCINFO; 
		if(state < STATE_SUM)
			m_state = state;
		else
			assert("State is Not Right");
		
	}
	STATE GetState()	{ FUNCINFO; return m_state; }

	STATE m_state;
};

class Originator
{
public:
	Originator(STATE state = STATE_WAIT):m_state(state) { FUNCINFO; }
	~Originator() { FUNCINFO; }

	void SetMemento(Memento *m)
	{
		FUNCINFO;
		if(NULL != m)
		{
			m_state = m->GetState();
		}
	}

	Memento* CreateMemento(STATE state)
	{
		FUNCINFO;
		return new Memento(state);
	}

	Memento* CreateMemento()
	{
		FUNCINFO;
		return new Memento(m_state);
	}

	void PrintState()
	{
		cout<<StateStr[m_state]<<endl;
	}

private:
	STATE m_state;
};

int main()
{
	Originator * originator = new Originator(STATE_WAIT);
	originator->PrintState();

	// store the old state
	Memento *oldMemento = originator->CreateMemento();
	Memento *newMemento = originator->CreateMemento(STATE_RUN);

	originator->SetMemento(newMemento);
	originator->PrintState();

	// restore the old state
	originator->SetMemento(oldMemento);
	originator->PrintState();

	SAFE_DELETE(oldMemento);
	SAFE_DELETE(newMemento);
	SAFE_DELETE(originator);

	return 0;
}