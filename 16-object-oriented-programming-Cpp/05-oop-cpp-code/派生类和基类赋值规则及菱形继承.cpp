#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	A(){val = 1; cout << "A" << endl;}
	~A(){cout << "-A" << endl;}
	void display()
	{
		cout << "displayA()" << endl;
	}
	void display(int a)
	{
		cout << "displayA()" << endl;
	}
	int val;
};
class B:public A
{
public:
	B(){val = 2; cout << "B" << endl;}
	~B(){cout << "-B" << endl;}
	void display()
	{
		cout << "displayB()" << endl;
	}
	int val;
};
class C:public A
{
public:
	C(){val = 3; cout << "C" << endl;}
	~C(){cout << "-C" << endl;}
	int val;
};
class D:public B,public C
{
public:
	D(){val = 4; cout << "D" << endl;}
	~D(){cout << "-D" << endl;}
	int val;
};



int main(void)
{
	B b;
	cout << b.val << endl;
	cout << b.A::val << endl;
	b.display();

	D d;	D *p = &d;
	cout << d.val << endl;

	cout << d.B::val << endl;
	cout << d.C::val << endl;
	cout << p->C::A::val << endl;
	cout << p->B::A::val << endl;
	cout << p->B::A::val << endl;
	

	return 0;
}