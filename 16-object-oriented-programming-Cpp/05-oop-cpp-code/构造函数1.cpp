#include <iostream>
#include <string>
using namespace std;


class Time
{
public:
	//Time(){}//ϵͳ�Զ����ɹ��캯��
	//Time();//�޲ι��캯��
	//Time(int =10);
	Time(int aH ,int aM ,int aS);
	void display()
	{
		cout << m_iHour << ":" << m_iMin << ":" << m_iSec << endl << m_ci<<endl << m_irSec << endl; 
	}
private:
	int m_iHour; int m_iMin; int m_iSec;
	const int m_ci;//const ��Ա
	int &m_irSec;  //���ó�Ա
};

//Time::Time()
//{
//	m_iHour = 0;  m_iMin = 0;  m_iSec = 0;
//	cout << "�޲ι��캯��" << endl;
//}
//Time::Time(int aH)
//{
//	m_iHour = aH;  m_iMin = 0;  m_iSec = 0;
//	cout << "���캯��Time_int_" << endl;
//}




//1. const��Ա   2�� ���ó�Ա     3�� ��Ĭ�Ϲ��캯�����Ӷ����Ա
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
	Time t1; //��Ĭ�Ϲ��캯�����Ӷ����Ա
};

int main(void)
{

	Date d1;
	d1.display();
	cout << sizeof(Time) << endl;//20���ֽ�
	

	
	/*
	Time t1(10);
	t1.display();
	Time t2 = Time(10);
	Time *pt = new Time(10,12,50);
	pt->display();

	delete pt;
	pt = NULL;*/


	/*//��������ָ�벻����malloc�ڶ�����̬�����ڴ�
	string *s = new string;	
	*s = "Hello";
	cout << *s << endl;
	string *ps = (string*)malloc(sizeof(string));
	*ps = "Hello";                      */

	return 0;
}
