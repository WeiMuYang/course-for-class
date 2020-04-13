#ifndef RECORDLIST_H
#define RECORDLIST_H

#include "RecordNode.h"

class RecordList
{
public:
	RecordList();
	~RecordList();

	void push(Record r);
	bool remove(int i);
	Record at(int i);
	int length();


private:
	RecordNode * m_pHead;
    RecordNode * m_pTail;
    int m_iLen;
};




#endif