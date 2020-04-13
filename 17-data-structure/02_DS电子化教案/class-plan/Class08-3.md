# 08-3 上课计划（补）  
---
## 1 回忆上节课内容  
### 1.1 杂事  
- QQ邮箱第4次作业（不要忘了提交）      
- 下周五(11月1日)下午16:35—18:05组织小测考试   
- 判作业发现问题，宽容    
- 有些学生不太会，做往年习题，编程        
- 不知道雪梨同步课的答案在哪里    

### 1.2 上节课总结    
[Class08-2](../course-summary/Class08-2-20191024.txt)      
```
## 08-2-20191024                
1. 串的定长顺序存储基本操作——串联接          （掌握、实现）    
2. 串的定长顺序存储基本操作——求子串          （掌握、实现）      
3. 串的定长顺序存储的缺点及改进              （理解）       
4. 串的堆分配存储表示                      （掌握、实现）            
5. 串的堆分配基本操作——插入串               （掌握、实现）            
```
### 1.3 学生的问题      

---

## 2 栈和队列              
### 2.1 递归与栈（没讲）      
> [算法3.5-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/3-栈和队列/14-Algorithm-3.5-(指针).c)            
- 汉诺塔是做什么？有个关于它的故事         
```
   相传在印度的贝纳雷斯有座大寺庙，寺庙内有一块红木板，上面插着三根钻石棒，在盘古开天地，世界刚创造不久之时，神便在其中的一根钻石棒上放了64枚纯金的圆盘。有一个叫婆罗门的门徒，不分日夜地向这座寺庙赶路，抵达后，就尽力将64枚纯金的圆盘移到另一根钻石棒上。等到婆罗门完成这项工作，寺庙和婆罗门本身都崩溃了，世界在一声霹雳中也毁灭了。
```
>>递归具备条件：
>>1. 递归结束条件    
>>2. 相邻项之间存在递推关系      
- 将一个大问题化简成若干个小问题，这些小问题和大问题是一种问题，在化简成小问题过程中，逐渐向终止条件靠拢，最终结束    

>算法思路：      
- 在移动圆盘过程中，总会是：       
>> 1. 将x上的`1~n-1`移动到y，z作为辅助     
>> 2. 然后将n由x移动到z      
>> 3. 将y上的`1~n-1`，移动到z，x作为辅助        

>函数作用：    
- `hanoi(int n, char x, char y, char z)` 将x上编号为1~n的圆盘移动至z，y作为辅助塔        
- `move(char x, int n, char z)`将编号为n的圆盘从x移动到z     

>递归和栈如何转换，解释清楚     



>时间复杂度：$ O(n)=O(T(n))=O(O(1)+O(2^{n+1}-1))=O(2^{n+1}+1-1)=O(2^{n+1})=O(2^n)$    
>空间复杂度：$ O(n) $ 
>执行步数  ：$ 2^n-1 $



### 2.2 队列习题(补一次课)         



---





## 3 串       
> [静态-顺序-引用（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/01-Algorithm-string-(静态-顺序-引用).cpp)       
> [静态-顺序-指针（定长顺序存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/02-Algorithm-string-(静态-顺序-指针).c)       
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)      
> [动态-链式-引用（块链存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/05-Algorithm-string-(动态-链式-引用).cpp)           


### 3.1 串的堆分配表示及实现        
> [动态-顺序-引用（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/03-Algorithm-string-(动态-顺序-引用).cpp)      
> [动态-顺序-指针（堆分配存储）](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/04-Algorithm-string-(动态-顺序-指针).c)        

#### 3.1.1 插入串`StrInsert`函数        
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


#### 3.1.2 串联接`StrInsert`函数        
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

>串比较`ClearString`函数   
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
1. 通常情况下，效率比较高，经常被程序员选用。 此时算法的时间复杂度为：`O(n+m)`      
2. 某些特殊的情况下，效率比较低。 此时算法的时间复杂度为：`O(n*m)`         


#### 3.3.2 KMP算法      
> [算法4.6-4.7-引用](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/16-Algorithm-4.6-4.7(静态-顺序-引用).cpp)            
> [算法4.5-指针](../../../../GithubRepository/WeiMuYang/data-structure/数据结构代码/4-串/17-Algorithm-4.6-4.7(静态-顺序-指针).c)              
- `int Index_KMP(SString S, SString T,int pos)`      
- 当子串和主串失配后，主串`i`保持不动，子串`j`滑动到`next[j]` 的位置    
- 子串的next数组中，下标`i`对应的值，就是串中第`i`s个字符要滑动的位置        
- next数组中，下标和字符位置对应，因此，next[0]不用，从next[1]开始用    
- next[1] = 0，因为第一次失配的话，j还要变成1，而i需要向后移动，因此，需要自增，因此next[1] = 0    
- next函数值仅取决于模式串本身，而与主串无关。    

>KMP算法步骤：    
1. 主串从第`pos`个位置开始，子串从第`1`个位置开始            
2. `while`循环只要主串S和子串T不为空，循环下面一步：    
3. 若`S[i]`和`T[j]`对应相等，两个指针分别向后移动，否则，`i`不变，`j = next[j]`   
4. 循环结束，判断`j>T[0]`是否成立，若成立，返回`i - T[0]`      


>get_next函数：找子串中，从第一个开始到
>get_next数组步骤：   
1. next[1] = 0，i = 1，j = 0    
2. while循环给next数组赋值     
3. 若j == 0 || T[i] == T[j] ：自增i，自增j， 将next[i] = j;    
4. 否则 j = next[j];      



>get_nextval函数：    





## 4 课下作业          
1. 抓紧时间复习准备数据结构小测      
2. 本周日晚上补课   











---












