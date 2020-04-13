#include <stdio.h>
#include <stdlib.h>


//判断一个m行n列的二维数组中是否存在相同的元素。
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
                printf("a[%d][%d]：%d\n", k/n, k%n, temp[k]);
                printf("a[%d][%d]：%d\n", i/n, i%n, a[i]);
                HaveSame = 1;
            }
        }
        temp[length++] = a[i];//没有遇到相同尾部增加一个元素
    }
    return HaveSame;
}

int main(void)
{
    int a[4][3]={11, 12, 13, 24, 25, 26, 13, 38, 39, 40, 39, 42};

    if(ContainSameElem(a[0],4,3))
        printf("a有相同元素!\n");
    else 
        printf("a无相同元素\n");

    return 0;
}


























