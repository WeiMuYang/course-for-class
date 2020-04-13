#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define OVERFLOW    -2
#define TElemType   char

//----------- ����˫�״洢��ʾ -----------//
#define MAX_TREE_SIZE 100
#define TElemType char
typedef struct			//���ṹ
{
	TElemType data;
	int parent;			//˫�׵�λ����
}PTNode;

typedef struct			//���Ľṹ
{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;			//����λ�úͽ����
}PTree;


void CreateTree(PTree *P)
{
	int m = 0, i;
	printf("�������Ľ������");
	scanf("%d",&m);
	fflush(stdin);
	P->n = m;
	printf("�������ֵ��˫��(�ո����)��\n");
	for(i = 1; i <= m; ++i)	{
		printf("���%d��",i);
		scanf("%c%d",&P->nodes[i].data,&P->nodes[i].parent);
		fflush(stdin);
		if(0 == P->nodes[i].parent)
			P->r = i;
	}
}
 

int DepthTree(PTree P)
{
	int max = 0, temp = 0, f = 0;
	for(int i = 1; i <= P.n; i++)
	{
		temp = 0;
		f = i;
		while(f > 0)
		{
			temp++;
			f = P.nodes[f].parent;
		}
		if(temp > max)
			max = temp;
	}
	return max;
}


int main(void)
{



	return 0;
}

