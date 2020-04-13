#include <iostream>
using namespace std;

template < typename T  = int ,int len = 10 >
class Stack
{
public:
	Stack();
	~Stack();
	void push(T e);
	T pop();
	bool isFull();
	bool isEmpty();
	int length()
	{
		return top;
	}
private:
	int top;
	T data[len];
};

template < typename T = int, int len = 10 >
Stack<T,len>::Stack()
{
	top = 0;
}

template < typename T = int, int len = 10 >
bool Stack<T,len>::isEmpty()
{
	if (top == 0)
	{
		return true;
	}
	return false;
}
template < typename T = int, int len = 10 >
bool Stack<T,len>::isFull()
{
	if (top == len)
	{
		return true;
	}
	return false;
}
template < typename T = int, int len = 10 >
void Stack<T,len>::push(T e)
{
	if (isFull())
	{
		cout << "ջ������������ջ��" << endl;
		exit(1);
	}
	data[top++] = e;
}
template < typename T = int, int len = 10 >
T Stack<T,len>::pop()
{
	if (isEmpty())
	{
		cout << "ջ�ѿգ����ܳ�ջ��" << endl;
		exit(1);
	}
	return data[--top];
}
template < typename T = int, int len = 10 >
Stack<T,len>::~Stack()
{
}

int main(void)
{
	Stack<> s;
	
	for (int i = 0;; i++)
	{
		if (s.isFull())
			break;
		s.push(i+1);
	}
	while(true)
	{
		if(s.isEmpty())
			break;
		cout << s.pop() << endl;
	}

	return 0;
}