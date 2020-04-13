#include <iostream>
using namespace std;

class mySwitch
{
public:
	static mySwitch * GetSwitch()
	{
		if (m_pSwitch == NULL)
		{
			m_pSwitch = new mySwitch;
		}
		return m_pSwitch;
	}
	bool m_OfforOn;
private:
	mySwitch(){ m_OfforOn = false;}//����ģʽ
	static mySwitch *m_pSwitch;
	
};
mySwitch *mySwitch::m_pSwitch = NULL;

class Appliance
{
public:
	virtual void Off_On() = 0;
};
class Tv :public Appliance
{
public:
	virtual void Off_On()
	{
		mySwitch *p = mySwitch::GetSwitch();
		if (p->m_OfforOn == false)
		{
			p->m_OfforOn = true;
			cout << "�����Ѿ���" << endl;
		}
		else{
			p->m_OfforOn = false;
			cout << "�����Ѿ��ر�" << endl;
		}
	}
};
class Computer :public Appliance
{
public:
	virtual void Off_On()
	{
		mySwitch *p = mySwitch::GetSwitch();
		if (p->m_OfforOn == false)
		{
			p->m_OfforOn = true;
			cout << "�����Ѿ���" << endl;
		}
		else{
			p->m_OfforOn = false;
			cout << "�����Ѿ��ر�" << endl;
		}
	}
};

int main(void)
{
	Tv objTV;
	Computer objC;
	Appliance *p = &objC;
	p->Off_On();
	p->Off_On();
	p->Off_On();
	p = &objTV;
	p->Off_On();
	p->Off_On();

	return 0;
}
