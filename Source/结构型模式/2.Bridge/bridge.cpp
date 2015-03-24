/** 	
　　Bridge模式的实现
　　File		:Brige.cpp 
　　Author		:singmelody 
　　Date		:2012.11.19 
*/
#include <iostream>
using namespace std;

class Implementor
{
public:
	virtual void OperationImp() = 0;
	virtual ~Implementor(){ cout<<__FUNCTION__<<endl;}
};

class ConcreteImplementorA : public Implementor
{
public:
	void OperationImp()	{	cout<<__FUNCTION__<<endl;	}
	virtual ~ConcreteImplementorA() { cout<<__FUNCTION__<<endl; }

};

class ConcreteImplementorB : public Implementor
{
public:
	void OperationImp()	{	cout<<__FUNCTION__<<endl;	}
	virtual ~ConcreteImplementorB() { cout<<__FUNCTION__<<endl; }
};
class Abstraction
{
public:
	Abstraction(Implementor *implementor):m_implementor(implementor){	cout<<__FUNCTION__<<endl; }
	virtual ~Abstraction(){ cout<<__FUNCTION__<<endl;delete m_implementor; }

	virtual void OperationImpl()
	{
		cout<<__FUNCTION__<<endl;
		m_implementor->OperationImp();
	}
protected:
	Implementor* m_implementor;
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementor *implementor):Abstraction(implementor) { cout<<__FUNCTION__<<endl; }
	~RefinedAbstraction(){ cout<<__FUNCTION__<<endl; }

	void OperationImpl(){ Abstraction::OperationImpl(); doSomething(); }
	void doSomething(){ cout<<"Hello World"<<endl;}
};

int main()
{
	Implementor* implentor = new ConcreteImplementorA();
	Abstraction* abstraction = new RefinedAbstraction(implentor);
	abstraction->OperationImpl();

	delete abstraction;
	return 0;
}