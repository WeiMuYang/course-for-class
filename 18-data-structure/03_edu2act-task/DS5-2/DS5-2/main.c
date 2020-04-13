#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define MAXSIZE 12500

typedef struct{
	int i,j;		//����������
	int e;			//Ԫ��ֵ
}Triple;

typedef struct{
	Triple data[MAXSIZE + 1];	//�����з���Ԫ��Ԫ���data[0]δ��
	int mu,nu,tu;				//����������������ͷ���Ԫ����
	//��Ϊdata����ֻ֪����Ԫ��˳��������MAXSIZE������֪����Ԫ��˳���ĳ���
}TSMatrix;


Status JudgingSymmetricMatrix(TSMatrix M)
{
    int p, q;
    if(M.mu != M.nu)
        return 0;
    for (p = 1; p <= M.tu; p++)
    {
        for (q = 1; q <= M.tu; q++)
        {
            if(M.data[p].i == M.data[q].j 
                && M.data[p].j == M.data[q].i )
                if(M.data[p].e != M.data[q].e)
                    return ERROR;
                else
                    break;
        }
        if(q > M.tu)
            return ERROR;
    }

    return OK;
}

void PrintMatrix(TSMatrix M)
{
    int i, j, p = 1;
    for(i = 1; i <= M.mu; i++)
    {
        for(j = 1; j <= M.nu; j++)
        {
            if(i == M.data[p].i && j == M.data[p].j)
                printf("%5d", M.data[p++].e);
            else
                printf("%5d", 0);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    TSMatrix M;
	M.mu = 4;	M.nu = 4;	M.tu = 6;
	M.data[1].i = 1;	M.data[1].j = 1;	M.data[1].e = 3;
	M.data[2].i = 1;	M.data[2].j = 4;	M.data[2].e = 5;
	M.data[3].i = 2;	M.data[3].j = 2;	M.data[3].e = -1;
    M.data[4].i = 3;	M.data[4].j = 4;	M.data[4].e = 9;
	M.data[5].i = 4;	M.data[5].j = 1;	M.data[5].e = 5;
    M.data[6].i = 4;	M.data[6].j = 3;	M.data[6].e = 9;
    if(JudgingSymmetricMatrix(M))
        printf("�ǶԳƾ���\n");
    else
        printf("���ǶԳƾ���\n");
    PrintMatrix(M);


	return 0;
}
