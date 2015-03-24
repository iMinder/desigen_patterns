/** 	
　　Observer模式的实现
　　File		:observer.cpp 
　　Author		:singmelody 
　　Date		:2012.11.19
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
class Observer;

class Subject
{
public:
	enum SUBJECT_STATE
	{
		SUBJECT_STATE_WAIT,
		SUBJECT_STATE_WALK,	
		SUBJECT_STATE_RUN
	};

	Subject(){ FUNCINFO }
	virtual ~Subject();
	
	void			Attach(Observer *observer);
	void			Detach(Observer *observer);
	void			Notify();

	SUBJECT_STATE	GetState() { FUNCINFO return m_subjectState; }
	void			SetState(SUBJECT_STATE	state){  FUNCINFO m_subjectState = state; }
protected:
	list<Observer* >	m_observers;
	SUBJECT_STATE		m_subjectState;
};

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject(){ FUNCINFO }
	~ConcreteSubject() { FUNCINFO }
};

class Observer
{
public:
	virtual void Update(Subject* subject) = 0;
	virtual ~Observer(){ FUNCINFO }
	Observer(){ FUNCINFO }
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver() : m_observerState(-1){ FUNCINFO }
	~ConcreteObserver() { FUNCINFO }
	void Update(Subject* subject);

private:
	int		m_observerState;
};

void Subject::Notify()
{
	FUNCINFO
	for(list<Observer *>::iterator itr = m_observers.begin(); 
		itr != m_observers.end(); ++itr)
	{
		(*itr)->Update(this);
	}
}

Subject::~Subject()
{
	FUNCINFO
	for(list<Observer *>::iterator itr = m_observers.begin(); 
	itr != m_observers.end();)
	{
		delete *itr;
		itr = m_observers.erase(itr);
	}
}

void Subject::Attach(Observer *observer)
{
	FUNCINFO
	m_observers.push_back(observer);
}

void Subject::Detach(Observer *observer)
{
		FUNCINFO

	list<Observer *>::iterator itr = std::find(m_observers.begin(),
		m_observers.end(),observer);

	if(itr != m_observers.end()){
		m_observers.erase(itr);
		cout<<"Detach Success"<<endl;
	}
	else{
		cout<<"Observer Not Found!"<<endl;
	}
}

void ConcreteObserver::Update(Subject *subject)
{
	FUNCINFO

	if(subject == NULL)
		return;

	m_observerState = subject->GetState();
}

int main()
{
	Observer *p1 = new ConcreteObserver;
	Observer *p2 = new ConcreteObserver;

	Subject* subject = new ConcreteSubject;
	subject->Attach(p1);
	subject->Attach(p2);
	subject->SetState(Subject::SUBJECT_STATE_WAIT);
	subject->Notify();

	subject->Detach(p1);
	subject->SetState(Subject::SUBJECT_STATE_RUN);
	subject->Notify();
	
	delete subject;
	return 0;
}