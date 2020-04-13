# 02-1上课计划  
## 1 回忆上节课内容  
### 1.1 杂事  
- 雪梨任务  
- 点名  
- QQ群资料    
### 1.2 上节课总结    
[Class01-2](../course-summary/Class01-2-20190905.txt)      
```
01-2-20190905
1. ADT的小结 （理解）    
2. 算法的定义、算法的5个特性：有穷性（合理的，可接受的范围内结束）、确定性（指令确定，结果确定）、可行性（执行有限次实现）、输入（≥0）、输出（≥1）  （理解）   
3. 算法设计要求：正确性（4个层面）、可读性（便于阅读）、健壮性（非法判断、const等）、高效率、低存储  （理解）   
4. 算法效率度量：基本操作（被循环包含最深的操作）、频度、时间复杂度（计算题、重点）  
5. 算法存储空间需求：空间复杂度的求法。（计算题、重点）     
```
---

## 2 绪论总结   

---
## 3 线性表概念    

### 3.1 定义、特点    
### 3.2 线性表ADT     
- 每种操作的含义  
- 区别引用型操作和传递引用的不同  
### 3.3 集合合并union函数
>算法2.1   
- [引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/01-Algorithm-2.1-2.2(动态-顺序-引用).cpp)    
-  [指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/02-Algorithm-2.1-2.2(动态-顺序-指针).c)     

### 3.4 有序表合并MergeList函数
>算法2.2                 
- [引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/01-Algorithm-2.1-2.2(动态-顺序-引用).cpp)   
- [指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/02-Algorithm-2.1-2.2(动态-顺序-指针).c)        

---
## 4 线性表的顺序表示和实现       
>算法2.3--算法2.7     
- [动态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/03-Algorithm-2.3-2.7(动态-顺序-引用).cpp)    
- [动态-指针版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/04-Algorithm-2.3-2.7(动态-顺序-指针).c)      
- [静态-引用版](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/05-Algorithm-2.3-2.5(静态-顺序-引用).cpp)      

### 4.1 定义    
### 4.2 动态顺序存储结构  
- 静态顺序存储和动态顺序存储的区别 
- 在插入时的区别  
- 在销毁时的区别   
### 4.3 顺序表初始化 InitList_Sq函数
>[算法2.3](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/06-Algorithm-2.3(动态-顺序-引用-指针).cpp)       
- 指针和引用相互转换       

>初始化作用：    
1. 对于动态顺序表来说就是对顺序表中三个属性成员赋值；    
2. 对于静态顺序表来说就是将元素个数置零即可。    

### 4.4 顺序表插入 ListInsert_Sq函数
>[算法2.4](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/2-线性表/07-Algorithm-2.4(动态-顺序-引用-指针).cpp)     
- 采用下标和采用指针方法互换   
- 静态和动态顺序表在插入时的区别   






