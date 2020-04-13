#include <iostream>
using namespace std;
class MyString
{
public:
	MyString(int al = 0,const char *const ap = "China");
	MyString(const MyString &temp);
	~MyString();
	void display() const;
private:

	char *m_pstr;
};

MyString::MyString(int al,const char* const ap )
{

	m_pstr = new char[strlen(ap) + 1];
    strcpy(m_pstr, ap);
	cout<< "构造"  << endl;
}

MyString::MyString(const MyString &r)
{
	if (r.m_pstr)
	{
		m_pstr = new char[strlen(r.m_pstr)+1];
		strcpy(m_pstr,r.m_pstr);
	}
	else
	{
		m_pstr = NULL;
	}

	cout<< "拷贝构造" << endl;
}





//MyString::MyString(const MyString &temp)
//{
//  if(temp.m_pstr)
//  {
//      m_pstr = new char[strlen(temp.m_pstr)+1];
//      strcpy(m_pstr, temp.m_pstr);
//   }
//   else m_pstr = 0;
//   m_iLength = temp.m_iLength;
//   cout<< "拷贝构造" << m_iLength << endl;
//}



MyString::~MyString()
{
	delete []m_pstr;
	cout << "析构"  << endl;
}
void MyString::display() const 
{
	cout << m_pstr << endl;
}

void fun(char * p)
{ 
	*p = 'b';
}

int main(void)
{
	//fun("abc");
	MyString str1(1);   
	MyString str2(str1);
	//MyString str3 = str2;  //error
	MyString str4;
	


	return 0;
}