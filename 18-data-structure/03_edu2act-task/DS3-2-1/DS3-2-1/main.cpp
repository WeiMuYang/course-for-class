#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   Status    int
#define   OK        1
#define   ERROR     0
#define   m         5
#define   CHARLEN   10
typedef   char*     QElemType;

typedef struct{
    QElemType Q[m];
    int length;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *Sq)
    //构造一个空队列Q
{
    int i = 0;
    for(i = 0;i < m;i++)
    {
        Sq->Q[i] = (char*)malloc(sizeof(char[10]));
        strcpy(Sq->Q[i], "");
    }
    Sq->length = Sq->rear = 0;
    return OK;
}

Status EnQueue1(SqQueue *Sq,QElemType e)
    //插入元素e为Q的新队列元素
{
    if(Sq->length == m)
    {
        printf("队列已满,请%s等待！\n",e);
        return ERROR;//队列满
    }
    strcpy(Sq->Q[Sq->rear] , e);
    Sq->rear = (Sq->rear + 1) % m;
    Sq->length = (Sq->length + 1);
    printf("%s已成功入队！\n",e);
    return OK;
}

Status EnQueue(SqQueue *Sq, QElemType e)
{
	//插入元素e为Q的新的队尾元素 
	int i;
	QElemType p;
	if (Sq -> length == m)//队列满 
	{
		printf("队列已满，请%s等待！\n", e);
		return ERROR;
	}
	//另外开辟一个内存来存储这个字符串 
	p = (QElemType)calloc(8, sizeof(char));
	for (i = 0; i < 7; i++)
		p[i] = e[i];
	
	Sq -> Q[Sq -> rear] = p;
	Sq -> rear = (Sq -> rear + 1) % m;
	Sq -> length++;
	printf("%s已成功入队！\n", e);
	return OK;
}




Status DeQueue(SqQueue *Sq,QElemType *e)
    //若队列不空，则删除Q的队头元素，用e返回其值，并返回OK
    //否则返回ERROR
{
    int front;
    if (Sq->length == 0)
    {
        printf("无车排队,不能进入车库。\n");
        return ERROR;
    }
    front = (Sq->rear - Sq->length + m) % m;
    strcpy(*e , Sq->Q[front]);
    Sq->length--;
    printf("%s已成功进入仓库！\n",*e);
    return OK;
}

Status TraQueue(SqQueue Sq)
    //遍历输出队列的每个元素
{
    int i = 0,j = 0, front = 0;
    if (Sq.length == 0) 
    {
        printf("队列长度为0!\n");
        return ERROR;
    }
    front = (Sq.rear - Sq.length + m) % m;
    printf("队列长度为%d其元素如下：\n",Sq.length);
    for(i = front;j < Sq.length; i++ )
    {
        if(i == m) i = 0;
        printf("%s\n",Sq.Q[i]);
        j++;
    }
    printf("\n");
    return OK;
}


int main(void)
{
    SqQueue Squeue;
    int i;
    char e[CHARLEN] = {0}, choice;
    char *pe = e;
    InitQueue(&Squeue);

    while(1)
	{
		system("cls");
		printf(" ============================================\n");
		printf("|           1. 排  队                        |\n");
		printf("|           2. 入  库                        |\n");
		printf("|           3. 打  印                        |\n");
        printf("|           4. 退  出                        |\n");
		printf(" ============================================\n");
		printf("请选择:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		case '1':
			printf("请输入车牌号:");
			scanf("%s",e);
			EnQueue(&Squeue,e);
			break;
		case '2':
			DeQueue(&Squeue,&pe);
            break;
		case '3':
            TraQueue(Squeue);
			break;
        case '4':
            return 0;

		default:
			printf("选择项输入错误，重新选择！\n");
			break;
		}
		system("pause");
	}

    return 0;
}