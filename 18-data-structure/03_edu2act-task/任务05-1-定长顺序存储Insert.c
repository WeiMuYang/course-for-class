#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1

//串的定长顺序存储表示
#define MAXSTRLEN       255						//用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1];	//0号单元存放串的长度

// 串赋值也就是串的初始化
Status StrAssign(SString T,char * chars)
{    // 生成一个其值等于串常量chars的串T
    char *c = NULL;
    int i, uncut = 0;
    for(i = 1, c = chars; *c && i <= 255; ++i)
        T[i] = *c++;
    T[0] = i-1;
    if(i > 255)
        return ERROR;   // 产生截断
    else
        return OK;
}

Status StrInsert(SString S, int pos, SString T)
{
	int i, uncut = 1;
	if(pos < 1 || pos > S[0] + 1)
		return ERROR;
	if(T[0])
	{
		if(S[0] + T[0] > MAXSTRLEN)
            return INFEASIBLE;

		for (i = S[0] - 1; i >= pos; i--)
			S[i + T[0]]	= S[i];
		for (i = pos ; i <= pos - 1 + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] += T[0];
	}

	return OK;
}


void PrintStr(SString S)
{
    int i;
    for (i = 1; i <= S[0]; i++)
        printf("%c",S[i]);
    printf("\n");
}




// 测试 Insert
int main(void)
{
    SString S, T;
    Status result;
    StrAssign(S, "abcdefhijklmn");
    StrAssign(T, "UVWXYZ");
    result = StrInsert(S, 4, T);
    if(OK == result)
    {
        printf("未发生截断，结果是：");
        PrintStr(S);
    }
    else if(INFEASIBLE == result){
        printf("发生截断!\n");
     }
    else {
        printf("插入位置有误!\n");
    }

    return 0;
}
