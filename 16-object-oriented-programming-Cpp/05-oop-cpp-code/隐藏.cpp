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
	//1.���������ֱ�ӷ��ʵ������ͬ���������ĸ���  ֻ���Ǻ������������βα�����ֵ
	d1.display(1, 2);	d1.display(9,2);
	//Derived *pd = &b1;//error
	Derived *pd = &d1;	pd->display(1, 2);
	Derived &rd = d1;	rd.display(1, 2);
	//2.�����������η��ʵ������ͬ������������������   ���� ��������ָ��
	d1.Base::display(9);	pd->Base::display(9);   rd.Base::display(0);
	Base *pb = &d1;		pb->display(1);
	Base &rb = d1;		rb.display(1);
	//3.����û��������������ͬ��������������ֱ�ӷ��ʵ���



	return 0;
}


