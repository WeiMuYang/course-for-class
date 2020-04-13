#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(int age = 0){	m_iAge = age;}
	~Person(){}
	int m_iAge;
};

class Teacher:public Person	//不要丢了
{
public:
	Teacher(int salary = 100){	m_iSalary = salary;}
	~Teacher(){}
	int m_iSalary;
};

int main(void)
{
	Person p1(10);
	Teacher t1(1000);
	p1 = t1;
	cout << p1.m_iAge << endl;//	0
	//t1 = p1;	//error
	Person &rp = t1;
	cout << rp.m_iAge << endl;//	0
	Person *pp = &t1;
	cout << pp->m_iAge << endl;//	0
	Teacher *pt = (Teacher *)&p1;
	cout << pt->m_iSalary << endl;//	随机数
	//Teacher &rt = (Teacher)p1;	//error
	Teacher &rt = *(Teacher*)(&p1); //OK
	cout << rt.m_iSalary << endl;//	随机数
	Teacher *pt1 = (Teacher *)&rp;
	cout << pt1->m_iSalary << endl;//1000

	return 0;
}