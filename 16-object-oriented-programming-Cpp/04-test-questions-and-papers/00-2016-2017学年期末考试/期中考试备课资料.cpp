#include <iostream>
using namespace std;
#define ElemType int
#define INIT_STACK_SIZE 6
#define STACKINCREMENT 3

class Stack
{
public:
	Stack();
	~Stack();
	void Push(int e);
	void Pop(int &e);
private:
	ElemType *m_base;
	ElemType *m_top;
	int m_stacksize;
};

Stack::Stack()
{
	m_base = new ElemType[INIT_STACK_SIZE];
	if (!m_base)
	{
		cout << "Init Error" << endl;
	}
	m_top = m_base;
	m_stacksize = INIT_STACK_SIZE;
}

Stack::~Stack()
{
	delete []m_base;
}

void Stack::Push(int e)
{
	if ((m_top - m_base) >= m_stacksize)//error
	{
		m_base = (ElemType*)realloc(m_base,(m_stacksize + STACKINCREMENT)*sizeof(ElemType));
		if (!m_base)
		{
			cout << "Push Error" << endl;
			return;
		}
		m_top = m_base + m_stacksize;
		m_stacksize += STACKINCREMENT;
	}
	*m_top++ = e;
}

void Stack::Pop(int &e)
{
	if (m_base == m_top)
	{
		cout << "Stack is Empty" << endl;
		e = -100;
		return;
	}
	e = * --m_top;
}

int main(void)
{

	Stack s1;
	int e = -1;
	for (int i = 0; i < 10; i++)
	{
		s1.Push(i+1);
	}
	for (int i = 0; i < 11; i++)
	{
		s1.Pop(e);
		cout << e << endl;
	}

	return 0;
}


#include <iostream>
using namespace std;
class Mouse
{
public:
	static Mouse *GetMouse();
private:
	Mouse();
	static Mouse *p;
};
Mouse *Mouse::p = NULL;
Mouse::Mouse()
{
}
Mouse *Mouse::GetMouse()
{
	if(p == NULL)
		p = new Mouse;
	return p;
}
int main(void)
{
	Mouse *p1 = Mouse::GetMouse();
	Mouse *p2 = p1->GetMouse();


	return 0;
}