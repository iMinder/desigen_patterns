/** 	
　　Proxy模式的实现
　　File		:proxy.cpp 
　　Author		:singmelody 
　　Date		:2012.11.22
*/
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;

class Subject
{
public:
	Subject() { FUNCINFO; }
	virtual ~Subject() { FUNCINFO; }

	virtual void Request() = 0;
};

class RealSubject : public Subject
{
public:
	RealSubject() { FUNCINFO; }
	~RealSubject() { FUNCINFO; }

	void Request() { FUNCINFO; }
};

class Proxy : public Subject
{
public:
	Proxy():m_realSubject(NULL) { FUNCINFO; }
	~Proxy() { FUNCINFO; delete m_realSubject; }

	virtual void Request()
	{
		FUNCINFO;
		if(m_realSubject == NULL)
		{
			m_realSubject = new RealSubject();
		}
		m_realSubject->Request();
	}
private:
	Subject* m_realSubject;
};

int main()
{
	Proxy * proxy = new Proxy();
	proxy->Request();

	delete proxy;
	return 0;
}