#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1

//���Ķ���˳��洢��ʾ
#define MAXSTRLEN       255						//�û�����255���ڶ�����󴮳�
typedef unsigned char SString[MAXSTRLEN + 1];	//0�ŵ�Ԫ��Ŵ��ĳ���

// ����ֵҲ���Ǵ��ĳ�ʼ��
Status StrAssign(SString T,char * chars)
{    // ����һ����ֵ���ڴ�����chars�Ĵ�T
    char *c = NULL;
    int i, uncut = 0;
    for(i = 1, c = chars; *c && i <= 255; ++i)
        T[i] = *c++;
    T[0] = i-1;
    if(i > 255)
        return ERROR;   // �����ض�
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

		for (i = S[0] + T[0]; i >= pos + T[0]; --i)
			S[i] = S[i - T[0]];
		for (i = 1; i <= T[0]; i++)
		    S[pos + i - 1] = T[i];
		
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




// ���� Insert
int main(void)
{
    SString S, T;
    Status result;
    StrAssign(S, "abcdefhijklmn");
    StrAssign(T, "UVWXYZ");
    result = StrInsert(S, 4, T);
    if(OK == result)
    {
        printf("δ�����ضϣ�����ǣ�");
        PrintStr(S);
    }
    else if(INFEASIBLE == result){
        printf("�����ض�!\n");
     }
    else {
        printf("����λ������!\n");
    }

    return 0;
}
