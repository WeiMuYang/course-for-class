//Bmpͼ��Ĺ������������
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
}HTNode, *huffmantree;// ��̬��������洢�շ�����
 
typedef char ** huffmancode;// ��̬��������洢�շ��������
 
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
{// s1Ϊ��С������ֵ�����С���Ǹ�
 
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
// w���n���ַ���Ȩֵ(��>0),����շ�����HT,�����n���ַ��ĺշ�������HC
 
    unsigned int s1,s2,start,c,f,i,m;// 0�ŵ�Ԫδ��
    huffmantree p;
    char *cd;
    if (n<=1)
    {
        return;
    }
    m=2*n-1;
    HT=(huffmantree)malloc((m+1)*sizeof(HTNode));//malloc ��ϵͳ�������ָ��size���ֽڵ��ڴ�ռ䡣
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
 
    for(i=n+1; i<=m; ++i)// ����������
 
    { // ��HT[1~i-1]��ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2
        select1(HT,i-1,&s1,&s2);
        HT[s1].parent=i;  HT[s2].parent=i;
        HT[i].lchild=s1;  HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
// ��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
    HC=(huffmancode)malloc((n+1)*sizeof(char *));// ����n���ַ������ͷָ������([0]����
    cd=(char *)malloc(n*sizeof(char));
 
    cd[n-1]='\0';// ���������
 
    for(i=1; i<=n; ++i)
    {// ����ַ���շ�������
 
        start=n-1;// ���������λ��
 
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
        {// ��Ҷ�ӵ������������
            if(HT[f].lchild==c)
            {
                cd[--start]='0';
            }
            else
            {
                cd[--start]='1';
            }
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char)); // Ϊ��i���ַ��������ռ�
 
        strcpy(HC[i],&cd[start]);// ��cd���Ʊ���(��)��HC
    }
    free(cd);// �ͷŹ����ռ�
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

    // 1. �޸�ѹ���ļ�����ļ���
    for(pname = filename, i = 0; *pname != '.'; pname++, i++)
        zipfile[i] = *pname;
    strcat(zipfile, ".zip");

    strcpy(tempfile,"test.bmp.txt");
    strcpy(tempfile2,"test.bmp222.txt");


    // 2. ��Ҫѹ����bmpͼƬ
    if((fp = fopen(filename,"rb")) == NULL)//fopen����������һ���ļ�
    {
        printf("error on open\n");
        exit(1);
    }
    // 3. ��ȡbmpͼƬ��Ϣ�����ڶ�Ӧ��count�±�λ���������ҵ�0~255ÿ�������ֵ�Ƶ��
    while(fread(&q ,1 ,1 ,fp)){
        weight[q]++; 
    }
    // 4. �ر�bmpͼƬ�ļ�
    fclose(fp);

    // 6. ����Huffman���룬���Huffman��HT�Լ�0~255ÿ������Ӧ������HC  
    huffmancoding(HT,HC,weight, 256);
 
    // 7. ���ÿ�����ֶ�Ӧ�ı������� 
    for(i=0,n=1;i<256;i++){
        printf("%3d:  ",i);
        printf("%s\n",HC[n++]);
    }

    // 8. �򿪸ղŵ�bmpͼƬ
    if((fp = fopen(filename,"rb")) == NULL)
    { //ֻ���򿪻���һ���������ļ���ֻ���������
        printf("error\n");
        exit(1);
    }

    // 9. ��Ҫѹ��д��01���е��ļ�
    if((fptemp = fopen(tempfile,"wb")) == NULL)
    { //ֻд�򿪻���һ���������ļ���ֻ����д����
        printf("error\n");
        exit(1);
    }


    // 10. �ٴζ�ȡbmpͼƬ,����Ӧ����temp�ļ�
    while(fread(&q ,1 ,1 ,fp))
        fwrite(HC[q +1], strlen(HC[q+1]) , sizeof(char), fptemp);
    fclose(fptemp);

    // 11. �ٴ��Զ��ķ�ʽ��01���� 
    if((fptemp = fopen(tempfile,"rb")) == NULL)
    { //ֻд�򿪻���һ���������ļ���ֻ����д����
        printf("error\n");
        exit(1);
    }
    // 12. ��д�ķ�ʽ��zip 
    if((fpzip = fopen(zipfile,"w+")) == NULL)
    { //ֻд�򿪻���һ���������ļ���ֻ����д����
        printf("error\n");
        exit(1);
    }
     
    // 13. ��ȡ01�����ļ�������д��ѹ����  
    code = 0;
    for(i = 0, j = 0; fread(&q ,1 ,1 ,fptemp); ++i){
        if (i % 8 == 0 && i != 0)	
        {	
            fwrite(&code, 1 , 1, fpzip);
            j++;
            code = 0;
        }
		code <<= 1;  //����1λ   
        q -= '0';
		code |= q;	 //��λ��	   
    }
    if(i % 8 != 0){
        code <<= 8 - (i % 8); //����leftΪ2����00000011����Ҫ����6λ��Ϊ11000000
        fwrite(&code, 1 , 1, fpzip);
    }
    fclose(fptemp);
    // 4. DeCompress
    if((fpzip = fopen(zipfile,"rb")) == NULL)
    { //ֻд�򿪻���һ���������ļ���ֻ����д����
        printf("error\n");
        exit(1);
    }

     if((fp = fopen(tempfile2,"wb")) == NULL)
    { //ֻд�򿪻���һ���������ļ���ֻ����д����
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
   






    //printf("��ѹ�����Ϊ��%s\n",strdecode);
    //// 5. GetStrs
    //GetStrs(strdecode, HT,  word, destr);
    //printf("�����Ϊ��%s\n",destr);
   
    fclose(fptemp);
    system("pause");

    return 0;
}
