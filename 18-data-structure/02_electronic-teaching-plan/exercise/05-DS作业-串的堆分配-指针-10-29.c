#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define OVERFLOW    -2


// ------------- 作业要求： -------------   // 
// 1.请用C语言实现以下8个函数，用*.c文件书写编译      
// 2.作业完成后，请发送至863255386@qq.com,邮箱的主题：05-数据结构-string-X班-姓名-学号    
// 3.截止时间2019-11-03   
// 4.有问题多交流，谢谢理解配合！    


//---- 串的堆分配存储表示----  
typedef struct {
	char *ch;	//若是非空串，则按串长分配存储区，否则ch为NULL
	int length;	//串长度
}HString;


// 算法4.4 
Status StrInsert(HString *S,int pos,HString T)
{
	
	return OK;
}


Status StrAssign(HString *T,char *chars)
{
	

	return OK;
}

int StrLength(HString S)
	//返回S的元素个数，称为串的长度
{
	 
}

int StrCompare(HString S,HString T)
	//若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
{
	
}

Status ClearString(HString *S)
	//将S清空
{
	
	return OK;
}

int Concat(HString *T,HString S1,HString S2)
	//用T返回由S1和S2联接而成的新串。
{
	
	return OK;
}

Status SubString(HString *Sub,HString S,int pos,int len)
{
	
	return OK;
}

void PrintStr(HString S)
{
	
}

int main(void)
{
	int i;
	HString s1 ,s2 , t, sub;
    sub.ch = s1.ch = s2.ch = t.ch = NULL;

	StrAssign(&s1, "123567890");
	PrintStr(s1);

    StrAssign(&s2, "ABCDEFGH");
	PrintStr(s2);
	
	StrInsert(&s1, 2 ,s2);
    PrintStr(s1);

    SubString(&sub, s1, 6, 7);
    PrintStr(sub);

    Concat(&t, s1, s2);
    PrintStr(t);



	return 0;
}