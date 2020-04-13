//Bmp图像的哈夫曼编码代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <malloc.h>
 
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode, *huffmantree;// 动态分配数组存储赫夫曼树
 
typedef char ** huffmancode;// 动态分配数组存储赫夫曼编码表
 
int power(int i)
{
    int j,result=1;
    for(j=0;j<i;j++)
    {
        result*=2;
    }
    return result;
}
 
void write_file(char temp[],FILE *fp2)
{
    int i;
    unsigned char result=0;
    for(i=8;i>0;i--)
    {
        if(temp[8-i]!='0')
        {
            result+=power(i-1);
        }
    }
    strcpy(temp,temp+8);
}
 
void select1(huffmantree HT, unsigned int i, unsigned int *s1, unsigned int *s2)
{// s1为最小的两个值中序号小的那个
 
    unsigned int j,temp;
    for(j=1;j<=i;j++)
    {
        if(HT[j].parent==0)
        {
            *s2=j;
            break;
        }
    }
    for(;j<=i;j++)
    {
        if(HT[j].parent==0 && j!=*s2)
        {
            *s1=j;
            break;
        }
    }
    for(j=1;j<=i;j++)
    {
        if(HT[j].parent==0 && HT[j].weight < HT[*s1].weight && *s2!=j)
        {
            *s1=j;
        }
    }
    for(j=1;j<=i;j++)
    {
        if(HT[j].parent==0 && HT[j].weight < HT[*s2].weight && *s1!=j)
        {
            *s2=j;
        }
    }
    if(*s1>*s2)
    {
        temp=*s1;
        *s1=*s2;
        *s2=temp;
    }
}
 
 
void huffmancoding(huffmantree &HT, huffmancode &HC,int *w, int n)
{
// w存放n个字符的权值(均>0),构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC
 
    unsigned int s1,s2,start,c,f,i,m;// 0号单元未用
    huffmantree p;
    char *cd;
    if (n<=1)
    {
        return;
    }
    m=2*n-1;
    HT=(huffmantree)malloc((m+1)*sizeof(HTNode));//malloc 向系统申请分配指定size个字节的内存空间。
    for(p=HT+1,i=1; i<=n; ++i,++p,++w)
    {
        p->weight=*w;
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
    }
 
    for(; i<=m; ++i,++p)
    {
        p->weight=0;
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
    }
 
    for(i=n+1; i<=m; ++i)// 建哈夫曼树
 
    { // 在HT[1~i-1]中选择parent为0且weight最小的两个结点,其序号分别为s1和s2
        select1(HT,i-1,&s1,&s2);
        HT[s1].parent=i;  HT[s2].parent=i;
        HT[i].lchild=s1;  HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
// 从叶子到根逆向求每个字符的赫夫曼编码
    HC=(huffmancode)malloc((n+1)*sizeof(char *));// 分配n个字符编码的头指针向量([0]不用
    cd=(char *)malloc(n*sizeof(char));
 
    cd[n-1]='\0';// 编码结束符
 
    for(i=1; i<=n; ++i)
    {// 逐个字符求赫夫曼编码
 
        start=n-1;// 编码结束符位置
 
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
        {// 从叶子到根逆向求编码
            if(HT[f].lchild==c)
            {
                cd[--start]='0';
            }
            else
            {
                cd[--start]='1';
            }
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char)); // 为第i个字符编码分配空间
 
        strcpy(HC[i],&cd[start]);// 从cd复制编码(串)到HC
    }
    free(cd);// 释放工作空间
}
 
 
int main(void)
{
    char w[256]="\0";
    int count[256] = {0}, weight[256] = {0},n = 0,i = 0, j = 0;
    int q = 0, *p = NULL;
    char filename[20]="\0",zipfile[20]="\0",tempfile[20]="\0", tempfile2[20]="\0", *pname = NULL, *pc = NULL;
    FILE *fp,*fpzip,*fptemp;
    huffmantree HT;
    huffmancode HC;
    unsigned char code = 0;
    char code01[5000] = { 0 };


    strcpy(filename,"test.bmp");

    // 1. 修改压缩文件后的文件名
    for(pname = filename, i = 0; *pname != '.'; pname++, i++)
        zipfile[i] = *pname;
    strcat(zipfile, ".zip");

    strcpy(tempfile,"test.bmp.txt");
    strcpy(tempfile2,"test.bmp222.txt");


    // 2. 打开要压缩的bmp图片
    if((fp = fopen(filename,"rb")) == NULL)//fopen函数用来打开一个文件
    {
        printf("error on open\n");
        exit(1);
    }
    // 3. 读取bmp图片信息，并在对应的count下标位置自增，找到0~255每个数出现的频率
    while(fread(&q ,1 ,1 ,fp)){
        weight[q]++; 
    }
    // 4. 关闭bmp图片文件
    fclose(fp);

    // 6. 进行Huffman编码，求出Huffman树HT以及0~255每个数对应的序列HC  
    huffmancoding(HT,HC,weight, 256);
 
    // 7. 输出每个数字对应的编码序列 
    for(i=0,n=1;i<256;i++){
        printf("%3d:  ",i);
        printf("%s\n",HC[n++]);
    }

    // 8. 打开刚才的bmp图片
    if((fp = fopen(filename,"rb")) == NULL)
    { //只读打开或建立一个二进制文件，只允许读数据
        printf("error\n");
        exit(1);
    }

    // 9. 打开要压缩写入01序列的文件
    if((fptemp = fopen(tempfile,"wb")) == NULL)
    { //只写打开或建立一个二进制文件，只允许写数据
        printf("error\n");
        exit(1);
    }


    // 10. 再次读取bmp图片,并对应生成temp文件
    while(fread(&q ,1 ,1 ,fp))
        fwrite(HC[q +1], strlen(HC[q+1]) , sizeof(char), fptemp);
    fclose(fptemp);

    // 11. 再次以读的方式打开01序列 
    if((fptemp = fopen(tempfile,"rb")) == NULL)
    { //只写打开或建立一个二进制文件，只允许写数据
        printf("error\n");
        exit(1);
    }
    // 12. 以写的方式打开zip 
    if((fpzip = fopen(zipfile,"w+")) == NULL)
    { //只写打开或建立一个二进制文件，只允许写数据
        printf("error\n");
        exit(1);
    }
     
    // 13. 读取01序列文件，生成写入压缩包  
    code = 0;
    for(i = 0, j = 0; fread(&q ,1 ,1 ,fptemp); ++i){
        if (i % 8 == 0 && i != 0)	
        {	
            fwrite(&code, 1 , 1, fpzip);
            j++;
            code = 0;
        }
		code <<= 1;  //左移1位   
        q -= '0';
		code |= q;	 //按位或	   
    }
    if(i % 8 != 0){
        code <<= 8 - (i % 8); //例如left为2，即00000011，需要左移6位变为11000000
        fwrite(&code, 1 , 1, fpzip);
    }
    fclose(fptemp);
    // 4. DeCompress
    if((fpzip = fopen(zipfile,"rb")) == NULL)
    { //只写打开或建立一个二进制文件，只允许写数据
        printf("error\n");
        exit(1);
    }

     if((fp = fopen(tempfile2,"wb")) == NULL)
    { //只写打开或建立一个二进制文件，只允许写数据
        printf("error\n");
        exit(1);
    }
    int k , ii;
    j = 0;
    unsigned char N;
    while(fread(&q ,1 ,1 ,fpzip)){
        char strdecode[8] = { 0 };
        int arr[8] = {0};
        N = q;
        k = 0;
        while (N) {
            arr[k++] = N % 2;
            N /= 2;
        }
        for (ii = 7, j = 0; ii >= 0; --ii)
            strdecode[j++] = arr[ii] + '0';
        fwrite(strdecode, 8 , sizeof(char), fp);
      }
   






    //printf("解压后编码为：%s\n",strdecode);
    //// 5. GetStrs
    //GetStrs(strdecode, HT,  word, destr);
    //printf("解码后为：%s\n",destr);
   
    fclose(fptemp);
    system("pause");

    return 0;
}
