/** 	
　　Visitor模式的实现
　　File		:visitor.cpp 
　　Author		:singmelody 
　　Date		:2012.11.20
 */
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
	Visitor(){ FUNCINFO; }
	virtual ~Visitor(){ FUNCINFO; }

	virtual void VisitConcreteElementA(ConcreteElementA* elment) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB* elment) = 0;
};

class ConcreteVisitor1 : public Visitor
{
public:
	ConcreteVisitor1() { FUNCINFO; }
	~ConcreteVisitor1() { FUNCINFO; }
	void VisitConcreteElementA(ConcreteElementA* elment);
	void VisitConcreteElementB(ConcreteElementB* elment);
};

class ConcreteVisitor2 : public Visitor
{
public:
	ConcreteVisitor2() { FUNCINFO; }
	~ConcreteVisitor2() { FUNCINFO; }
	void VisitConcreteElementA(ConcreteElementA* element);
	void VisitConcreteElementB(ConcreteElementB* element);
};

class Element
{
public:
	Element() { FUNCINFO; }
	virtual ~Element() { FUNCINFO; }

	virtual void Accept(Visitor & visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
	ConcreteElementA() { FUNCINFO; }
	~ConcreteElementA() { FUNCINFO; }

	void Accept(Visitor & visitor){ FUNCINFO; visitor.VisitConcreteElementA(this); }
	void OperationA() { }
};

class ConcreteElementB : public Element
{
public:
	ConcreteElementB() { FUNCINFO; }
	~ConcreteElementB() { FUNCINFO; }
	void Accept(Visitor & visitor){ FUNCINFO; visitor.VisitConcreteElementB(this); }
	void OperationB() { }

};

class CompositeElement
{
public:
	CompositeElement() { FUNCINFO; }
	~CompositeElement()
	{
		for(list<Element*>::iterator itr = m_children.begin(); 
			itr != m_children.end(); ++itr)
		{
			delete *itr;
		}
		
		m_children.clear();
	}
	virtual void Accept(Visitor * visitor)
	{
		for(list<Element*>::iterator itr = m_children.begin(); 
			itr != m_children.end(); ++itr)
		{
			(*itr)->Accept(*visitor);	
		}
	}

	void Attach(Element * element)
	{
		m_children.push_back(element);
	}

	void Detach(Element * element)
	{
		list<Element *>::iterator itr = std::find(m_children.begin(),m_children.end(),element);
	}
private:
	list<Element *> m_children;
};

void ConcreteVisitor1::VisitConcreteElementA(ConcreteElementA* element){ FUNCINFO;}
void ConcreteVisitor1::VisitConcreteElementB(ConcreteElementB* element){ FUNCINFO;}

void ConcreteVisitor2::VisitConcreteElementA(ConcreteElementA* elment){ FUNCINFO;}
void ConcreteVisitor2::VisitConcreteElementB(ConcreteElementB* elment){ FUNCINFO;}

int main()
{
	CompositeElement *collection = new CompositeElement();
	Element * elementA = new ConcreteElementA();
	Element * elementB = new ConcreteElementB();
	collection->Attach(elementA);
	collection->Attach(elementB);

	Visitor * visitor1 = new ConcreteVisitor1();
	Visitor * visitor2 = new ConcreteVisitor2();
	collection->Accept(visitor1);
	collection->Accept(visitor2);

	delete visitor1;
	delete visitor2;
	delete collection;
	
	return 0;
}