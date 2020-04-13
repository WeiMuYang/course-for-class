#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define OVERFLOW    -2
#define TElemType   char

//----------- 树的双亲存储表示 -----------//
#define MAX_TREE_SIZE 100
#define TElemType char
typedef struct			//结点结构
{
	TElemType data;
	int parent;			//双亲的位置域
}PTNode;

typedef struct			//树的结构
{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;			//根的位置和结点数
}PTree;


void CreateTree(PTree *P)
{
	int m = 0, i;
	printf("输入树的结点数：");
	scanf("%d",&m);
	fflush(stdin);
	P->n = m;
	printf("输入结点的值和双亲(空格隔开)：\n");
	for(i = 1; i <= m; ++i)	{
		printf("结点%d：",i);
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

