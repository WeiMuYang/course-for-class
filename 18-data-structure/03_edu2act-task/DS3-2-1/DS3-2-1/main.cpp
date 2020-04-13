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
    //����һ���ն���Q
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
    //����Ԫ��eΪQ���¶���Ԫ��
{
    if(Sq->length == m)
    {
        printf("��������,��%s�ȴ���\n",e);
        return ERROR;//������
    }
    strcpy(Sq->Q[Sq->rear] , e);
    Sq->rear = (Sq->rear + 1) % m;
    Sq->length = (Sq->length + 1);
    printf("%s�ѳɹ���ӣ�\n",e);
    return OK;
}

Status EnQueue(SqQueue *Sq, QElemType e)
{
	//����Ԫ��eΪQ���µĶ�βԪ�� 
	int i;
	QElemType p;
	if (Sq -> length == m)//������ 
	{
		printf("������������%s�ȴ���\n", e);
		return ERROR;
	}
	//���⿪��һ���ڴ����洢����ַ��� 
	p = (QElemType)calloc(8, sizeof(char));
	for (i = 0; i < 7; i++)
		p[i] = e[i];
	
	Sq -> Q[Sq -> rear] = p;
	Sq -> rear = (Sq -> rear + 1) % m;
	Sq -> length++;
	printf("%s�ѳɹ���ӣ�\n", e);
	return OK;
}




Status DeQueue(SqQueue *Sq,QElemType *e)
    //�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
    //���򷵻�ERROR
{
    int front;
    if (Sq->length == 0)
    {
        printf("�޳��Ŷ�,���ܽ��복�⡣\n");
        return ERROR;
    }
    front = (Sq->rear - Sq->length + m) % m;
    strcpy(*e , Sq->Q[front]);
    Sq->length--;
    printf("%s�ѳɹ�����ֿ⣡\n",*e);
    return OK;
}

Status TraQueue(SqQueue Sq)
    //����������е�ÿ��Ԫ��
{
    int i = 0,j = 0, front = 0;
    if (Sq.length == 0) 
    {
        printf("���г���Ϊ0!\n");
        return ERROR;
    }
    front = (Sq.rear - Sq.length + m) % m;
    printf("���г���Ϊ%d��Ԫ�����£�\n",Sq.length);
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
		printf("|           1. ��  ��                        |\n");
		printf("|           2. ��  ��                        |\n");
		printf("|           3. ��  ӡ                        |\n");
        printf("|           4. ��  ��                        |\n");
		printf(" ============================================\n");
		printf("��ѡ��:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		case '1':
			printf("�����복�ƺ�:");
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
			printf("ѡ���������������ѡ��\n");
			break;
		}
		system("pause");
	}

    return 0;
}