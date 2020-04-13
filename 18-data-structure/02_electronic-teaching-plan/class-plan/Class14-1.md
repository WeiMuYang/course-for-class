# 14-1 上课计划     

---


## 1 回忆上节课内容  
### 1.1 杂事  
1. 雪梨作业问的比较多的是：输出根结点到结点x的路径    
2. 处理雪梨作业判错的内容     
3. 补课一次，讲一下去年小测试题    
4. 课下大家多做题，下周第二次小测     
5. 第二次小测押题卷（自己准备就行）    


### 1.2 上节课总结    
[Class13-1](../course-summary/Class13-1-20191126.txt)      
```
## 13-1-20191126                             
1. 哈夫曼树的基本概念           （理解）      
2. 哈夫曼树的构造              （理解、掌握、实现）      
3. 哈夫曼编码与译码             （理解、掌握、实现）       
4. 图的定义及术语               （理解）      
```

---

## 3 数据结构小测    
[2017 — 2018 学年第 一 学期《 数据结构 》期中考考试](../Others/08-小测准备数据结构-期中试卷.doc)    
[2016 — 2017 学年第 一 学期《 数据结构 》期中考考试](../Others/07-小测准备-2016-2017学年第1学期数据结构期中试题.doc)     


## 4 数组与广义表   
1. 稀疏矩阵的存储：三元组表示法(16 — 17 小测 )   
2. 十字链表画法（雪梨作业）   
3. 广义表求表头和表尾(16 — 17 小测 )   

## 5 二叉树的性质   
[数据结构单本](../../06_数据结构试题分章节/ch06树与二叉树.docx)      

## 6 根据前序（后序）和中序画二叉树  
PPT练习    

## 7 线索二叉树的画法（雪梨作业+数据结构单本）   

[数据结构单本](../../06_数据结构试题分章节/ch06树与二叉树.docx)      

## 8 树的双亲表示法   

[双亲表示法的实现](../../05_data-structure-code/6-树和二叉树/05-Algorithm-ptree-(动态-顺序-引用).cpp)    

## 9 哈夫曼树及其编码      



## 10 上三角存储及图的遍历   



## 2 图       
### 2.1 邻接表    
[ALGraph-静态-顺序-引用](../../05_data-structure-code/7-图/03-Algorithm-algraph-(动态-顺序-链式-引用).cpp)      
[ALGraph-静态-顺序-指针](../../05_data-structure-code/7-图/04-Algorithm-algraph-(动态-顺序-链式-指针).c)   
>特点：   
>1. 若无向图中有 n 个顶点、e 条边，则其邻接表需 n 个头结点和 2e 个表结点。适宜存储稀疏图。   
>2. 无向图中顶点 vi 的度为第 i 个单链表中的结点数。   
>3. 对于有向图，找出度容易，找入度难   


>图的邻接表表示法存储结构    
```C
#define MAX_VERTEX_NUM  20
#define InfoType        int	//该弧相关信息的指针（假设信息是整数，因此用int类型）
#define VertexType      char	//顶点类型（假设每个顶点是一个字符表示）

typedef enum {
    DG,DN,UDG,UDN			//有向图，有向网，无向图，无向网
}GraphKind;		

typedef struct ArcNode {    //表结点类型
    int adjvex;				//该弧指向顶点位置 0,1,2,3...
    //这个位置指的是邻接的顶点在表头数组中的位置
    struct ArcNode * nextarc;	//指向下一条弧的指针
    InfoType *info;				//该弧相关信息的指针
}ArcNode;

typedef struct VNode {  //头结点类型
    VertexType data;	//顶点信息（VertexType实际上是顶点类型）
    ArcNode *firstarc;	//指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct	{	    //邻接表类型
    AdjList vertices;	
    int vexnum;	//图的顶点数
    int arcnum;	//图的弧数
    GraphKind kind;			//图的类型标志
}ALGraph;
```

### 2.2.3 十字链表     
```C
//---有向图的十字链表存储表示---
typedef struct ArcBox {	//弧结点的结构
	int tailvex, headvex;		//该弧的尾和头顶点的位置
	struct ArcBox *hlink,*tlink;//分别为弧头相同和弧尾相同的弧的链域
	InfoType *info;				//该弧相关信息的指针
}ArcBox;

typedef struct VexNode {	//顶点结点结构
	VertexType data;			//顶点信息（VertexType实际上是顶点类型）
	ArcBox *firstin, *firstout;	//分别指向该顶点第一条入弧和出弧
}VexNode;

typedef struct	{		//十字链表结构
	VexNode xlist[MAX_VERTEX_NUM];//表头向量
	int vexnum, arcnum;			  //有向图的当前顶点数和弧数
}OLGraph;
```
>十字链表画法步骤：   
>1. 先写出顶点结点，确定图的每一行，写出data域，并标记每行行号0-n-1  
>2. 在图的上方标记每列，方便画图，属于草稿，a b c d并分别写上0 1 2 3  
>3. 先画以顶点结点为弧尾的弧，然后链接成单链表；    
>4. 在画结点时，每个结点所在的位置行列：第几行有弧尾顶点确定，第几列由弧头顶点确定    
>5. 循环第3步和第4步，画出所有弧     

---





---

## 5 课下作业        
1. 雪梨作业任务7   
2. 把第6章的PPT后面习题做一下       
3. 把Huffman编码和译码实现一下    
4. 压缩和解压缩也实现一下   

---












