#include "RecordNode.h"

RecordNode::RecordNode()
{
	m_Next = NULL;
}

Record RecordNode::getRecord()
{
	return m_RecData;
}
RecordNode * RecordNode::getNext()
{
	return m_Next;
}

void RecordNode::setRecord(Record aR)
{
	m_RecData = aR;
}
void RecordNode::setNext(RecordNode *aN)
{
	m_Next = aN;
}



