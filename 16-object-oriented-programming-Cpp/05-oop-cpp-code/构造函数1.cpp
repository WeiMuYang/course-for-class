#include <iostream>
#include <string>
using namespace std;


class Time
{
public:
	//Time(){}//系统自动生成构造函数
	//Time();//无参构造函数
	//Time(int =10);
	Time(int aH ,int aM ,int aS);
	void display()
	{
		cout << m_iHour << ":" << m_iMin << ":" << m_iSec << endl << m_ci<<endl << m_irSec << endl; 
	}
private:
	int m_iHour; int m_iMin; int m_iSec;
	const int m_ci;//const 成员
	int &m_irSec;  //引用成员
};

//Time::Time()
//{
//	m_iHour = 0;  m_iMin = 0;  m_iSec = 0;
//	cout << "无参构造函数" << endl;
//}
//Time::Time(int aH)
//{
//	m_iHour = aH;  m_iMin = 0;  m_iSec = 0;
//	cout << "构造函数Time_int_" << endl;
//}




//1. const成员   2、 引用成员     3、 无默认构造函数的子对象成员
Time::Time(int aH,int aM,int aS)
:m_iHour(aH),m_iMin(aM),m_iSec(aS),m_ci(aH),m_irSec(m_iSec)
{
}
class  Date
{
public:
	Date()
		:t1(12,23,17)
	{}
	void display()
	{
		t1.display();
	}
private:
	Time t1; //无默认构造函数的子对象成员
};

int main(void)
{

	Date d1;
	d1.display();
	cout << sizeof(Time) << endl;//20个字节
	

	
	/*
	Time t1(10);
	t1.display();
	Time t2 = Time(10);
	Time *pt = new Time(10,12,50);
	pt->display();

	delete pt;
	pt = NULL;*/


	/*//创建对象指针不能用malloc在堆区动态分配内存
	string *s = new string;	
	*s = "Hello";
	cout << *s << endl;
	string *ps = (string*)malloc(sizeof(string));
	*ps = "Hello";                      */

	return 0;
}
