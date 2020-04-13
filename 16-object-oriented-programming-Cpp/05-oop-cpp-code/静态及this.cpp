#include <iostream>
using namespace std;

class A {
public:A(int a = 10)	 { m_ia = m_ib = a; cout << this << endl; }
       ~A()	 {  }
	   A& setA(int a) { this->m_ia = a; return *this;}
	   A& setB(int a) { this->m_ib = a; return *this;}
	   void display()	{cout << this->m_ia << endl;cout << this->m_ib << endl;
						 cout << this->s << endl;}
	   int getA()		{	return this->m_ia;}

private:
	int m_ia;	int m_ib;
	static int  s;
};
int A::s;
int main(void)
{
	
	A a;
	a.setA(2).setB(9).display();
	
	

	return 0;
}

