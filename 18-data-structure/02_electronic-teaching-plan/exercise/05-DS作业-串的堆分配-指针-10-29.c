#include <stdio.h>
#include <stdlib.h>

#define Status      int
#define OK          1
#define ERROR       0
#define OVERFLOW    -2


// ------------- ��ҵҪ�� -------------   // 
// 1.����C����ʵ������8����������*.c�ļ���д����      
// 2.��ҵ��ɺ��뷢����863255386@qq.com,��������⣺05-���ݽṹ-string-X��-����-ѧ��    
// 3.��ֹʱ��2019-11-03   
// 4.������ཻ����лл�����ϣ�    


//---- ���Ķѷ���洢��ʾ----  
typedef struct {
	char *ch;	//���Ƿǿմ����򰴴�������洢��������chΪNULL
	int length;	//������
}HString;


// �㷨4.4 
Status StrInsert(HString *S,int pos,HString T)
{
	
	return OK;
}


Status StrAssign(HString *T,char *chars)
{
	

	return OK;
}

int StrLength(HString S)
	//����S��Ԫ�ظ�������Ϊ���ĳ���
{
	 
}

int StrCompare(HString S,HString T)
	//��S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0
{
	
}

Status ClearString(HString *S)
	//��S���
{
	
	return OK;
}

int Concat(HString *T,HString S1,HString S2)
	//��T������S1��S2���Ӷ��ɵ��´���
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