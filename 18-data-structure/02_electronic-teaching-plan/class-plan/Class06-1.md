# 06-1 上课计划  
---

## 1 回忆上节课内容  
### 1.1 杂事  
- 雪梨作业（本周发布链表的作业）      
- QQ群资料(下发的\*.c文件将函数完成，10月7号之前发到我的邮箱)，上次的代码文件有20来个学生没交             


### 1.2 上节课总结    
[Class04-2](../course-summary/Class04-2-20190926.txt)      
```
## 04-2-20190926                     
1. 函数调用，简单值传递、传地址、传引用区别和适用场景；  （掌握）     
2. 函数指针经过寻址还是它本身；                      （理解）     
3. 静态链表的算法和实现；                          （对比动态链表理解）    
4. 线性表的应用——一元多项式                        （理解）      

```
### 1.3 学生的问题    
1. 删除函数Delete，没写free结点     
2. 删除和插入while循环条件写错的，删除：`p->next && j < i-1 `         
3. 有学生在CreateList函数中，用类C写作业的 `scanf(&p = > data);`      
4. 有学生找前驱结点时，从第1个位置开始       
```C
//算法2.10.0
Status ListDelete_L(LinkList *L,int i,ElemType *e)
{
    int cnt = 1;
    LinkList p = (*L) -> next;
    while(p && cnt < i - 1)//先找到第i-1个节点
    {
        cnt += 1;
        p = p -> next;
    }
    
    if(!(p && cnt == i - 1&& p -> next)) return ERROR;//第i-1个节点存在
    LinkList t = p -> next;//记录一下第i个节点，后面要free
    (*e) = t -> data;
    p -> next = t -> next;
    free(t);
    return OK;
}
```
5. 在判断出问题的       
```C
//算法2.10.0
Status ListDelete_L(LinkList *L,int i,ElemType *e)
{
	LinkList p = (*L);
	LinkList q;
	int j = 1;
	while (p->next && j < i)//寻找第i个元素的前驱
	{
		p = p->next;
		j++;
	} //循环正常结束时，p指向第i - 1个元素,要删除第i个元素，所以p->next不能为空

	if (!p->next || j > i - 1)//第i个元素不存在
		return ERROR;
	q = p->next;//q指向被准备删除的元素
	p->next = q->next;
	(*e) = q->data;
	free(q);
    return OK;
}

```
**总结：**出问题的学生很多也是善于思考，没完全按照书中的写法，但是书上的写法的每个语句，都是有一定道理，不能随意修改。    

---

## 2 线性表的链式存储            

>算法2.8--算法2.12       
- [动态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/12-Algorithm-2.8-2.12(动态-链式-引用).cpp)    
- [动态-指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/13-Algorithm-2.8-2.12(动态-链式-指针).c)      
- [动态-引用版-不带头结点](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/14-Algorithm-2.8-2.12(动态-链式-引用)不带头结点.cpp)          
- [静态-引用-带头结点](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/22-Algorithm-2.13-2.17(静态-链式-引用).cpp)       


### 2.1 静态单链表         
>[静态链表PPT](../Others/02-静态链表.pptx)       
>[算法2.13-2.17-静态-链式-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/22-Algorithm-2.13-2.17(静态-链式-引用).cpp)              
>>1. space是整个内存，也是唯一的一个备用链表；      
2. i = space[i].cur;    
3. 下标就代表指针，因此指向头结点的指针是int类型，头指针可以作为正用链表的名字，因此静态正用链表也是int类型；       
4. 初始化备用链表和初始化正用链表是两个不同的函数。         

---


## 3 线性表的应用——一元多项式表示和相加      
>[算法2.22-2.23](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/25-Algorithm-2.22-2.23(动态-链式-引用).cpp)       
1. 下标隐含表示指数，对存在大量零系数的多项式并不适用。 （顺序存储）    
2. 将下标和指数都存储下来。（链式存储）         
3. 多项式的创建`CreatPolyn`函数        
4. 多项式的相加`AddPolyn`函数       

### 3.1 PPT上的作业       
- P53     
- P78    

---


## 4 栈和队列              
### 4.1 栈的定义及逻辑实现           
- 操作受限的线性表（动态、静态、顺序、链式）     
- 栈顶指针的位置：可以是栈顶元素，也可以是栈顶元素的下一个位置，书上的情况是后者     
- Last in First out（LIFO结构）      
### 4.2 栈的表示和实现      
>动态顺序存储      
- [动态-顺序-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/3-栈和队列/01-Algorithm-stack-(动态-顺序-引用).cpp)    
- [动态-顺序-指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/3-栈和队列/02-Algorithm-stack-(动态-顺序-指针).c)        
1. 动态顺序存储和静态顺序存储栈的结构      
2. 基本操作中加工型操作和引用型操作      
3. `InitStack`初始化操作：修改三个属性成员，`top`既可以指向栈顶元素下一个位置，也可以指向栈顶元素       
4. `GetTop`获取栈顶元素，栈顶指针不可修改       
5. `Push`压栈（插入）`*S.top++ = e;`虽然后自增优先级高于寻址，但是它是语句执行完成后再自增，讲的时候可以先将 `S.top++`括起来`(S.top++)`      
6. `Pop`出栈（删除）`e = *--S.top`     



## 5 课下作业    
1. 课下把课本好好看看     
2. 栈的操作下节课找人上来写     
3. 栈的应用这一块大家可以提前写一写，下节课讲   









