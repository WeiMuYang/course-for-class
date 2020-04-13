#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OVERFLOW    -2
#define OK          1
#define ERROR       0



// ------------- 作业要求： -------------   // 
// 1.请用C语言实现以下6个函数，用*.c文件书写编译      
// 2.作业完成后，请发送至863255386@qq.com,邮箱的主题：04-数据结构-queue-X班-姓名-学号    
// 3.截止时间2019-10-27   
// 4.有问题多交流，谢谢理解配合！    




//------------- 循环队列————队列的动态顺序存储结构 -------------
#define MAXQSIZE    6	//最大队列长度
#define QElemType   char

typedef struct
{
	QElemType *base;	//初始化的动态分配存储空间
	int front;			//头指针，若队列不空，指向队列头元素
	int rear;			//若队列不空，指向队列元素的下一个元素
}SqQueue;

//------------- 循环队列基本操作 ---------------
// 初始化
Status InitQueue(SqQueue *Q)
	//构造一个空队列Q
{
 
	return OK;
}

// 求元素个数
int QueueLength(SqQueue Q)
	//返回Q的元素个数，即队列的长度
{
	return  ;
}

// 入队
Status EnQueue(SqQueue *Q, QElemType e)
	//插入元素e为Q的新的队尾元素
{
	 

	return OK;
}

// 出队
Status DeQueue(SqQueue *Q,QElemType *e)
	//若队列不空，则删除Q的对头元素，用e返回其值，并返回OK
	//否则返回ERROR
{
	 
	return OK;
}

// 打印循环队列
void PrintSqQueue(SqQueue Q)
{
    
   
}

Status DestroyQueue(SqQueue *Q){
    
    return OK;
}




int main(void)
{
    SqQueue Q;
    int i;	
    QElemType e = 'A';
    InitQueue(&Q);
    for (i = 0; i < 7; i++){
        if(!EnQueue(&Q, e++))
            printf("队列已满, 不能入队\n");
    }
    PrintSqQueue(Q);

    DeQueue(&Q, &e);
    PrintSqQueue(Q);
    e = 'w';
    EnQueue(&Q, e );
    PrintSqQueue(Q);
    DeQueue(&Q, &e);
    DeQueue(&Q, &e);
    PrintSqQueue(Q);
    e = 'x';
    EnQueue(&Q, e++ );
    EnQueue(&Q, e++ );
    EnQueue(&Q, e++ );
    PrintSqQueue(Q);
    return 0;
}
