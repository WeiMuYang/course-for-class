#include <iostream>
using namespace std;
#define ElemType int
#define INIT_STACK_SIZE 100
#define STACKINCREMENT 10
class Stack
{
public:
	Stack();
	Stack(const Stack &r);
	~Stack();
	void Push(int e);
	void Pop(int &e);

private:
	ElemType *m_base;
	ElemType *m_top;
	int m_stacksize;
};
void Stack::Pop(int &e)
{
	if (m_base == m_top)
	{
		cout << "Stack is Empty" << endl;
		return;
	}
	e =* --m_top;
}
void Stack::Push(int e)
{
	if (m_top - m_base >= m_stacksize)
	{
		m_base =(ElemType*)realloc(m_base,(m_stacksize + STACKINCREMENT)*sizeof(ElemType));
		if (!m_base)
		{
			cout << " Insert error "<< endl;	return;
		}
		m_top = m_base + m_stacksize;
		m_stacksize += STACKINCREMENT;
	}
	*m_top++ = e;
}
Stack::Stack()
{
	m_base = new ElemType[INIT_STACK_SIZE];
	if (!m_base)
	{
		cout << "Init error"<< endl;
		return;
	}
	m_top = m_base;
	m_stacksize = INIT_STACK_SIZE;
}
Stack::Stack(const Stack &r)
{
	m_base = new ElemType[r.m_stacksize];
	if (!m_base)
	{
		cout << "Copy error"<< endl;
		return;
	}
	m_top = m_base;
	ElemType *p = r.m_base;
	for (;p<r.m_top;p++)
	{
		*m_top++ = *p;
	}
	m_stacksize = r.m_stacksize;
}
Stack::~Stack()
{
	delete []m_base;
}

int main()
{
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);

	Stack S2(s1);
	int e = -110;
	S2.Pop(e);
	cout << e << endl;
	S2.Pop(e);
	cout << e << endl;
	S2.Pop(e);
	cout << e << endl;
	S2.Pop(e);
	cout << e << endl;

	return 0;
}
