/** 	
　　Strategy模式的实现
  　File		:strategy.cpp 
	Author		:singmelody 
	Date		:2012.11.24
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
#define SAFE_DELETE(p) delete p;p = NULL;

class Strategy
{
public:
	Strategy(){ FUNCINFO; }
	virtual ~Strategy() { FUNCINFO; }

	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA(){ FUNCINFO; }
	~ConcreteStrategyA() { FUNCINFO; }

	void AlgorithmInterface() { FUNCINFO;}

};

class ConcreteStrategyB : public Strategy
{
public:
	ConcreteStrategyB(){ FUNCINFO; }
	~ConcreteStrategyB() { FUNCINFO; }
	
	void AlgorithmInterface() { FUNCINFO; }
};

class ConcreteStrategyC : public Strategy
{
public:
	ConcreteStrategyC(){ FUNCINFO; }
	~ConcreteStrategyC() { FUNCINFO; }
	void AlgorithmInterface() { FUNCINFO; }
};

class Context
{
public:
	Context(Strategy *p):m_strategy(p){ FUNCINFO; }
	~Context(){ FUNCINFO; SAFE_DELETE(m_strategy); }

	void ContextInterface(){ FUNCINFO; m_strategy->AlgorithmInterface(); }
private:
	Strategy* m_strategy;
};
int main()
{
	Strategy*	strategy = new ConcreteStrategyA();
	Context*	context	 = new Context(strategy);
	context->ContextInterface();

	delete context;
	return 0;
}