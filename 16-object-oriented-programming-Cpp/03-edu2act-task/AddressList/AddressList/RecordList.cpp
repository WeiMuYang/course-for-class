#include "RecordList.h"
#include "RecordNode.h"
#include <iostream>
using namespace std;

RecordList::RecordList()
{
	m_pHead = NULL;
    m_pTail = NULL;
    m_iLen = 0;
}

RecordList::~RecordList()
{
    RecordNode * temp = m_pHead;
    RecordNode * next = temp;
    while(next)
    {
        next = temp->getNext();
        delete temp;
        temp = next;
    }
    m_iLen = 0;
    m_pHead = NULL;
    m_pTail = NULL;
}

void RecordList::push(Record r)
{
    RecordNode * pNew = new RecordNode;
    pNew->setNext(NULL);
    pNew->setRecord(r);

    if(!m_pHead)
    {
        m_pHead = pNew;
        m_pTail = pNew;
    }
    else
    {
        m_pTail->setNext(pNew);
    }

    m_iLen++;
}

bool RecordList::remove(int i)
{
    if(i<0 || i>=m_iLen)
        return false;

    RecordNode * temp, * front;
    if(i==0)
    {
        temp = m_pHead;
        m_pHead = temp->getNext();
    }
    else
    {
        front = m_pHead;
        for(int n=1; n<i; n++)
            front = front->getNext(); 
        temp = front->getNext();
        front->setNext(temp->getNext());

        if(temp == m_pTail)
            m_pTail = front;
    }

    delete temp;
    m_iLen--;

	return true;
}
Record RecordList::at(int i)
{
    if(i<0 || i>=m_iLen)
    {
        Record t;
        return t;
    }

	RecordNode * temp = m_pHead;
    for(int n=0; n<i; n++)
        temp = temp->getNext();
    return temp->getRecord();
}

int RecordList::length()
{
    return m_iLen;
}
