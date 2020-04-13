# 09-1 上课计划     
---
## 1 回忆上节课内容  
### 1.1 杂事  
- 小测考试范围      
- 课下做习题     
- 找几个4班的学生谈话     
- 补充汉诺塔内容     

### 1.2 上节课总结    
[Class08-2](../course-summary/Class08-2-20191024.txt)      
```
## 08-3-20191027                
1. 递归与栈                                （理解） 
2. 汉诺塔                                  （了解）    
3. 递归函数运行过程的栈式管理（以汉诺塔为例）    （理解）
4. 第3章PPT上的习题                         （理解、掌握）  
```
### 1.3 学生的问题      

---




## 2 串       
> [静态-顺序-引用（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/01-Algorithm-string-(静态-顺序-引用).cpp)       
> [静态-顺序-指针（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/02-Algorithm-string-(静态-顺序-指针).c)       
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)      
> [动态-链式-引用（块链存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/05-Algorithm-string-(动态-链式-引用).cpp)             

### 2.1 上课写代码    
1. 定长顺序存储——串联接       
2. 定长顺序存储——求子串      
3. 串的堆分配存储——串插入      

### 2.2 串的堆分配表示及实现        
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        

#### 2.2.1 插入串`StrInsert`函数        
> [算法4.4-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/12-Algorithm-4.4-(动态-顺序-引用).cpp)            
> [算法4.4-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/13-Algorithm-4.4-(动态-顺序-指针).c)              
- `Status StrInsert(HString &S,int pos,HString T)`    
- 堆分配可以扩展空间，而且此处用的是`realloc`            
- 先移动S中的字符腾位置，再插入     
- 移动字符时，先移动最后一个，再一次向前移动        

>算法步骤：
1. 判断`pos`的合法性：`[1, S.length+1]`，这里需要注意的是`pos`可以取到`S.length+1`        
2. 判断T中是否是空串，若不是空串，则执行下面4步：      
3. 对`S`串追加空间，借助`realloc`函数      
4. 移动串`S`中字符，腾出空间，放串`T` ，`i`从`[S.length-1, pos-1]`，`i`递减，依次将下标是`i` 的字符向后移动`T.length`个长度 ，即：`S.ch[i + T.length] = S.ch[i];`      
5. 将T插入到`S`中`pos`个位置，对应下标是`pos-1`，`i`从`[pos-1,pos-2+T.length]`，依次给`S`的下标是`i`的赋值，即：`S.ch[i] = T.ch[i - pos + 1];`      
6. 修改S的长度:`S.length += T.length;`    


#### 3.1.2 串联接`Concat`函数        
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        
- `Status Concat(HString &T,HString S1,HString S2)`    
- 可以追加空间，不会发生截断，区别于定长顺序存储     
- 因为一开始有`free(T.ch);`，因此，对于空串，调用该函数时，一定要将`T.ch`赋空    


#### 3.1.3 求子串`SubString`函数       
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        
- `Status SubString(HString &Sub,HString S,int pos,int len)`    
- 因为一开始有`free(Sub.ch);`，因此，对于空串，调用该函数时，一定要将`Sub.ch`赋空    
- 注意子串也有可能是空串    

>算法步骤：
1. 判断`pos:[1, S.length]` ，len:`[0,S.length-pos+1]`       
2. 将`Sub`里面内容释放     
3. 判断是否是所求子串为空      
4. 若所求子串不为空，则执行下面2步：      
5. 给`Sub`申请空间，依次将`S`中下标是`[pos-1，pos+len-2]`依次给了Sub中下标是`[0，len-1]`       
6. 将`Sub`中字符个数赋值为`len`       


#### 3.1.4 其他函数         
>串复制`Strcopy`函数    

>串赋值`StrAssign`函数   
- 通过一个空语句的循环来计算`chars`的字符个数     
- 需要判断是不是空串    

>串比较`StrCompare`函数   
- 通过循环判断对应字符是否相等，若不相等，返回字符之差         
- 若字符都相等，返回串长之差       

>串清空`ClearString`函数   
- 需要释放空间     
- 因为空间随着串而存在    

#### 3.1.5 堆存储结构的优点       
堆存储结构既有顺序存储结构的特点，处理（随机取子串）方便，操作中对串长又没有任何限制，更显灵活，因此在串处理的应用程序中常被采用。     

### 3.2 串的块链存储      
串值也可用单链表存储，简称为**链串**。 链串与单链表的差异只是它的结点数据域为单个字符。     

>优缺点：    
- 便于插入删除     
- 空间利用率低      

>串的块链结构：为了提高空间利用率，可使每个结点存放多个字符(这是顺序串和链串的综合 (折衷) ），称为**块链结构**。      
- 结构体定义，类似于链队列     
- 结点中的Data域是`char`类型的数组      
```C
#define BLANK       '#'

#define CHUNKSIZE 4	//可用户定义的块大小
//== == == 串的块链存储表示(不带头结点)== == ==
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk, SNode;

typedef struct{
    Chunk *head, *tail; // 头尾指针（类似于链队列）
    int curlen;         // 当前串长（因为最后一个结点不一定占满）
}LString;

```

### 3.3 串的模式匹配      
**模式匹配** ：子串定位运算。    
**串匹配**就是在主串中找出子串出现的位置。          

#### 3.3.1 朴素的模式匹配算法      
> [算法4.5-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/14-Algorithm-4.5-(静态-顺序-引用).cpp)            
> [算法4.5-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/15-Algorithm-4.5-(静态-顺序-指针).c)              
- `int Index(SString S, SString T,int pos)`      

>算法思想：从主串 S 的第 pos 个字符起和模式 T 的第一个字符比较之，若相同，则继续比较后续字符；否则从主串 S的下一个字符起再重新和模式 T 的字符比较之。        

>算法步骤：
1. 主串从第`pos`个位置开始，子串从第`1`个位置开始            
2. `while`循环只要主串S和子串T不为空，循环下面一步：    
3. 若`S[i]`和`T[j]`对应相等，两个指针分别向后移动，否则，回退`j-1`(j从1增加到j，走了j-1步)，i再向后移动一位，`j`从`1`开始          
4. 循环结束，判断`j>T[0]`是否成立，若成立，返回`i - T[0]`    

>算法评价：      
>1. 通常情况下，效率比较高，经常被程序员选用。 此时算法的时间复杂度为：$ O(n+m) $      
>2. 某些特殊的情况下，效率比较低。 此时算法的时间复杂度为：$ O(n \times m) $         
>3. 以书上P79页的例子进行讲解，若最极端情况：$ （主串字符个数n - 模式串字符个数m+1）\times 模式串长m $ :        
>> 1. 将主串放在第0行，模式串从第1行开始，每回溯一次换一行；   
>> 2. 在匹配过程中，每多一行，就多匹配模式串长次；   
>> 3. 一共有：主串字符个数n - 模式串字符个数m + 1  行；   
>> 4. 回溯的行数，是：(n - m + 1) -1 = n-m，因为最后一次匹配成功，不算回溯的;    
>> 5. 时间复杂度：频度
$$
(n-m+1)  \times n ;  \because n > m  &there4  O(n \times m)
$$




## 4 课下作业    
### 4.1 掌握内容    
1. 认真写一写串的堆分配的基本操作纯C语言版    
2. 将串插入、串赋值、求串长、串比较、清空串、串联接、求子串、打印串代码写一写；      
3. 作业完成后，请发送至863255386@qq.com,邮箱的主题：05-数据结构-string-X班-姓名-学号   
4. 截止时间 2019-11-03       
### 4.2 代码练习       
>顺序栈习题      
- [05-DS作业-串的堆分配-指针-10-29](../exercise/05-DS作业-串的堆分配-指针-10-29.c)         
- [05-DS作业-串的堆分配-指针-10-29(答案)](../exercise/05-DS作业-串的堆分配-指针-10-29(答案).c)       









---












