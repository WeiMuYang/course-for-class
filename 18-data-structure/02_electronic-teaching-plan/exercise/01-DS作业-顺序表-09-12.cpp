#include <stdio.h>
#include <stdlib.h>

#define Status          int //״̬
#define OVERFLOW        -1  //���
#define OK              1   //��ȷ
#define ERROR           0   //����


//----- ���Ա�Ķ�̬����˳��洢�ṹ -----
#define LIST_INIT_SIZE  100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10  //���Ա�洢�ռ�ķ�������

#define ElemType int        //ElemType����Ϊint����
typedef struct
{
	ElemType * elem;    //�洢�ռ��ַ
	int length;         //��ǰ����
	int listsize;       //��ǰ����Ĵ洢������С��listsize * sizeof(ElemType)�ֽ�
}SqList;

//�㷨2.3
Status InitList_Sq(SqList &L){
   
	return OK;
}//InitList_Sq

//�㷨2.4
Status ListInsert_Sq(SqList &L, int i,ElemType e){
    //��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e��
    //i�ĺϷ�ֵΪ [1, ListLength_Sq(L)+1]
	
	return OK;
}

//�㷨2.5
Status ListDelete_Sq(SqList &L,int i,ElemType &e){
   
	return OK;
}


int ListLength_Sq(SqList L)
{
   
}

//����
Status equal(ElemType e1,ElemType e2)
{
    if(e1 == e2)
        return OK;
    else
        return ERROR;
}
//С��
Status lessthan(ElemType e1,ElemType e2)
{
    if(e1 < e2)
        return OK;
    else
        return ERROR;
}
//С�ڵ���
Status lessequal(ElemType e1,ElemType e2)
{
    if(e1 <= e2)
        return OK;
    else
        return ERROR;
}

Status GetElem(SqList L,int i,ElemType &e)
{
    
    return OK;
}

//�㷨2.6
int LocateElem_Sq(SqList L,ElemType e,Status (*compare)(ElemType ,ElemType )){
    //��˳�����Ա�L���ҵ���1����e����compare()��Ԫ��λ��
    //���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0

        return 0;
}


//�㷨2.7
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){
    //��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����С�
    //�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����С�
}



//�㷨2.1
void UnionList_Sq(SqList &La,SqList Lb)
    // �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
{
	
}

void visit(ElemType e)
{
	printf("%d ",e);
}

void TraverseList_Sq(SqList La, void (*pvist)(ElemType ))
{
	
}


void Destroy_Sq(SqList &L)
{
	
}

void ClearList_Sq(SqList &L)
{


}

int main(void)
{
	

	return 0;
}