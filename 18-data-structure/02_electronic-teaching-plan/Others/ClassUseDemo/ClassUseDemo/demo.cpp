#include <stdio.h>

int ContainSameElem(int *a,int m,int n)
{
    int i,j;
    int flag;
    for(i = 0;i< m*n ;i++){
        for(j = i+1;j <= m*n ;j++){
            if(*(a+i) == *(a+j)){
                printf("a[%d][%d]:%d\n",i,j,*(a+i));
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
    }

    return flag;
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


