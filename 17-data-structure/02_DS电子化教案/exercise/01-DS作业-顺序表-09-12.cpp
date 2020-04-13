#include <stdio.h>
#include <stdlib.h>

#define Status          int //状态
#define OVERFLOW        -1  //溢出
#define OK              1   //正确
#define ERROR           0   //错误


//----- 线性表的动态分配顺序存储结构 -----
#define LIST_INIT_SIZE  100 //线性表存储空间的初始分配量
#define LISTINCREMENT   10  //线性表存储空间的分配增量

#define ElemType int        //ElemType设置为int类型
typedef struct
{
	ElemType * elem;    //存储空间基址
	int length;         //当前长度
	int listsize;       //当前分配的存储容量大小：listsize * sizeof(ElemType)字节
}SqList;

//算法2.3
Status InitList_Sq(SqList &L){
   
	return OK;
}//InitList_Sq

//算法2.4
Status ListInsert_Sq(SqList &L, int i,ElemType e){
    //在顺序线性表L中第i个位置之前插入新的元素e，
    //i的合法值为 [1, ListLength_Sq(L)+1]
	
	return OK;
}

//算法2.5
Status ListDelete_Sq(SqList &L,int i,ElemType &e){
   
	return OK;
}


int ListLength_Sq(SqList L)
{
   
}

//等于
Status equal(ElemType e1,ElemType e2)
{
    if(e1 == e2)
        return OK;
    else
        return ERROR;
}
//小于
Status lessthan(ElemType e1,ElemType e2)
{
    if(e1 < e2)
        return OK;
    else
        return ERROR;
}
//小于等于
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

//算法2.6
int LocateElem_Sq(SqList L,ElemType e,Status (*compare)(ElemType ,ElemType )){
    //在顺序线性表L中找到第1个与e满足compare()的元素位序
    //若找到，则返回其在L中的位序，否则返回0

        return 0;
}


//算法2.7
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){
    //已知线性表La和Lb中的数据元素按值非递减排列。
    //归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
}



//算法2.1
void UnionList_Sq(SqList &La,SqList Lb)
    // 将所有在线性表Lb中但不在La中的数据元素插入到La中
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