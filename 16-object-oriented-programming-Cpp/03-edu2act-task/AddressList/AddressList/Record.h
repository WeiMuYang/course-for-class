#ifndef RECORD_H
#define RECORD_H

#include <string>

using namespace std;

class Record
{
public:
	Record(string aName = "" ,string aPhone = "",string aAddress ="" );

	void setName(string aName);
	void setPhone(string aPhone);
	void setAddress(string aAddress);

	string getName();
	string getPhone();
	string getAddress();

private:
	string m_strName;
	string m_strPhone;
	string m_strAddress;
};

#endif