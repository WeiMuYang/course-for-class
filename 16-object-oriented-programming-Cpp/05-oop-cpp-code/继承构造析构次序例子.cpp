#include <iostream>
using namespace std;


class A
{
public:
	A(){	cout << "A" << endl;}
	~A(){	cout << "-A" << endl;}
private:
	int m_ia;
};
class B:public A
{
public:
	B(){	cout << "B" << endl;}
	~B(){	cout << "-B" << endl;}
	A m_a;
	int m_ib;
};
class C: public B,public A
{
public:
	C(){	cout << "C" << endl;}
	~C(){	cout << "-C" << endl;}
	int m_ic;
};
int main(void)
{
	C c;
	c.m_ib;
	/*c.m_ia;*///error

	cout << sizeof(c) << endl;

	return 0;
}