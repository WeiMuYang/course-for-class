#include <stdio.h>
#include <stdlib.h>


//�ж�һ��m��n�еĶ�ά�������Ƿ������ͬ��Ԫ�ء�
int ContainSameElem(int *a,int m,int n)
{
    int i, k, HaveSame = 0, length = 0;
    int * temp = (int *)malloc(m * n * sizeof(int));

    for(i = 0;i < m * n;i++)
    {
        for(k = 0;k < length;k++)
        {
            if(a[i] == temp[k])
            {
                printf("a[%d][%d]��%d\n", k/n, k%n, temp[k]);
                printf("a[%d][%d]��%d\n", i/n, i%n, a[i]);
                HaveSame = 1;
            }
        }
        temp[length++] = a[i];//û��������ͬβ������һ��Ԫ��
    }
    return HaveSame;
}

int main(void)
{
    int a[4][3]={11, 12, 13, 24, 25, 26, 13, 38, 39, 40, 39, 42};

    if(ContainSameElem(a[0],4,3))
        printf("a����ͬԪ��!\n");
    else 
        printf("a����ͬԪ��\n");

    return 0;
}


























