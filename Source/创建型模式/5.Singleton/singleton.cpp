/** 	
����Singletonģʽ��ʵ��
����File		:singleton.cpp 
����Author		:singmelody 
����Date		:2012.11.19
*/
#include <iostream>
using namespace std;

template <class T>
class Singleton
{
public:
    static inline T& getInstance()
    {
        static T _instance;
        return _instance;
    }
protected:
    Singleton() {}
    ~Singleton() {}
    Singleton( const Singleton< T >& );
    Singleton< T >& operator= ( const Singleton< T > & );
}; 


class Test : public Singleton<Test>
{
public:
	void echo()
	{
		cout<<__FUNCTION__<<endl;
	}
};

int main()
{
	Test::getInstance().echo();
	return 0;
}