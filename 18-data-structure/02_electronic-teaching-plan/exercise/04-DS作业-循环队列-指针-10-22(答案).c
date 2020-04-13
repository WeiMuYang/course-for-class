#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OVERFLOW    -2
#define OK          1
#define ERROR       0

//------------- ѭ�����С����������еĶ�̬˳��洢�ṹ -------------
#define MAXQSIZE    6	//�����г���
#define QElemType   char

typedef struct
{
	QElemType *base;	 
	int front;			 
	int rear;			 
}SqQueue;

//------------- ѭ�����л������� ---------------
// ��ʼ��
Status InitQueue(SqQueue *Q)
	//����һ���ն���Q
{
	(*Q).base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!(*Q).base)
		exit(OVERFLOW);	//�洢����ʧ��
	(*Q).front = (*Q).rear = 0;

	return OK;
}

// ��Ԫ�ظ���
int QueueLength(SqQueue Q)
	//����Q��Ԫ�ظ����������еĳ���
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

// ���
Status EnQueue(SqQueue *Q, QElemType e)
	//����Ԫ��eΪQ���µĶ�βԪ��
{
	if(((*Q).rear + 1) % MAXQSIZE == (*Q).front)	//������
		return ERROR;
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear + 1) % MAXQSIZE;

	return OK;
}

// ����
Status DeQueue(SqQueue *Q,QElemType *e)
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
	//���򷵻�ERROR
{
	if((*Q).front == (*Q).rear)
		return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1) % MAXQSIZE;

	return OK;
}

// ��ӡѭ������
void PrintSqQueue(SqQueue Q)
{
    int i;
    for (i = Q.front; i != Q.rear; i = (i + 1) % MAXQSIZE)
        printf("%c ", Q.base[i]);
    printf("\n");
}

Status DestroyQueue(SqQueue *Q){
    free((*Q).base);
    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;
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
            printf("��������, �������\n");
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
