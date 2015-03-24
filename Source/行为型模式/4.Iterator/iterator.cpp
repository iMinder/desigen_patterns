/** 	
　　Iterator模式的实现
  　File		:iterator.cpp 
	Author		:singmelody 
	Date		:2012.11.26
*/
#include <iostream>
#include <vector>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}
typedef int	DataType;

class ConcreteIterator;
class Iterator;

class Aggregate
{
public:
	Aggregate(int size) { FUNCINFO; m_vec.reserve(size); }
	virtual ~Aggregate() { FUNCINFO; m_vec.clear(); }

	virtual Iterator&	CreateIterator() = 0;
	int					GetSize() { return m_vec.size(); }
	void				Push(int number) { m_vec.push_back(number); }
	DataType&			operator[](int offset){ return m_vec[offset]; }
protected:
	list<DataType>	m_vec;
};

class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate(int size) :Aggregate(size){ FUNCINFO; }
	~ConcreteAggregate() { FUNCINFO; }

	Iterator& CreateIterator();
};

class Iterator
{
public:
	Iterator(Aggregate*	aggregate):m_aggregate(aggregate) { FUNCINFO; }
	virtual ~Iterator() { 	FUNCINFO; }
	
	virtual bool		IsDone()			= 0;
	virtual void		Next()				= 0;
	virtual void		First()				= 0;
	virtual DataType&	CurrentItem() const	= 0;
protected:
	Aggregate*	m_aggregate;
	int			m_curIndex;
};

class ConcreteIterator : public Iterator
{
public:
	ConcreteIterator(Aggregate* aggregate) : Iterator(aggregate){ FUNCINFO;}
	~ConcreteIterator() { FUNCINFO; }

	bool	IsDone() 
	{
		return m_curIndex <	m_aggregate->GetSize();
	}

	void	Next()
	{
		m_curIndex++;
	}

	void	First()
	{
		m_curIndex = 0;
	}

	DataType& CurrentItem() const
	{
		 return (*m_aggregate)[m_curIndex];
	}
};

Iterator& ConcreteAggregate::CreateIterator()
{
	Iterator* p = new ConcreteIterator(this);
	return *p;
}

int main()
{
	Aggregate* aggregate = new ConcreteAggregate(4);
	aggregate->Push(10);
	aggregate->Push(20);
	aggregate->Push(30);

	Iterator& iterator  = aggregate->CreateIterator();

	for(iterator.First();
		false != iterator.IsDone(); iterator.Next() )
	{
		cout<<iterator.CurrentItem()<<endl;
	}
	
	SAFE_DELETE(aggregate);

	Iterator* p = &iterator;
	SAFE_DELETE(p);

	return 0;
}