#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define OVERFLOW    -2 


//���Ķѷ���洢��ʾ
typedef struct {
	char *ch;	//���Ƿǿմ����򰴴�������洢��������chΪNULL
	int length;	//������
}HString;

Status StrAssign(HString *T,char *chars)
{
	//����һ����ֵ���ڴ�����chars�Ĵ�T
	int i,j;
	char *c;
	if((*T).ch)
		free((*T).ch);
	for (i = 0,c = chars; *c; ++i,++c)   ;   
	if(!i)
	{
		(*T).ch = NULL;
		(*T).length = 0;
	}
	else
	{
		if(!((*T).ch = (char*)malloc(i * sizeof(char))))
			exit(OVERFLOW);
		for (j = 0; j < i; ++j)
			(*T).ch[j] = chars[j];
		(*T).length = i;
	}
	return OK;
}

int StrCompare(HString S,HString T)
	//��S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0
{
	int i;
	for (i = 0; i < S.length && i < T.length; ++i)
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];

	return S.length - T.length;
}

Status SubString(HString *Sub,HString S,int pos,int len)
{
	int i;
	if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	if(Sub->ch)
		free(Sub->ch);
	if(!len)
	{
		Sub->ch = NULL;
		Sub->length = 0;
	}
	else
	{
		if(!(Sub->ch = (char *)malloc(len * sizeof(char))))
		{
			printf("ERROR!\n");
			exit(OVERFLOW);
		}
		for (i = 0; i < len; i++)
			Sub->ch[i] = S.ch[pos + i - 1];	//����
		Sub->length = len;
	}
	return OK;
}

void PrintStr(HString S)
{
	int i;
	for ( i = 0; i < S.length; i++)
		printf("%c",S.ch[i]);
	printf("\n");
}
//����S���Ƿ�����T��ͬ���Ӵ����еĻ���ɾ��
Status Strfun(HString *S,HString T)
{
    int m, n, pos = 1, k;
    HString Sub;
    Sub.ch = NULL;
    n = S->length;
    m = T.length;
    while (pos < n - m + 1)
    {
        SubString(&Sub, *S, pos, m);
        if(StrCompare(Sub, T) != 0)
            ++pos;
        else
        {
            for(k = pos-1; k <= S->length - pos + T.length + 1; ++k)
                (*S).ch[k] = (*S).ch[k + T.length]; 
            S->length -= T.length;
            S->ch = (char*)realloc(S->ch, S->length);
           if(!S->ch)
               exit(OVERFLOW);
           return ERROR;
        }
    }
    return OK;
}

int main(void)
{
	HString S ,T;
    S.ch = T.ch = NULL;
	StrAssign(&S ,"abcFGdeFGHiGH");
	PrintStr(S);

	StrAssign(&T ,"FGH");
	PrintStr(T);

    Strfun(&S,T);
	PrintStr(S);

	return 0;
}