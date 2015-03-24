/** 	
　　Factory模式的实现
　　File		:factory.cpp 
　　Author	:singmelody 
　　Date		:2012.11.18
*/
#include <iostream>
using namespace std;

class AbstractProductA
{
public:
	virtual ~AbstractProductA(){}
};

class ProductA1 : public AbstractProductA
{
public:
	ProductA1() { cout<<"ProductA1()"<<endl; }
	~ProductA1() { cout<<"~ProductA1()"<<endl; }
};

class ProductA2 : public AbstractProductA
{
public:
	ProductA2() { cout<<"ProductA2()"<<endl; }
	~ProductA2() { cout<<"~ProductA2()"<<endl; }	
};

class AbstractProductB
{
public:
	virtual ~AbstractProductB(){}
};

class ProductB1 : public AbstractProductB
{
public:
	ProductB1() { cout<<"ProductB1()"<<endl; }
	~ProductB1() { cout<<"~ProductB1()"<<endl; }	
};

class ProductB2 : public AbstractProductB
{
public:
	ProductB2() { cout<<"ProductB2()"<<endl; }
	~ProductB2() { cout<<"~ProductB2()"<<endl; }		
};


class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreateFactory1 : public AbstractFactory
{
public:
	AbstractProductA* CreateProductA(){  return new ProductA1;}
	AbstractProductB* CreateProductB(){  return new ProductB1;}
};

class ConcreateFactory2 : public AbstractFactory
{
public:
	AbstractProductA* CreateProductA(){  return new ProductA2;}
	AbstractProductB* CreateProductB(){  return new ProductB2;}
};

 
int main()
{
	AbstractFactory * factory = new ConcreateFactory1;
	AbstractProductA* productA = factory->CreateProductA();
	AbstractProductB* productB = factory->CreateProductB();
	delete productA;
	delete productB;
	delete factory;

	factory = new ConcreateFactory2;
	productA = factory->CreateProductA();
	productB = factory->CreateProductB();
	delete productA;
	delete productB;
	delete factory;

	return 0;
}

