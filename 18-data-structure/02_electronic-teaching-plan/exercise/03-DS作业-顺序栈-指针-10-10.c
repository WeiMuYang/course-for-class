#include <stdio.h>
#include <stdlib.h>
#define Status          int
#define OK              1
#define ERROR           0
#define OVERFLOW        -2
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  5
#define SElemType       int

// ------------- 作业要求： -------------   // 
// 1.请用C语言实现以下7个函数，用*.c文件书写编译      
// 2.作业完成后，请发送至863255386@qq.com,邮箱的主题：03-数据结构-stack-X班-姓名-学号    
// 3.截止时间2019-10-14   
// 4.有问题多交流，谢谢理解配合！    


typedef struct {
    SElemType *base;    // 在构造之前和销毁之后，base的值为NULL
    SElemType *top;     // 栈顶指针
    int stacksize;      // 当前已分配存储空间，以元素为单位
}SqStack;

//因为要修改栈S内存中数据成员的值，因此必须传递S的地址
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



