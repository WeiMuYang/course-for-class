#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >>n;
	string *p = new string[n];
	for(int i = 0; i < n; i++)
	{
		cin>> p[i];
	}
for(int i = n-1; i >=0; i--)
	{
		cout<< p[i];
	}
	delete []p;
return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Point{
public:
	int X;	int Y;
};
class Rectangle{
public:
	Rectangle(Point ap1,Point ap2){
		P1 = ap1;		P2 = ap2;
	}
	Point P1;//вСоб	
	Point P2;//срио
	void printArea()
	{
		double a = (P2.X-P1.X)*(P2.Y-P1.Y);
		cout << a << endl;
	}
};

int main(void)
{
	Point p1,p2;
	p1.X = 1;	p1.Y = 1;
	p2.X = 2;	p2.Y = 4;
	Rectangle r(p1,p2);
	r.printArea();

}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString{
public:
	MyString(const char * const p = ""){
	m_p = new char[strlen(p)+1];
	strcpy(m_p,p);
	}
	~MyString()	{delete []m_p;}
	MyString(const MyString &r){
	m_p = new char[strlen(r.m_p)+1];
	strcpy(m_p,r.m_p);
	}
	void display()
	{
		cout << m_p << endl;
	}
private:
	char *m_p;
};

int main(void)
{
	MyString s("Hello");
	s.display();
	MyString s1(s);
	s1.display();

	return 0;
}