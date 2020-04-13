#include <iostream>
using namespace std;
class Base
{
public:
	virtual void display(int a)
	{
		cout << "Base::display()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void display(int a)
	{
		cout << "Derived::display()" << endl;
	}
};
int main(void) {
	Derived d1;
	Base b1;
	//定义基类指针
	//Base *pb = &d1;	pb->display(1);
	//pb = &b1; pb->display(9);
	//定义基类引用
	Base &rb = d1;	rb.display(9);
	rb = b1;						//只是简单的赋值
	rb.display(0);		
	Base &rb1 = b1;	rb1.display(2);	//注意引用要重新写
	


	return 0;
}

