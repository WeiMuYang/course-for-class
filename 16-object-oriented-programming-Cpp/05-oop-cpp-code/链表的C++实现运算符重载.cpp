#include <iostream>
using namespace std;
class Node
{
public:
	Node();
	int m_iData;
	Node *m_Next;
};
Node::Node()
{
	m_Next = NULL;
}
class List
{
public:
	List();
	List(const List & r);
	void Push(int e);
	int &operator[](const int i);
	List &operator=(const List & r);
	void clear();
	~List();
	Node *m_Head;
	int m_iLength;
};

List::List()
{
	m_Head = new Node;
	m_iLength = 0;
}

List::~List()
{
	Node *p = m_Head;
	for (int i = 0; i < m_iLength + 1; i++)
	{
		m_Head = m_Head->m_Next;
		delete p;
		p = m_Head;
	}
}
void List::Push(int e)
{
	Node *newNode = new Node;
	newNode->m_iData = e;
	Node *p = m_Head;
	for (int i = 0; i < m_iLength; i++)
	{
		p = p->m_Next;
	}
	p->m_Next = newNode;
	m_iLength++;
}
List::List(const List & r)
{
	m_Head = new Node;
	m_iLength = 0;
	Node *p = r.m_Head;
	for (int i = 0; i < r.m_iLength; i++)
	{
		p = p->m_Next;
		Push(p->m_iData);
	}
}
void List::clear()
{
	Node *p = m_Head;
	p = p->m_Next;				//从头结点后面的节点开始清除
	for (int i = 0; i < m_iLength; i++)
	{
		Node *q = p->m_Next;
		delete p;
		p = q;
	}
	m_iLength = 0;	//链表置空
	m_Head->m_Next = NULL;
}
List &List::operator=(const List & r)
{
	clear();
	Node *p = r.m_Head;
	for (int i = 0; i < r.m_iLength; i++)
	{
		p = p->m_Next;
		Push(p->m_iData);
	}
	return *this;
}

int & List::operator[](const int i)
{
	Node *p = m_Head;
	//本链表下标从1~length 包括1和length
	if ( i < 1 || i > m_iLength)
	{
		cout << "下标越界" << endl;
		exit(1);
	}
	for (int t = 0; t < i; t++)
	{
		p = p->m_Next;
	}
	return p->m_iData;
}


int main(void)
{
	List l1;
	l1.Push(1);
	l1.Push(2);
	l1.Push(3);
	l1.Push(4);
	List l2(l1);
	l2 = l1;
	for (int i = 1; i <= l2.m_iLength; i++)
	{
		cout << l2[i]<< endl;
	}
	cout << "------------------------------\n";
	for (int i = 1; i <= l1.m_iLength; i++)
	{
		cout << l1[i]<< endl;
	}
	
	return 0;
}