#ifndef RECORDNODE_H
#define RECORDNODE_H

#include <string>
#include "Record.h"

using namespace std;

class RecordNode
{
public:
	RecordNode();

	void setRecord(Record aR);
	void setNext(RecordNode *aN);

	Record getRecord();
	RecordNode * getNext();

private:
	Record m_RecData;
	RecordNode * m_Next;
};












#endif