#include <stdio.h>
#include <stdlib.h>
#define Status          int //״̬
#define OVERFLOW        -1  //���
#define OK              1   //��ȷ
#define ERROR           0   //����

typedef int ElemType;

struct {
  
};

Status InitList_L(LinkList &L)
{

    return OK;
}


// �㷨2.8
Status GetElemt_L(LinkList L,int i,ElemType &e)
{
    
    return OK;
}


//�㷨2.9.0
Status ListInsert_L(LinkList &L,int i,ElemType e)	//�����޸�Ӧ�ò��� p = *L����
{
    
    return OK;
}

//�㷨2.10.0
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
   

    return OK;
}


//�㷨2.11.0 
void CreateList_L(LinkList &L,int n){
  

} // CreateList_L




//�㷨2.12 �������Լ��ȿ���
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
 
} // MergeList_L




Status visit(ElemType e) {
    if(printf("%d   ", e))
        return OK;
    return ERROR;
}

Status visit1(ElemType e) {
    if(printf("%d\n", e))
        return OK;
    return ERROR;
}

// ����
Status ListTraverse_L(LinkList L, Status (*pvisit)(ElemType)) {
    LNode *p = L->next;
    while (p) {
        if(!pvisit(p->data))
            return ERROR;
        p = p->next;
    }
    printf("\n");
    return OK;
}


int main(void)
{
    LinkList L;
    ElemType e, dataArr[5] = {11, 22, 33, 44, 55};
    int i;
    InitList_L(L);
    printf("L = %p\n", L);
    printf("L->next = %p\n", L->next);
    printf("L->data = %d\n", L->data);

    for (i = 1; i <= 5; i++)
    {
        ListInsert_L(L, i, dataArr[i-1]);
    }
    ListTraverse_L(L, visit);

    ListDelete_L(L, 2, e);
    ListTraverse_L(L, visit);
 
    return 0;
}


//����CreateList_L
//int main(void)
//{
//    LinkList L;
//    CreateList_L(L, 6);
//    ListTraverse_L(L, visit);
// 
//    return 0;
//}


