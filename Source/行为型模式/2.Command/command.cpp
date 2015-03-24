/** 	
　　Command模式的实现
  　File		:command.cpp 
	Author		:singmelody 
	Date		:2012.11.26
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
#define SAFE_DELETE(p) if(NULL != p) { delete p,p=NULL; }
enum STATE
{
	STATE_WAIT,
	STATE_SLEEP,
	STATE_RUN
};

char* str[] = {"WAIT","SLEEP","RUN"};

class Receiver
{
public:
	Receiver(){ FUNCINFO; m_state = STATE_WAIT;  }
	~Receiver(){ FUNCINFO; }

	void Action(STATE state){ FUNCINFO; m_state = state; cout<<str[m_state]<<endl;}
private:
	STATE m_state;
};

class Command 
{
public:
	Command(Receiver * receiver = NULL,STATE state = STATE_WAIT) : m_receiver(receiver),m_state(state){ FUNCINFO; }
	virtual ~Command(){ FUNCINFO; }
	
	virtual void Execute() = 0;
protected:
	Receiver*	m_receiver;
	STATE		m_state;
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* receiver,STATE state) : Command(receiver,state) { FUNCINFO; }
	~ConcreteCommand() { FUNCINFO; }
	void Execute() 
	{ 
		FUNCINFO; 
		if(NULL != m_receiver)
		{
			m_receiver->Action(m_state); 
		}
	}
};

class Invoker
{
public:
	Invoker(Command* command = NULL):m_command(command) { FUNCINFO; }
	~Invoker() { FUNCINFO; }

	void Invoke() 
	{
		FUNCINFO;
		if (NULL != m_command)
		{
			m_command->Execute();
		}
	}
private:
	Command*	m_command;
};

int main()
{
	Receiver* receiver = new Receiver();
	Command* command = new ConcreteCommand(receiver,STATE_RUN);
	Invoker* invoker = new Invoker(command);

	invoker->Invoke();

	SAFE_DELETE(receiver);
	SAFE_DELETE(command);
	SAFE_DELETE(invoker);
	
	return 0;
}