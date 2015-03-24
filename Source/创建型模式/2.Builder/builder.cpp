/** 	
　　Builder模式的实现
　　File		:buidler.cpp 
　　Author		:singmelody 
　　Date		:2012.11.20
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Builder;
class Director
{
public:
	Director(Builder *builder):m_builder(builder) { FUNCINFO;}
	~Director() { FUNCINFO; delete m_builder; m_builder = NULL; }

	void Construct();
private:
	Builder*	m_builder;
};

class Builder
{
public:
	Builder() { FUNCINFO; }
	virtual ~Builder() { FUNCINFO; }

	virtual void BuilderPartA() = 0;
	virtual void BuilderPartB() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1() { FUNCINFO; }
	~ConcreteBuilder1() { FUNCINFO; }
	
	void BuilderPartA() { FUNCINFO; }
	void BuilderPartB() { FUNCINFO; }
};

class ConcreteBuilder2 : public Builder
{
public:
	ConcreteBuilder2() { FUNCINFO; }
	~ConcreteBuilder2() { FUNCINFO; }

	void BuilderPartA() { FUNCINFO; }
	void BuilderPartB() { FUNCINFO; }
};

void Director::Construct()
{ 
	FUNCINFO; 
	m_builder->BuilderPartA();
	m_builder->BuilderPartB();
}

int main()
{
	Builder * builder1 = new ConcreteBuilder1();
	Director* director1 = new Director(builder1);
	director1->Construct();
	
	Builder * builder2 = new ConcreteBuilder2();
	Director* director2 = new Director(builder2);
	director2->Construct();

	delete director1;
	delete director2;
	return 0;
}