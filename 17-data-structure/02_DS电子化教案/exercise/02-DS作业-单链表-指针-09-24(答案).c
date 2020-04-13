#include <stdio.h>
#include <stdlib.h>
#define Status          int //״̬
#define OVERFLOW        -1  //���
#define OK              1   //��ȷ
#define ERROR           0   //����

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status InitList_L(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    (*L)->data = 0;
    return OK;
}


// �㷨2.8
Status GetElemt_L(LinkList L,int i,ElemType *e)
{
    LNode *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    *e = p->data;

    return OK;
}


//�㷨2.9.0
Status ListInsert_L(LinkList *L,int i,ElemType e)	 
{
    LNode *p = (*L), *s = NULL;
    int j = 0;
    while (p && j < i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i-1)
        return ERROR;
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

//�㷨2.10.0
Status ListDelete_L(LinkList *L,int i,ElemType *e)
{
    LNode *p = (*L), *q = NULL;
    int j = 0;
    while (p->next && j < i-1)
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i-1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}


//�㷨2.11.0 
void CreateList_L(LinkList *L,int n){
    int i;
    LNode *s = NULL;
    (*L) = (LNode *)malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->next = NULL;
    for (i = 1; i <= n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = i * 11;
        s->next = (*L)->next;
        (*L)->next = s;
    }
} // CreateList_L




//�㷨2.12 �������Լ��ȿ���
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc){
	LinkList pa, pb, pc;
    pa = (*La)->next;    pb = (*Lb)->next;
    (*Lc) = pc = (*La);             // ��La��ͷ�����ΪLc��ͷ���
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;  
            pc = pa;   
            pa = pa->next;
        }else { 
            pc->next = pb;   
            pc = pb;   
            pb = pb->next; }
    }
    pc->next = pa ? pa : pb;  // pa�Ƿ�Ϊ�գ�����ʣ���
    free(*Lb);                 // �ͷ�Lb��ͷ���
 
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
    InitList_L(&L);
    printf("L = %p\n", L);
    printf("L->next = %p\n", L->next);
    printf("L->data = %d\n", L->data);

    for (i = 1; i <= 5; i++)
    {
        ListInsert_L(&L, i, dataArr[i-1]);
    }
    ListTraverse_L(L, visit);

    ListDelete_L(&L, 2, &e);
    ListTraverse_L(L, visit);
 
    return 0;
}

//����CreateList_L
//int main(void)
//{
//    LinkList L;
//    CreateList_L(&L, 6);
//    ListTraverse_L(L, visit);
// 
//    return 0;
//}


