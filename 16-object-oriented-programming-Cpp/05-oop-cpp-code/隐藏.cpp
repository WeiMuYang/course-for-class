#include <iostream>
using namespace std;
class Base
{
public:
	void display(int a)
	{
		cout << "Base::display(int)" << endl;
	}
};

class Derived :public Base
{
public:
	void display(int a, int b)
	{
		cout << "Derived::display(int int)" << endl;
	}
};

int main(void) {
	Base b1;
	Derived d1;
	//1.派生类对象直接访问的与基类同名函数是哪个？  只考虑函数名，不看形参表，返回值
	d1.display(1, 2);	d1.display(9,2);
	//Derived *pd = &b1;//error
	Derived *pd = &d1;	pd->display(1, 2);
	Derived &rd = d1;	rd.display(1, 2);
	//2.派生类对象如何访问到基类的同名函数？基类名：：   或者 借助基类指针
	d1.Base::display(9);	pd->Base::display(9);   rd.Base::display(0);
	Base *pb = &d1;		pb->display(1);
	Base &rb = d1;		rb.display(1);
	//3.除非没有派生类与基类的同名函数，否则不能直接访问到。



	return 0;
}


