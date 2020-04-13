#include <iostream>
using namespace std;
class Base
{
public:
	Base(int a = 0){	m_iBase = a;}
	virtual void display()
	{
		cout << "Base Element::" << m_iBase << endl;
	}
private:
	int m_iBase;
};

class Derived:public Base
{
public:
	Derived(int a = 11){	m_iDerived = a;}
	void display()
	{
		cout << "Derived Element::" << m_iDerived<< endl;
	}
private:
	int m_iDerived;
};

int main(void)
{
	Base b1;	Derived d1;
	Base *pb = &b1;
	Derived *pd = &d1;
	pb->display();
	pb = &d1;
	pb->display();
	//pd->display();
	//pd->Base::display();
	//pb->Derived::display(); //error
	

	return 0;
}
