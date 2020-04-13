#include <iostream>
using namespace std;

class A
{
public:
	A();	
	~A();
	void print() const 
	{
		cout << "const " << m_ia << endl;
	}
	void print() 
	{
		cout << m_ia << endl;
	}
	void setA(int val) 
	{
		print();
		m_ia = val;
	}
private:
	int m_ia;
};
A::A()
:m_ia(0){  }
A::~A(){}

int main(void)
{
	A a;
	const A b;
	a.print();
	//b.setA(230); //error
	b.print();
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	Student(const Student &r);
	~Student();
	static void displayCount(){	cout << s_iCount << endl;}
private:
	string m_strName;
	static int s_iCount;
};
int Student::s_iCount;
Student::Student()
{s_iCount++;}
Student::Student(const Student &r){
	m_strName = r.m_strName;	s_iCount++;}
Student::~Student()
{ s_iCount--;}


int main(void)
{
	Student stu1,stu2;
	stu1.displayCount();
	Student::displayCount();
	Student *pstu3 = new Student(stu1);
	Student::displayCount();
	delete pstu3;
	stu2.displayCount();

	return 0;
}



	//int arr0[3] = {0};
	//int (*p)[3] = &arr0;
	//int a[4][3];
	//
	//p = a;
	//int *q[4];
	//q[1] = a[1];