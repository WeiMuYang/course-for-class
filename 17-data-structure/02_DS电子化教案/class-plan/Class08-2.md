# 08-2 上课计划  
---
汉诺塔、写代码、串   
## 1 回忆上节课内容  
### 1.1 杂事  
- QQ邮箱第4次作业（不要忘了提交）      
- 本周日晚上补一次课，2课时      

### 1.2 上节课总结    
[Class08-1](../course-summary/Class08-1-20191022.txt)      
```
## 08-1-20191022             
1. 静态顺序栈的实现                                   （理解）      
2. 字符串如何赋值：strcpy函数或者借助循环赋值            （理解、掌握）  
3. 在VS下如何进行程序的调试                           （掌握）     
4. 串的基本概念及ADT的定义                            （理解）     
5. 串的定长存储表示                                  （掌握、实现）      
```
### 1.3 学生的问题      
1.         

---


## 2 串       
> [静态-顺序-引用（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/01-Algorithm-string-(静态-顺序-引用).cpp)       
> [静态-顺序-指针（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/02-Algorithm-string-(静态-顺序-指针).c)       
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)      
> [动态-链式-引用（块链存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/05-Algorithm-string-(动态-链式-引用).cpp)           

### 2.1 串的定长表示及实现      
#### 2.1.1 串的定长表示     
> [静态-顺序-引用（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/01-Algorithm-string-(静态-顺序-引用).cpp)       
> [静态-顺序-指针（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/02-Algorithm-string-(静态-顺序-指针).c)         
- 定长顺序存储表示，也称为静态存储分配的顺序串。即用一组地址连续的存储单元依次存放串中的字符序列。       
- `unsigned char`类型的取值：`[0,255]`      
- `typedef`定义了一种字符数组的数据类型：SString    
- `MAXSTRLEN + 1`0号空间放长度，根据`unsigned char`最大取值是255，因此能放的最大值是255，那么后面跟着255个字符，因此，数组长度是255+1        
- 由于长度限制，超出长度会发生截断     
- 串长度表示有：隐式也有显式，我们这个属于**显式**的表示，C语言中属于隐式以`'\n'`结尾      
- 存储结构：    
```C
//串的定长顺序存储表示
#define MAXSTRLEN       255						//用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1];	//0号单元存放串的长度
```

#### 2.1.2 串联接`Concat` 函数        
> [算法4.2-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/08-Algorithm-4.2-(静态-顺序-引用).cpp)            
> [算法4.2-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/09-Algorithm-4.2-(静态-顺序-指针).c)              
- 用T返回S1和S2联接而成的新串。若未截断返回1，若截断返回0     
- 分三种情况：①未截断`S1[0] + S2[0] <= MAXSTRLEN`   ②截断S2部分`S1[0] < MAXSTRLEN`   ③ 仅取S1`S1[0] == MAXSTRLEN`     
- 第①种情况，先将S1赋值给T，再赋值S2，每次下标从1开始 ，uncut = 1         
- 第②种情况，循环结束条件判断最后T赋值的下标不能大于MAXSTRLEN ， uncut = 0        
- 第③种情况，将S1完全赋值给T即可      uncut = 0     


#### 2.1.3 求子串`SubString` 函数        
> [算法4.3-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/10-Algorithm-4.3-(静态-顺序-引用).cpp)            
> [算法4.3-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/11-Algorithm-4.3-(静态-顺序-指针).c)            
- 用Sub返回串S的第pos个字符起长度为len的子串   
- 以Sub下标作为循环增量[1,len]，对应关系是`Sub[i] = S[pos + i - 1]`   
- 最后给`Sub[0] = len`     

>算法步骤：
1. 判断`pos:[1, S[0]]` ，len:`[0,S[0]-pos+1]`     
2. 以Sub下标作为循环增量[1,len]，对应关系是`Sub[i] = S[pos + i - 1]`   
3. 最后给`Sub[0] = len`     


#### 2.1.4 串的定长顺序存储的缺点    
>缺点：     
1. 需事先预定义串的最大长度， 这在程序运行前是很难估计的。      
2. 由于定义了串的最大长度，使得 串的某些操作受限（截尾），如：串的联接、插入、置换等运算。     

>改进策略：    
- 不限定最大长度——动态分配串值的存储空间。      

### 2.2 串的堆分配表示及实现        
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        

#### 2.2.1 堆分配存储表示    
>特点：
- 仍以一组空间足够大的、**地址连续**的存储单元依次存放串值字符序列，但它们的存储空间是在程序执行过程中**动态分配**的。       
- 需要一个指向堆区的指针，指向地址连续的存储单元     
- 还需要一个成员标记字符串中元素个数      
- 因为有`length`标记串中字符个数，因此，**第1个字符在下标是0的位置上**      
- 这种结构中若在ch[0]这个位置放字符个数的话，最大字符个数不能超过127，这样也会发生截断，因此，我们不能这样做        
```C
//---- 串的堆分配存储表示----  
typedef struct {
	char *ch;	//若是非空串，则按串长分配存储区，否则ch为NULL
	int length;	//串长度    对比S[0]
}HString;
```

>实现算法方式:     
1. 为新生成的串分配一个存储空间；     
2. 进行串值的复制。      

#### 2.2.2 插入串`StrInsert`函数        
> [算法4.4-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/12-Algorithm-4.4-(动态-顺序-引用).cpp)            
> [算法4.4-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/13-Algorithm-4.4-(动态-顺序-指针).c)              
- `Status StrInsert(HString &S,int pos,HString T)`    
- 堆分配可以扩展空间，而且此处用的是`realloc`            
- 先移动S中的字符腾位置，再插入     
- 移动字符时，先移动最后一个，再一次向前移动        

>算法步骤：
1. 判断`pos`的合法性：`[1, S.length-1]`     
2. 判断T中是否是空串，若不是空串，则执行下面4步：
3. 对`S`串追加空间，借助`realloc`函数      
4. 移动串`S`中字符，腾出空间，放串`T` ，`i`从`[S.length-1, pos-1]`，`i`递减，依次将下标是`i` 的字符向后移动`T.length`个长度 ，即：`S.ch[i + T.length] = S.ch[i];`      
5. 将T插入到`S`中`pos`个位置，对应下标是`pos-1`，`i`从`[pos-1,pos-2+T.length]`，依次给`S`的下标是`i`的赋值，即：`S.ch[i] = T.ch[i - pos + 1];`      
6. 修改S的长度:`S.length += T.length;`    


#### 2.2.3 串联接`StrInsert`函数        
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        
- `Status Concat(HString &T,HString S1,HString S2)`    
- 可以追加空间，不会发生截断，区别于定长顺序存储     
- 因为一开始有`free(T.ch);`，因此，对于空串，调用该函数时，一定要将`T.ch`赋空    


#### 2.2.4 求子串`SubString`函数       
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


#### 2.2.5 其他函数         
>串复制`Strcopy`函数    

>串赋值`StrAssign`函数   
- 通过一个空语句的循环来计算`chars`的字符个数     
- 需要判断是不是空串    

>串比较`StrCompare`函数   
- 通过循环判断对应字符是否相等，若不相等，返回字符之差         
- 若字符都相等，返回串长之差       

>串比较`ClearString`函数   
- 需要释放空间     
- 因为空间随着串而存在    

#### 2.2.6 堆存储结构的优点       
堆存储结构既有顺序存储结构的特点，处理（随机取子串）方便，操作中对串长又没有任何限制，更显灵活，因此在串处理的应用程序中常被采用。     





## 3 课下作业          
1. 抓紧时间复习准备数据结构小测      
2. 本周日晚上补课   











---












