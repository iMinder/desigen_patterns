/** 	
　　Composite模式的实现
　　File		:composite.cpp 
　　Author		:singmelody 
　　Date		:2012.11.21
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <assert.h>
using namespace std;
#define FUNCINFO cout<<__FUNCTION__<<endl;

class Component
{
public:
	Component()	{	FUNCINFO }
	virtual ~Component() {	FUNCINFO }

	virtual void Operation() = 0;
	virtual void Add(Component *component){}
	virtual bool Remove(Component *component){ return false; }
	virtual Component * GetChild(int index) { return NULL; }
};

class Leaf : public Component
{
public:
	Leaf() { FUNCINFO; }
	~Leaf() { FUNCINFO; }
	void Operation(){ FUNCINFO; }
};

class Composite : public Component
{
public:
	Composite() { FUNCINFO }
	~Composite() 
	{ 
		FUNCINFO; 
		for(ComponentIterator itr = m_list.begin();
			itr != m_list.end(); ++itr)
		{
			delete *itr;
		}
		m_list.clear();
	}

	void Operation()
	{
		FUNCINFO;
		for(ComponentIterator itr = m_list.begin(); itr != m_list.end(); ++itr)
		{
			(*itr)->Operation();
		}
	}

	Component* GetChild(int index)
	{
		FUNCINFO;
		if(index < 0 && index >= m_list.size())
			return NULL;

		ComponentIterator itr;
		int count = 0;
		for(itr = m_list.begin();count < index;count++,itr++);

		return *itr;
	}

	void Add(Component *component) { FUNCINFO; m_list.push_back(component); }
	bool Remove(Component *component)
	{
		FUNCINFO;
		ComponentIterator itr = find(m_list.begin(),m_list.end(),component);
		if(itr != m_list.end())
		{
			delete *itr;
			m_list.erase(itr);
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	list<Component *> m_list;
	typedef list<Component *>::iterator ComponentIterator;
};

int main()
{
	Component * composite = new Composite();
	Component * leaf1	  = new Leaf();
	Component * leaf2	  = new Leaf();

	composite->Add(leaf1);
	composite->Add(leaf2);
	composite->Operation();

	Component * leafX = composite->GetChild(1);
	assert(leafX == leaf2);
	composite->Remove(leafX);
	composite->Operation();

	delete composite;

	return 0;
}