#include <iostream>
using namespace std;

class Time
{
public:
	/*Time(){}*/
	Time(int aH ,int aM = 15,int aS = 23)
		:m_iHour(aH),m_iMin(aM),m_iSec(aS){}
	void display()
	{
		cout << m_iHour <<":" <<  m_iMin <<":"<< m_iSec <<endl;
	}
private:
	int m_iHour; int m_iMin; int m_iSec;
	
};
class Date
{
public:
	Date();
	void display()
	{
		t1.display();
	}
private:
	Time t1;
};

Date::Date()
	:t1(12)
{
	Time temp(13);
	t1 = temp;
}




int main(void)
{
	Time t1(12);
	t1.display();
	Date d1;
	d1.display();
	return 0;
}