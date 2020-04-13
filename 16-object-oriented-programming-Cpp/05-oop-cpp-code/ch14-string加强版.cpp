#define   _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class CString
{
public:
	CString(const char * const p = "ABC"){
		m_p = new char[strlen(p) + 1];
		strcpy(m_p, p);
	}
	~CString()
	{
		delete[]m_p;
	}
	CString(const CString &r){
		m_p = new char[strlen(r.m_p) + 1];
		strcpy(m_p, r.m_p);
	}
	CString & operator=(const CString &r)
	{
		delete[]m_p;
		m_p = new char[strlen(r.m_p) + 1];
		strcpy(m_p, r.m_p);
		return *this;
	}
	bool operator==(const CString &r)const
	{
		return strcmp(m_p, r.m_p) ? false : true;
	}
	const CString operator+(const CString & r)const
	{
		CString temp;
		delete[]temp.m_p;
		temp.m_p = new char[strlen(m_p) + strlen(r.m_p) + 1];
		strcpy(temp.m_p, m_p);
		strcat(temp.m_p, r.m_p);
		return temp;
	}
	void display()
	{
		cout << m_p << endl;
	}
private:
	char * m_p;
};



int main(void)
{
	CString s1("Hello");
	CString s2(s1);
	s2.display();
	CString s3;
	s3 = s1 + s2;
	s3.display();
	return 0;
}