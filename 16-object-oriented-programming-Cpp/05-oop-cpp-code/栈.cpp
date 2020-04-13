#include <iostream>
using namespace std;
#define SElemType int
#define Status int
#define STACK_INIT_SIZE 30
#define STACKINCREMENT 5


typedef struct{
	SElemType *base1;
	SElemType *base2;
	SElemType *top1;
	SElemType *top2;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S)
//构造一个空栈
{
	S.base1 = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base1) {cout << "初始化失败" << endl; return 0;}	//存储分配失败
	S.top1 = S.base1;
	S.stacksize = STACK_INIT_SIZE;
	S.base2 = S.base1 + S.stacksize - 1;
	S.top2 = S.base2;
}


Status Push(SqStack &S, SElemType e, int TopType)
{
	int stacksize1 = S.top1 - S.base1;
	int stacksize2 = S.base2 - S.top2;
	if (((S.top1 - S.base1) + (S.base2 - S.top2)) >= S.stacksize)// S.top1 - 1 = S.top2
	{
		S.base1 = (SElemType *)realloc(S.base1, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base1)	{ cout << "分配失败" << endl; return 0;}
		S.top1 = S.base1 + stacksize1;
		S.stacksize += STACKINCREMENT;
		int *temp = S.base2;
		S.base2 = S.base1 + S.stacksize - 1;
		for (int i = 0; i < stacksize2; i++)
		{
			*(S.base2 - i) = *temp;
			temp--;
		}
		S.top2 = S.top2 + STACKINCREMENT;
	}
	if (TopType == 1)
	{
		*S.top1++ = e;
	}
	else if (TopType == 2)
	{
		*S.top2-- = e;
	}
	else
	{
		return 0;
	}
	return 1;
}

Status Pop(SqStack &S, SElemType &e, int TopType)
{
	if (TopType == 1)
	{
		if (S.base1 == S.top1) { cout << "栈1为空" << endl; return 0;}
		e = *--S.top1;
		*S.top1 = -1;
		return 1;
	}
	else if (TopType == 2)
	{
		if (S.base2 == S.top2) { cout << "栈2为空" << endl; return 0;}
		e = *++S.top2;
		*S.top2 = -2;
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void){
	SqStack stack;
	InitStack(stack);
	cout << stack.base1 - stack.base2 << endl;
	for (int i = 0; i < 11; i++)
	{
		int type = (i % 2) + 1;
		Push(stack, i, type);
	}
	cout << "栈1的元素："<< endl;
	for (int * p = stack.base1; p < stack.top1; p++)
	{
		cout << *p << endl;
	}
	cout << "栈2的元素："<< endl;
	for (int * p = stack.top2 +1; p <= stack.base2; p++)
	{
		cout << *p << endl;
	}


	for (int i = 0; i < 11; i++)
	{
		int type = (i % 2) + 1;
		int e;
 		Pop(stack, e, type);
	}

	return 0;
}
