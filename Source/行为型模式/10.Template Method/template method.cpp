/** 	
　　Template Method模式的实现
  　File		:template method.cpp 
	Author		:singmelody 
	Date		:2012.11.24
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class AbstractClass
{
public:
	AbstractClass() { FUNCINFO; }
	virtual ~AbstractClass() { FUNCINFO; }
	
	void TemplateMethod()
	{
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
protected:
	virtual void PrimitiveOperation1() { FUNCINFO; }
	virtual void PrimitiveOperation2() { FUNCINFO; }
};

class ConcreteClass : public AbstractClass
{
public:
	ConcreteClass() { FUNCINFO; }
	~ConcreteClass() { FUNCINFO; }
	
	void PrimitiveOperation1() { FUNCINFO; }
	void PrimitiveOperation2() { FUNCINFO; }
};

int main()
{
	AbstractClass * abstract = new ConcreteClass();
	abstract->TemplateMethod();

	delete abstract;
	return 0;
}