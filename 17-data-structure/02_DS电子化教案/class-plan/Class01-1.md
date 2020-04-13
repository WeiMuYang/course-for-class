# 01-1上课计划  
## 1 介绍部分  
### 自我介绍  
- 雪梨C语言同步课  
- 考试出题  
- 解决过一些C语言问题  
- 专业辅导员  
### 课程介绍  
- 课程地位  
- 就业与考研  
- 评奖学金、保研    
- 程序设计大赛   
### 课程要求  
- 这部分放在平时分中  
- 迟到三次 = 一次旷课  
- 旷课两次平时成绩0分  
- 找辅导员请假后，让班委带上假条   
- 点名的时间可能在上课前，上课中，也可能在上课后   
- 上课基本不用电脑，用的时候会提前跟大家说  
- C语言上学期没学好的这学期希望可以跟着我好好熟悉一遍   
- 上课谁有听不明白的，直接问我，不要不好意思  
## 2 C语言储备知识  
- [指针、数组](../../../../GithubRepository/WeiMuYang/data-structure\数据结构代码\0-C语言储备知识/01-指针-数组.c)     
```C
#include <stdio.h>

void Visit1(int brr[5],int length)
{
	printf("brr = %p\n",brr);
	printf("&brr = %p\n",&brr);
	printf("sizeof(brr) = %d\n",sizeof(brr));
}

int main(void)
{
	int arr[5]= {1,2,3};
	int *parr = arr;
	printf("arr[2] = %d\n",arr[2]);
	printf("*(arr+2) = %d\n",*(arr+2));
	printf("parr[2] = %d\n",parr[2]);
	printf("*(parr+2) = %d\n",*(parr+2));
	//1.
	//++parr;
	//++arr;
	//2.
	printf("&parr = %p\n",&parr);
	printf("&arr = %p\n",&arr);
	printf("parr = %p\n",parr);
	//3.
	printf("sizeof(parr) = %d\n",sizeof(parr));
	printf("sizeof(arr) = %d\n",sizeof(arr));
	
	//Visit1(arr,5);

	return 0;
}
```
- [指针、引用](../../../../GithubRepository/WeiMuYang/data-structure\数据结构代码\0-C语言储备知识/02-指针-引用.cpp)       
```C
#include <stdio.h>
//---------     指针-引用     ---------//
void Myswap1(int a,int b)
{
	int c = a;
	a = b;
	b = c;
}

void Myswap2(int &a,int &b)
{
	int c = a;
	a = b;
	b = c;
}

void Myswap3(int *pa,int *pb)
{
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

int main(void)
{
	int a = 1;
	int b = 2;
	int &ra = a;
	int *pa = &a;
	ra = 100;
	printf("&a = %p, a = %d\n",&a,a);
	printf("&ra = %p, ra = %d\n\n",&ra,a);
	*pa = 200;
	printf("&a = %p, a = %d\n",&a,a);
	printf("&ra = %p, ra = %d\n",&ra,a);
	printf("pa = %p, *pa = %d\n\n",pa,*pa);

	Myswap1(a,b);
	printf("Myswap1: a = %d,b = %d\n",a,b);
	Myswap2(a,b);
	printf("Myswap2: a = %d,b = %d\n",a,b);
	Myswap3(&a,&b);
	printf("Myswap3: a = %d,b = %d\n",a,b);

	return 0;
}
```

- [结构体、typedef](../../../../GithubRepository/WeiMuYang/data-structure\数据结构代码\0-C语言储备知识/03-结构体-typedef.c)      
```C
#include <stdio.h>

//----------------     结构体和typedef     ----------------//

typedef struct Date
{
	int Year;
	int Month;
	int Day;
	struct Date *pDate;
}Date, *pDate;

typedef int INTARR[3];

int main(void)
{
	Date d1 = {2018,9,11};
	pDate pd = &d1;
	Date* pd1 = &d1;
    INTARR arr1;
	arr1[0] = 1;	arr1[1] = 2;   arr1[2] = 3;
	pd->pDate = &d1;
	printf("%d-%d-%d\n",pd->Year,pd->Month,pd->Day);
	printf("%d-%d-%d\n",pd1->Year,pd1->Month,pd1->Day);
	printf("%d-%d-%d\n",pd->pDate->Year,pd->pDate->Month,pd->pDate->Day);

	return 0;
}
```
- [动态内存分配](../../../../GithubRepository/WeiMuYang/data-structure\数据结构代码\0-C语言储备知识/04-动态内存分配.c)      
```C
#include <stdio.h>
#include <stdlib.h>

//-------------    动态分配     -------------//
int main(void)
{
	int i;
	int *q;
	int *p = (int *)malloc(4 * sizeof(int));
	if(p == NULL)
	{
		printf("空间申请失败！\n");
		exit(1);
	}
	for(i = 0; i < 4; ++i)
	{
		p[i] = i+1;
	}
	q = (int *)realloc(p , 6 * sizeof(int));
	if(q == NULL)
	{
		printf("空间追加失败!\n");
		exit(1);
	}

	printf("%d\n",q[3]);
	free(p);
	return 0;
}
```
- [递归与栈](../../../../GithubRepository/WeiMuYang/data-structure\数据结构代码\0-C语言储备知识/05-递归-栈.c)      
```C
#include<stdio.h>
int fun(int *a,int n)
{
    if(n == 0)
        return a[0];
    else
        return fun(a ,n - 1) + a[n];
}

int main(void){
    int a[5] = {1, 2, 3, 4, 5},i;
    
    printf("%d",fun(a, 4));
    return 0;
}
```

## 3 课程概览  
3页  
## 4 基本概念和术语   
7页  
## 5 抽象数据类型   
11页（略讲）  



