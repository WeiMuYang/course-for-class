#include "Record.h"

Record::Record(string aName ,string aPhone ,string aAddress)
	:m_strName(aName),m_strPhone(aPhone),m_strAddress(aAddress)
{}

string Record::getName()
{
	return m_strName;
}

string Record::getPhone()
{
	return m_strPhone;
}

string Record::getAddress()
{
	return m_strAddress;
}


void Record::setName(string aName)
{
	m_strName = aName;
}

void Record::setPhone(string aPhone)
{
	m_strPhone = aPhone;
}

void Record::setAddress(string aAddress)
{
	m_strAddress = aAddress;
}
