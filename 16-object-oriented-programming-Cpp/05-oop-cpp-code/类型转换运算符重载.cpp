#include <iostream>
using namespace std;
class A
{
public:
	int operator()(int a,int b)
	{
		return (a+b);
	}
	//1.��ֵ���������
	//A &operator=(const B & rb)
	//{
	//	m_ia = rb.m_ib;
	//	return *this;
	//}
	A(int a = 0){	m_ia = a;}
	//2.���캯���ķ���
	//A(const B & rb)
	//{
	//	m_ia = rb.m_ib;
	//}

	int m_ia;
};


class B
{
public:
	B(int b = 1){ m_ib = b;}
	//3.����ת�����������
	operator A()
	{
		return m_ib;
	}
	int m_ib;//����

};



int main(void)
{
	int a = 0;
	double b = 3.14;
	a = b;
	a = int(b);
	a = (int)b;
	A obja(10);
	B objb(11);
	obja = objb;
	cout << obja.m_ia << endl;
	
	obja = A(objb);
	cout << obja.m_ia << endl;
	obja = 12;
	obja = (A) objb;
	cout << obja.m_ia << endl;




	return 0;
}