#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OVERFLOW    -2
#define OK          1
#define ERROR       0



// ------------- ��ҵҪ�� -------------   // 
// 1.����C����ʵ������6����������*.c�ļ���д����      
// 2.��ҵ��ɺ��뷢����863255386@qq.com,��������⣺04-���ݽṹ-queue-X��-����-ѧ��    
// 3.��ֹʱ��2019-10-27   
// 4.������ཻ����лл�����ϣ�    




//------------- ѭ�����С����������еĶ�̬˳��洢�ṹ -------------
#define MAXQSIZE    6	//�����г���
#define QElemType   char

typedef struct
{
	QElemType *base;	//��ʼ���Ķ�̬����洢�ռ�
	int front;			//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;			//�����в��գ�ָ�����Ԫ�ص���һ��Ԫ��
}SqQueue;

//------------- ѭ�����л������� ---------------
// ��ʼ��
Status InitQueue(SqQueue *Q)
	//����һ���ն���Q
{
 
	return OK;
}

// ��Ԫ�ظ���
int QueueLength(SqQueue Q)
	//����Q��Ԫ�ظ����������еĳ���
{
	return  ;
}

// ���
Status EnQueue(SqQueue *Q, QElemType e)
	//����Ԫ��eΪQ���µĶ�βԪ��
{
	 

	return OK;
}

// ����
Status DeQueue(SqQueue *Q,QElemType *e)
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
	//���򷵻�ERROR
{
	 
	return OK;
}

// ��ӡѭ������
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
