#include <stdio.h>
#include <stdlib.h>
#define Status           int
#define OK              1
#define ERROR           0
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  5
#define ElemType        int

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

 
Status InitStack(SqStack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!S->base)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return ERROR;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status JudgRepetition(SqStack *S,ElemType e)
{
	ElemType *p = S->top - 1;
    while (p >= S->base) {
        if(e == *p) {
            printf("%dΪ�ظ�Ԫ�ز��ɲ���!\n", e);
            return ERROR;
        }
        --p;
    }
	return OK;
}

Status Push(SqStack *S,ElemType e)
{
    if(!JudgRepetition(S, e))
        return ERROR;
	if ((S->top - S->base) >= S->stacksize)
	{
		S->base = (ElemType *)realloc(S->base,S->stacksize+STACKINCREMENT);
		if (!S->base)
		{
			printf("׷��ʧ��!\n");
			return ERROR;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}



void PrintStack(SqStack S)
{
	ElemType *p = S.base;
	while(p < S.top)
	{
	
		printf("%d ",(*(p)));
		++p;
	}
	printf("\n");
}

int main(void)
{
	SqStack s;
    ElemType *p = NULL;
	InitStack(&s);
	Push(&s,11);
	Push(&s,22);
	Push(&s,3);
	Push(&s,22);
	Push(&s,5);
    Push(&s,5);
    PrintStack(s);

	return 0;
}