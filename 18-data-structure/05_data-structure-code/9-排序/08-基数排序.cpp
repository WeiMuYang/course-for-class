#include <stdio.h>
#include <windows.h>
#define  EQ(a, b)	((a)==(b))	//a,b为数值型
#define  LT(a, b)	((a)< (b))
#define  LQ(a, b)	((a)<=(b))
#define  MAX_NUM_OF_KEY  8   //关键字项数最大值
#define  RADIX           10  //关键字基数，此时是十进制整数的基数
#define  MAX_SPACE       100  
#define  KeyType         char
#define  InfoType        char*

typedef struct{
    KeyType keys[MAX_NUM_OF_KEY];   // 关键字
    InfoType otheritems;            // 其他数据项
    int next;
}SLCell;                            // 静态链表结点类型

typedef struct{
    SLCell r[MAX_SPACE];    // 静态链表的可利用空间，r[0]为头结点
    int keynum;             // 记录当前关键字的个数
    int recnum;             // 静态链表当前长度
}SLList;                    // 静态链表的类型

typedef int ArrType[RADIX]; // 指针数组类型
void PrintList(SLList L);
void Distribute(SLList &L, int i, ArrType &f, ArrType &e) {  
  // 算法10.15
  // 静态链表L的r域中记录已按(keys[0],...,keys[i-1])有序，
  // 本算法按第i个关键字keys[i]建立RADIX个子表，
  // 使同一子表中记录的keys[i]相同。f[0..RADIX-1]和e[0..RADIX-1]
  // 分别指向各子表中第一个和最后一个记录。
  int j, p;
  for (j=0; j<RADIX; ++j) f[j] = 0;     // 各子表初始化为空表
  for (p=L.r[0].next;  p;  p=L.r[p].next) {
    j = L.r[p].keys[i]-'0';  // 将记录中第i个关键字映射到[0..RADIX-1]，
    if (!f[j]) f[j] = p;
    else L.r[e[j]].next = p;
    e[j] = p;                // 将p所指的结点插入第j个子表中
  }
} // Distribute


void Collect(SLList &L, int i, ArrType f, ArrType e) {  // 算法10.16
  // 本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次链接成
  // 一个链表，e[0..RADIX-1]为各子表的尾指针
  int j,t;
  for (j = 0; !f[j]; j++);  // 找第一个非空子表，succ为求后继函数: ++
  L.r[0].next = f[j];  // L.r[0].next指向第一个非空子表中第一个结点
  t = e[j];
  while (j < RADIX) {
    for (j = j+1; j < RADIX && !f[j]; j++);       // 找下一个非空子表
    if (j < RADIX) // 链接两个非空子表
      { L.r[t].next = f[j];  t = e[j]; }
  }
  L.r[t].next = 0;   // t指向最后一个非空子表中的最后一个结点
} // Collect


void RadixSort(SLList &L) {  // 算法10.17
   // L是采用静态链表表示的顺序表。
   // 对L作基数排序，使得L成为按关键字自小到大的有序静态链表，
   // L.r[0]为头结点。
   int i;
   ArrType f, e;
   for (i = 1; i < L.recnum; ++i) L.r[i-1].next = i;
   L.r[L.recnum].next = 0;     // 将L改造为静态链表
   for (i = 0; i < L.keynum; ++i) {  
      // 按最低位优先依次对各关键字进行分配和收集
      Distribute(L, i, f, e);    // 第i趟分配
      Collect(L, i, f, e);       // 第i趟收集
      PrintList(L);
   }
} // RadixSort

#define KeyNum   3
#define RecNum  11
char *Data[RecNum] = {"278","109","063","930","589","184","505","109","269","008","083"};

int CreateSLList(SLList &L)
{
    int i;
    L.keynum = KeyNum;
    L.recnum = RecNum;
    for(i = 0; i < MAX_SPACE; ++i)
        L.r[i].next = 0;
    L.r[0].next = 1;
    for(i = 0; i < L.recnum; ++i) {
        L.r[i+1].next = i + 2;
        strcpy(L.r[i+1].keys, Data[i]);
    }
     L.r[i].next = 0;

     return 0;
}

void PrintList(SLList L)
{
    int i = 0;
    while(L.r[i].next != 0){
        i = L.r[i].next;
        printf("%s ", L.r[i].keys);
    }
    printf("\n");
}

int main(void)
{
    SLList L;
    
    CreateSLList(L);
    PrintList(L);
    RadixSort(L);
    // PrintList(L);
    return 0;
}


