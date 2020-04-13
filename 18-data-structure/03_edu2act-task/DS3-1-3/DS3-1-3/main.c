#include <stdio.h>
#include <stdlib.h>
#define OK              1
#define ERROR           0
#define Status          int
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  5
#define ElemType        char



typedef struct {
	ElemType *base;
	int top;
	int stacksize;
}SqStack;

//因为要修改栈S内存中数据成员的值，因此必须传递S的地址
Status InitStack(SqStack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!S->base)
	{
		printf("初始化失败！\n");
		return ERROR;
	}
	S->top = 0;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status push(SqStack *S,ElemType e)
{
	if (S->top + 1 >= S->stacksize)
	{
		S->base = (ElemType *)realloc(S->base,S->stacksize+STACKINCREMENT);
		if (!S->base)
		{
			printf("追加失败!\n");
			return ERROR;
		}
		// S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
    S->base[S->top++] = e;

	return OK;
}

Status pop(SqStack *S,ElemType *e)
{
	if (S->top == 0)
	{
		printf("出栈失败，栈为空!\n");
		return ERROR;
	}
	*e = S->base[--S->top]; 
    //*e = *--S->top;
	return OK;
}

Status matchBracket(SqStack *S,ElemType *str)
{
	int i = 0;
	ElemType e = NULL;
	ElemType *p;
	InitStack(S);
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<')
			push(S,str[i]);
		else if(str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>')
		{
			if (!S->top)
			{
				printf("右括号太多，匹配失败！\n");
				return ERROR;
			}
			if( S->base[S->top-1] + 1 == str[i] || S->base[S->top-1] + 2 == str[i])
			{
				pop(S,&e);
				//printf("%c\n",e);
			}else
			{
				printf("匹配错误，有左括号没遇到与之对应的右括号！\n");
				return ERROR;
			}
		}
		i++;
	}
	if (!S->top)
	{
		printf("括号匹配成功！\n");
		return OK;
	}
	else
	{
		printf("左括号太多，匹配失败！\n");
		return ERROR;
	}
}

// {[(q)(a)]}<(s)> 
// {[(q)(a)]}<(s) 
// {[(q)(a]]}<(s)>  
// {[(q)(a)]}<(s)>w)
int main(void)
{
	SqStack s;
	ElemType e;
	char str[20];
    printf("请输入需要判断的字符串：");
    scanf("%s",str);
	matchBracket(&s,str);

	return 0;
}