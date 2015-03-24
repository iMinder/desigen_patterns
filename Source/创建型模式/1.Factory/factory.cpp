/**
　　factory.cpp 
　　Author		:singmelody 
　　Date		:2012.11.12 
　　Goal		:Factory模式的实现
*/
#include <iostream>
using namespace std;

class Product
{
public:
	virtual ~Product(){ cout<<__FUNCTION__<<endl; }
};

class ProductA : public Product
{
public:
	~ProductA() { cout<<__FUNCTION__<<endl; }
};

class Creator
{
public:
	virtual ~Creator(){ cout<<__FUNCTION__<<endl; }
	Product* AnOperation(){	return FactoryMethod();	}

protected:
	virtual Product* FactoryMethod() = 0;

};

class CreatorA : public Creator
{
public:
	~CreatorA() { cout<<__FUNCTION__<<endl; }

protected:
	Product* FactoryMethod()
	{
		cout<<__FUNCTION__<<endl;
		return new ProductA();
	}
};

int main()
{
	Creator *creator = new CreatorA();
	Product *product = creator->AnOperation();

	delete product;
	delete creator;
	
	return 0;
}