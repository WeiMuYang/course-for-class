#include <iostream>
using namespace std;
class Base
{
public:
	~Base() 
	{	cout << "~Base() "	<< endl;}
};

class Derived :public Base
{
public:
	Derived() {	m_p = new char[1000];}
	~Derived() {	delete[] m_p;
	cout << "~Derived()"<< endl;}
private:
	char* m_p;
};
int main(void) {

	//当基类指针指向堆区派生类的对象时，在delete 基类指针时，不会调用派生类的析构函数,产生内存泄漏
	
	/*Base *bp = new Derived;
	delete bp;*/

	//当基类指针指向栈区派生类的对象时，当派生类所在函数执行完毕时，系统自动释放栈区对象，先调用派生类析构函数再调用基类析构
	Derived d1;
	Base *bp = &d1;//ok
	
	return 0;
}