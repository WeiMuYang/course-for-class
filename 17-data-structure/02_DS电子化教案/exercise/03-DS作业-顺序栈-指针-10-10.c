#include <stdio.h>
#include <stdlib.h>
#define Status          int
#define OK              1
#define ERROR           0
#define OVERFLOW        -2
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  5
#define SElemType       int

// ------------- ��ҵҪ�� -------------   // 
// 1.����C����ʵ������7����������*.c�ļ���д����      
// 2.��ҵ��ɺ��뷢����863255386@qq.com,��������⣺03-���ݽṹ-stack-X��-����-ѧ��    
// 3.��ֹʱ��2019-10-14   
// 4.������ཻ����лл�����ϣ�    


typedef struct {
    SElemType *base;    // �ڹ���֮ǰ������֮��base��ֵΪNULL
    SElemType *top;     // ջ��ָ��
    int stacksize;      // ��ǰ�ѷ���洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//��ΪҪ�޸�ջS�ڴ������ݳ�Ա��ֵ����˱��봫��S�ĵ�ַ
Status InitStack(SqStack *S)
{
    
    return OK;
}

Status GetTop(SqStack S,SElemType *e){
   
    return OK;
}

Status Push(SqStack *S,SElemType e){
   
    return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
   
    return OK;
}


void ClearStack(SqStack *S)
{
    
}

void DestroyStack(SqStack *S)
{
    
}

void PrintStack(SqStack S)
{
    
}

int main(void)
{
    SqStack s;
    int e,i,stats = 0;
    InitStack(&s);
    Push(&s,11);
    Push(&s,22);
    Push(&s,33);
    Push(&s,44);
    Push(&s,55);

    PrintStack(s);

    for (i = 1; i <= 6; i++)
    {
        stats = Pop(&s,&e);
        if (stats)
            printf("e = %d\n",e);
    }

    DestroyStack(&s);

    return 0;
}



