# 10-2 上课计划     
---
## 1 回忆上节课内容  
### 1.1 杂事  
1. 雪梨发布第5次任务，提前做，有点难度    
2. 雪梨发布的第6次任务，也要抓紧时间，提交空白     
3. 小测的题目我们会尽快给分      
4. 作业抄袭问题    
5. 对于具体问题，结构要具体化，不要写ElemType      
6. 返回时候，int   或者  1   0    -1，除非你在前面宏定义了一部分内容     
7. 对于作业判的有误的情况，注意说话方式，一定要据理力争，扣一分也不行，最后我出面给你做主   

### 1.2 上节课总结    
[Class10-1](../course-summary/Class10-1-20191105.txt)      
```
## 10-1-20191105                    
1. 数组的定义、N维数组、数组的特点                   （理解）    
2. 数组的存储方式：行为主序、列为主序                 （掌握、理解）     
3. 数组的初始化算法实现                             （了解）     
4. 特殊矩阵存储：对称矩阵、三角矩阵、对称矩阵          （理解）   
5. 三元组顺序表结构、矩阵转置                       （掌握、理解）    
```
### 1.3 学生的问题        
1. 把雪梨作业代码上传到github     

---

## 2 稀疏矩阵   
### 2.1 三元组顺序表      
> [动态-顺序-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/03-Algorithm-tsmatrix-(静态-顺序-引用).cpp)      
> [动态-顺序-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/04-Algorithm-tsmatrix-(静态-顺序-指针).c)       

### 2.2 快速转置`FastTransposeSMatrix`函数      
>[Algorithm-5.2](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/13-Algorithm-5.2-(静态-顺序-引用).cpp)       
-  `Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T)`     
-  统计每列的非零元个数放到num数组中；    
- 已知第1列第1个非零元对应T中三元组顺序表中第1个位置`cpot[1] = 1;`    
- 根据`cpot[col]=cpot[col–1]+num[col–1]`依次递推，求出不同列号第一个非零元   
- 每次放完第col列第i个非零元，则++cpot[col]，这时，cpot[col]中保存的是第col列下一个非零元的位置   

>步骤：   
1. 行列互换，非零元个数不变      
2. 如果非零元个数不为0，进行以下4步：        
3. 通过循环求出每列非零元个数，保存至num数组中    
4. 通过循环递推求出cpot数组    
5. 对M循环，循环变量是`p:1~M.tu`，依次取出M中非零元，进行如下2步操作：      
6. 先取出非零元的列号给了col，根据cpot数组和col找到这个非零元在T中位置，赋值给q  
7. 将该M中非零元行列互换，非零元不变，赋值给T，然后`++cpot[col]`      


### 2.2 行逻辑联接的顺序表（带行表的三元组）     
> [动态-顺序-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/05-Algorithm-rlsmatrix-(静态-顺序-引用).cpp)      
> [动态-顺序-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/06-Algorithm-rlsmatrix-(静态-顺序-指针).c)       
- 为了方便根据行号找到，该行的元素在什么位置，而不用每次都从头开始循环   
- 存储这个每行第一个非零元的位置的数组，我们称为行逻辑    

>行逻辑联接顺序表存储结构：    
```C
#define MAXSIZE     12500	//非零元的个数最大值为12500
#define MAXRC       250
#define ElemType    int
typedef struct
{
	int i, j;
	ElemType e;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];
	int rpos[MAXRC + 1];	//各行第一个非零元的位置表
	int mu, nu, tu;			//矩阵的行数、列数和非零元个数
}RLSMatrix;
```

>[Algorithm-5.3](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/15-Algorithm-5.3-(静态-顺序-引用).cpp)       
- 行逻辑循环的范围问题     



### 2.3 十字链表     
> [动态-顺序-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/07-Algorithm-crosslist-(动态-链式-引用).cpp)      
> [动态-顺序-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/08-Algorithm-crosslist-(动态-链式-指针).c)       
- 稀疏矩阵的链式存储    
- 会画结构图即可      

>[Algorithm-5.4](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/5-数组和广义表/17-Algorithm-5.4-(动态-链式-引用).cpp)       
- `Status CreateSMatrix(CrossList &M)`    
-  `M.rhead`和`M.chead`是长度为行数+1和列数+1的顺序表，因为0号空间不用   
-    

>步骤：     
1. 先给矩阵M的行数、列数、非零元个数赋值    
2. 给`M.rhead`和`M.chead`申请连续存储空间，并将每个空间初始值置空    
3. 通过循环插入结点，循环个数就是非零元个数，每次循环执行下列5步操作：   
4. 获取非零元的行号、列号、非零元的值   
5. 生成结点，将非零元的信息存入结点中的i、j、e    
6. 若`M.rhead[i] == NULL || M.rhead[i]->j > j`， 则用头插法   
7. 否则的话，通过循环向后找，要插入结点位置前驱，找到后插入即可    
8. 同样的方法，将新结点插入到列链表中    


## 3 广义表    
### 3.1 广义表的概念    
- 广义表的定义   
- 广义表的表头、表尾、长度、深度   


### 3.2 广义表的存储结构    
#### 3.2.1 首尾链表    
- 广义表分成表头和表尾两部分    
- 广义表结点的值，要么是元素，要么是指向广义表的指针，因此采用联合体 同时用tag作为标记    
- 每脱一层括号，图示就多一个三个框的表     

#### 3.2.2 扩展线性链表（孩子兄弟链表）     
- 每脱一层括号，图示就多一个三个框的表   
- 同一个括号中的原子，互为兄弟，长子后面跟着同一级别的所有兄弟   
- 结点中要么是一个原子，要么是指针， 因此采用联合体，同时用tag作为标记       






## 4 课下作业        
1. 雪梨任务7 本周五发布    

---












