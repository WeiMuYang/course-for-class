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
	//�������ָ��
	//Base *pb = &d1;	pb->display(1);
	//pb = &b1; pb->display(9);
	//�����������
	Base &rb = d1;	rb.display(9);
	rb = b1;						//ֻ�Ǽ򵥵ĸ�ֵ
	rb.display(0);		
	Base &rb1 = b1;	rb1.display(2);	//ע������Ҫ����д
	


	return 0;
}

