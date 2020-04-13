#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(string aName,bool aSex,int aAge);
	~Person();
	void displayP()
	{
		cout << m_strName << " "<< (m_bSex?"男":"女") << " "
			<<m_iAge << endl;
	}
	
	bool m_bSex;
	string m_strName;
	int m_iAge;
};
Person::Person(string aName ,bool aSex ,int aAge )
{
	m_strName = aName;	m_bSex = aSex;	m_iAge = aAge;
	cout << "Person" << endl;
}
Person::~Person()
{
	cout << "-Person\n";
}

class Teacher: public Person
{
public:
	Teacher(string aName,bool aSex,int aAge,
		string aAddress,string aMajor,int aSalary);
	~Teacher();
	void dispalyT()
	{

		cout << "displayT------------------Start \n";
		displayP();
		cout << m_strAddress << " "<< m_strMajor << " " 
			<< m_iSalary << endl;
		cout << "displayT------------------End \n";
	}
	string m_strAddress;
	string m_strMajor;
	int m_iSalary;
	/*double m_iAge;*/
};

Teacher::Teacher(string aName,bool aSex,int aAge,
				 string aAddress,string aMajor,int aSalary)
				 :Person(aName,aSex,aAge),m_strAddress(aAddress),
				 m_strMajor(aMajor),m_iSalary(aSalary)
{
	//Person(aName,aSex,aAge);//ERROR
	//m_strName = aName;
	//m_iAge = aAge;
	//m_bSex = aSex;//OK
	cout << "Teacher\n";
}


Teacher::~Teacher()
{
	cout << "-Teacher" << endl;
}

int main(void)
{
	Teacher t1("杨老师",true,27,"501","C++",1000);
	Person p1("杨老师",0,27);
	t1.dispalyT();
	t1.displayP();
	p1.displayP();
	cout << sizeof(string) << endl;
	cout << sizeof(t1) << endl;
	cout << sizeof(p1) << endl;

	return 0;
}