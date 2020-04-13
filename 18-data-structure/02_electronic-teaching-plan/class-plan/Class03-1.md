# 03-1 上课计划  
## 1 回忆上节课内容  
### 1.1 杂事  
- 点名    
- 雪梨作业（没表示成n的函数，不写O的）     
- 推荐书籍：考研书，QQ群资料，往年习题集    
### 1.2 上节课总结    
[Class02-2](../course-summary/Class02-2-20190912.txt)      
```
02-2-20190912

1. 顺序表插入算法的步骤、几种写法及时间复杂度分析；    （掌握，实现算法）   
2. 顺序表删除算法的步骤、几种写法及时间复杂度分析；    （掌握，实现算法）    
3. 初始化算法步骤和作用；         （掌握，实现算法）          
4. C语言中指针和下标的对应关系；   （掌握）     

```
### 1.3 学生遇到问题   
1. 第i个位置和第i个元素和elem的下标啥关系   
2. 遍历函数的函数指针如何使用，以`ListTraverse`函数为例    
3. 引用和指针调用问题，以`MergeList`函数为例      
4. 总结什么时候传递引用   
5. 修改成指针形式后，调用Insert函数只传递空指针       
  
---
## 2 线性表的顺序表示和实现       
>算法2.3--算法2.7     
- [动态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/03-Algorithm-2.3-2.7(动态-顺序-引用).cpp)     
- [动态-指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/04-Algorithm-2.3-2.7(动态-顺序-指针).c)      
- [静态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/05-Algorithm-2.3-2.5(静态-顺序-引用).cpp)      


### 2.1 顺序表的遍历`ListTraverse_Sq`函数     
> 实现算法2.3、算法2.4、算法2.5     

> [ListTraverse_Sq函数](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/09-Algorithm-Traverse(动态-顺序-引用).cpp)      
- 遍历函数如何去写      
- 函数指针:函数指针寻址还是它本身，所以\*compare <-> compare       

### 2.2 顺序表的查找`LocateElem_Sq`函数      
>[算法2.6](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/10-Algorithm-2.6(动态-顺序-引用).cpp )          
- 函数作为参数传递      
- 指针和引用区别           

### 2.3 顺序表的应用`MergeList_Sq`函数（不讲）      
>[算法2.7](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/11-Algorithm-2.7(动态-顺序-引用).cpp )          
- 对比算法2.2     
- 基本操作的应用    

### 2.4 引用和指针如何转换    
- 通过比较指针版和引用版的实现文件讲解   

---

## 3 线性表的链式存储            

>算法2.8--算法2.12       
- [动态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/12-Algorithm-2.8-2.12(动态-链式-引用).cpp)    
- [动态-指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/13-Algorithm-2.8-2.12(动态-链式-指针).c)      
- [动态-引用版-不带头结点](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/14-Algorithm-2.8-2.12(动态-链式-引用)不带头结点.cpp)      

### 3.1 单链表初始化`InitList_L`函数     
>[InitList_L函数](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/15-Algorithm-InitList_L(动态-链式-引用-指针-头结点).cpp)      
- 二级指针           
- `->`运算符优先级高于`*`      
- 带头结点和不带都结点的区别          
- 传递引用、传递地址、简单值传递区别      

>作用：  
1. 对于带头结点的单链表，初始化是创建头结点，并给指针域和数据域赋值；  
2. 对于不带头结点的单链表，初始化是将链表指针赋值为`NULL`。    


### 3.2 单链表序号查找`GetElem_L`函数     
>[算法2.8](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/16-Algorithm-2.8(动态-链式-引用-指针-头结点).cpp)      
- 如何找到第i个元素        
- 判断i值合法性的方法      
- 引用型操作不需要传递引用也不需要传递地址         
- 时间复杂度O(n)，比顺序存储O(1) 要高    

>查找步骤：   
1. 查找第i个结点；    
2. 判断i的合法性；    
3. 取出第i个元素给e。    























