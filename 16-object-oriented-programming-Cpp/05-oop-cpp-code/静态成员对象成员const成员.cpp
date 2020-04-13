#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(string aN = "Ä³Ä³Ä³")
	{		
		m_strName = aN;
		s_iCount++;
		cout  << m_strName << s_iCount << endl;
	}
	Student(const Student &r)
	{
		m_strName = r.m_strName;
		s_iCount++;
		cout  << m_strName << s_iCount << endl;
	}
	~Student()
	{
		cout << "-" << m_strName << s_iCount << endl;
		s_iCount--;
	}
	static void display();

private:
	string m_strName;
	static int s_iCount;
};

void Student::display()
{
	cout << "Number = " << s_iCount << endl;
}

int Student::s_iCount;

int main(void)
{
	Student s1("A"),s2("B");
	Student *pstu = new Student("C");
	Student::display();
	Student s3(s1);
	Student::display();

	delete pstu;//²»Òª¶ª
	return 0;
}
