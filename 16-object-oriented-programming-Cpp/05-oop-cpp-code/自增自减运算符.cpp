#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(int aR = 0,int aI = 0);
	const Complex operator-(const Complex &r)const
	{
		Complex temp(m_iReal - r.m_iReal,m_iImag - r.m_iImag);
		return temp;
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
	void display()
	{
		cout << m_iReal << " + " << m_iImag << "i\n";
	}
private:
	int m_iReal;	int m_iImag;
};

Complex::Complex(int aR,int aI)
{
	m_iReal = aR;	m_iImag = aI;
}
int main(void)
{
	Complex c1(1,2),c2;

	(++c1) = c2;
	c1.display();
	
	

	return 0;
}