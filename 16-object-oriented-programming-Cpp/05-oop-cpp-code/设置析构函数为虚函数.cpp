#include <iostream>
using namespace std;
class Base
{
public:
	~Base() 
	{	cout << "~Base() "	<< endl;}
};

class Derived :public Base
{
public:
	Derived() {	m_p = new char[1000];}
	~Derived() {	delete[] m_p;
	cout << "~Derived()"<< endl;}
private:
	char* m_p;
};
int main(void) {

	//������ָ��ָ�����������Ķ���ʱ����delete ����ָ��ʱ������������������������,�����ڴ�й©
	
	/*Base *bp = new Derived;
	delete bp;*/

	//������ָ��ָ��ջ��������Ķ���ʱ�������������ں���ִ�����ʱ��ϵͳ�Զ��ͷ�ջ�������ȵ������������������ٵ��û�������
	Derived d1;
	Base *bp = &d1;//ok
	
	return 0;
}