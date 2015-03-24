/** 	
　　Facade 模式的实现
　　File		:factory.cpp 
　　Author		:singmelody 
　　Date		:2012.11.18
*/
#include <iostream>
using namespace std;

class CPU
{
public:
	void freeze() { cout<<__FUNCTION__<<endl; }
	void jump(long position) {  cout<<__FUNCTION__<<endl; }
	void execute() { cout<<__FUNCTION__<<endl; }
};

class Memory {
public :
	void load(long position, char  data[]) { cout<<__FUNCTION__<<endl; }
};

class HardDrive {
public:
	void read(long lba, int size) { cout<<__FUNCTION__<<endl; }
};

class Facade
{
private:
	CPU*		cpu;
	Memory*		memory;
	HardDrive*	hardDrive;

public:
	void Compute()
	{
		cpu = new CPU();
        memory = new Memory();
        hardDrive = new HardDrive();
	}

	void startComputer() {
        cpu->freeze();
        memory->load(0,"hello");
        cpu->jump(0);
        cpu->execute();
    }
};

int main()
{
	Facade* facade = new Facade;
	facade->startComputer();
	return 0;
}