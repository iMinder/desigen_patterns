/** 	
　　Flyweight模式的实现
　　File		:flyweight.cpp 
　　Author		:singmelody 
　　Date		:2012.11.21
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
typedef std::string extrinsicState;

class Flyweight
{
public:
	Flyweight(extrinsicState& state):m_intrinsicState(state) { FUNCINFO; }
	virtual ~Flyweight() { FUNCINFO; }

	virtual void Operation(extrinsicState &) = 0;
	extrinsicState getInstrinsicState() const { return m_intrinsicState; }
protected:
	std::string m_intrinsicState;
};

class ConcreteFlywegiht : public Flyweight
{
public:
	ConcreteFlywegiht(extrinsicState & state):Flyweight(state) { FUNCINFO; }
	~ConcreteFlywegiht() { FUNCINFO; }

	void Operation(extrinsicState & state )
	{ 
		FUNCINFO; cout<<state<<" "<<m_intrinsicState<<endl; }
};

class UnsharedConcreateFlyweight : public Flyweight
{
public:
	UnsharedConcreateFlyweight(extrinsicState & state):Flyweight(state) { FUNCINFO;}
	~UnsharedConcreateFlyweight() { FUNCINFO; }

	void Operation(extrinsicState &state)
	{
		FUNCINFO;
		cout<<state<<endl;
	}
};

class FlyweightFactory
{
public:
	FlyweightFactory(){ FUNCINFO; }
	~FlyweightFactory() 
	{
		FUNCINFO; 
		for(FlyweightIterator itr = m_list.begin();
			itr != m_list.end();++itr)
		{
			delete *itr;
		}
		m_list.clear();
	}

	Flyweight* GetFlyweight(extrinsicState & key)
	{
		FUNCINFO;
		for(FlyweightIterator itr = m_list.begin();
			itr != m_list.end(); ++itr)
		{
			if((*itr)->getInstrinsicState() == key)
			{
				cout<<"The Flyweight:"<<key<<" Already Exist"<<endl;
				return (*itr);
			}
		}

		cout<<"Create a new Flyweight: "<<key<<endl;
		Flyweight * flyweight = new ConcreteFlywegiht(key);
		m_list.push_back(flyweight);
		return flyweight;
	}
private:
	list<Flyweight *> m_list;
	typedef list<Flyweight *>::iterator FlyweightIterator;
};

int main()
{
	FlyweightFactory * factory = new FlyweightFactory();
	factory->GetFlyweight(string("Pretty"))->Operation(string("Jack"));
	factory->GetFlyweight(string("Beautiful"))->Operation(string("Mary"));
	factory->GetFlyweight(string("Pretty"))->Operation(string("Maze"));

	delete factory;
		return 0;
}