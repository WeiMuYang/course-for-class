#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
	Complex(int aR = 0,int aI = 0){	m_iImag = aI;	m_iReal = aR;}
	~Complex(){}
	void display(){	cout << m_iReal<< " + " << m_iImag << "i"<< endl; }
	const Complex  operator +(const Complex & r)const
	{
		/*Complex temp;
		temp.m_iReal = m_iReal + r.m_iReal;
		temp.m_iImag = m_iImag + r.m_iImag;*/
		return Complex(m_iReal + r.m_iReal, m_iImag + r.m_iImag);
	}
	Complex & operator++() 
	{
		m_iReal++;	m_iImag++;
		return *this;
	}
	const Complex operator++(int ) 
	{
		Complex temp(*this);
		m_iReal++;	m_iImag++;
		return temp;
		
	}
private:
	int m_iReal;	int m_iImag;
};


int main(void)
{
	Complex c1(2,3),c2(1,2);
	int a = 0;int b = 99;
	Complex c3;
	//c3 = c1.operator+(c2);
	c3 = c1 + c2;
	c3.display();
	++c3 ;
	//c3++ = c1;
	++b = a;
	//b++ = a;
	cout << b << endl;
	c3.display();
	//c3.operator++(9);
	c3++;
	c3.display();
	

	return 0;
}