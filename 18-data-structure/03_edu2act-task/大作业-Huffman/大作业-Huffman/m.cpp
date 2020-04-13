#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	INFINITY INT_MAX	//整型的最大值∞
//赫夫曼树和赫夫曼编码的存储表示
typedef struct
{
    unsigned int weight;	//权重
    unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;		//动态分配数组存储赫夫曼树
typedef char ** HuffmanCode;//动态分配数组存储赫夫曼编码表


//选出无父结点，并且权值最小的两个结点，赋值给s1，s2 
void Select(HuffmanTree &HT,int x,int &s1,int &s2)
{
    int i = 1,min1 = INFINITY,min2 = INFINITY;
    for(i = 1;i <= x; i++)//找最小 
        if(HT[i].weight < min1 && HT[i].parent == 0)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
        for(i = 1;i <= x; i++)//找次小 
            if(HT[i].weight < min2 && i != s1 && HT[i].parent == 0)
            {
                min2 = HT[i].weight;
                s2 = i;
            }
}

// 算法 6.12 赫夫曼编码算法
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{	//w存放n个字符的权值（均>0），构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
    int m,i;
    HuffmanTree p;
    char *cd;
    if(n <= 1)
        return ;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));	//0号单元未用
    for(p = HT + 1, i = 1; i <= n; ++i,++p,++w){
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for(;i <= m; ++i,++p){
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for(i = n + 1; i <= m; ++i)	//建赫夫曼树
    {   //在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2

        int s1,s2;
        Select(HT,i-1,s1,s2);
        HT[s1].parent = i;	HT[s2].parent = i;
        HT[i].lchild = s1;	HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //---从叶子到根逆向求取每个字符的赫夫曼编码---
    HC = (HuffmanCode)malloc((n+1) * sizeof(char *));	//分配n个字符编码的头指针向量
    cd = (char *)malloc(n * sizeof(char));				//分配求编码的工作空间
    cd[n - 1] = '\0';									//编码结束符
    for(i = 1; i <= n; ++i){
        int start = n - 1, c, f;
        //从叶子到根逆向求编码
        for(c = i, f = HT[i].parent; f != 0; c = f,f = HT[f].parent)
            if(HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (char *)malloc((n - start) * sizeof(char));	//为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);
        //printf("%d的赫夫曼编码为：%s\n",HT[i].weight,HC[i]);

    }
    free(cd);	//释放工作空间
}


void GetCodes(unsigned char *str, HuffmanTree HT, HuffmanCode HC, char *strcode, int len)
{
    int i, j;
    unsigned char *pstr = str;
    for(i = 0, j = 0; j < len; ++pstr, ++j){
        strcpy(&strcode[i], HC[*pstr + 1]);
        i += strlen(HC[*pstr + 1]);
    }
    
}

void Compress(char *strcode,unsigned char**pbicode)
{
	int num, left, count, i, j;
    int arrtest[100] = {0};
    count = strlen(strcode);
    num = count / 8;	//存储字符需要的多少个字节
	left = count % 8;	//字符串剩余不足8位的个数
	(*pbicode) = (unsigned char *)malloc(sizeof(unsigned char) * (num + (left ? 1 : 0)));
	memset((*pbicode), 0, num + (left ? 1 : 0));

	j = -1;
	for (i = 0; i < count; i++)//位运算，每8个字符以2进制的形式储存在一个字符中 
	{
		if (i % 8 == 0)			j++;
		(*pbicode)[j] <<= 1;           //左移1位   
		strcode[i] -= '0';
		(*pbicode)[j] |= strcode[i];	//按位或	   
    }
	if (left != 0)	//如果left不为0，需要把剩余的几个位向左边靠拢 
	{
		(*pbicode)[j] <<= 8 - left; //例如left为2，即00000011，需要左移6位变为11000000 
	}
}
void DeCompress(unsigned char* bicode, char *strdecode, int count, int left)
{   // count代表bicode中的字节个数 
    int k , ii, i, j = 0;
    unsigned char N;
    for(i = 0; i < count; ++i){
        int arr[8] = {0};
        N = bicode[i];
        k = 0;
        while (N)
        {
            arr[k++] = N % 2;
            N /= 2;
        }
    
    for (ii = 7; ii >= 0; --ii)
        strdecode[j++] = arr[ii] + '0';
    }
    for(i = 0;i < 8-left; ++i)
        strdecode[j--] = '\0';
    strdecode[j] = '\0';
}

void GetStrs(char *strdecode, HuffmanTree HT, unsigned char *destr)
{
    int i, n, k = 0;
    char *p = strdecode, str;
    n = 256;
	for (; *p; p++){
		i = 2 * n - 1;
		while (HT[i].lchild)
   {  //Huffman树没有左孩子必没有右孩子，即为叶子结点
            str = *p++;
			if(str == '0')
				i = HT[i].lchild;
			else
				i = HT[i].rchild;
		}
        --p;
        destr[k++] = i - 1;
    }

}

int GetWeightAndN(char *filename, int *w, int *pn, unsigned char *str,int *plen)
{
    FILE *fp;
    int oneWord = 0, i = 0;
    *pn = 256;
    if((fp = fopen(filename,"rb")) == NULL){//fopen函数用来打开一个文件
        printf("打开文件失败！\n");
        return 0;
    }
    // 3. 读取bmp图片信息，并在对应的count下标位置自增，找到0~255每个数出现的频率
    while(fread(&oneWord ,1 ,1 ,fp)){
        str[i++] = oneWord;
        w[oneWord]++; 
    }
    *plen = i;
    // 4. 关闭bmp图片文件
    fclose(fp);
    return 1;
}

int WriteZip(char *zipname, unsigned char *bicode, int count){
    FILE *fp;
    if((fp = fopen(zipname,"wb")) == NULL){//fopen函数用来打开一个文件
        printf("打开文件失败！\n");
        return 0;
    }
    fwrite(bicode ,count ,1 ,fp);
    return 1;
}


int main(void)
{
    HuffmanTree HT;
    HuffmanCode HC;
    unsigned char str[9000] = { 0 };//str原来串
    char filename[20] = "\0",zipfile[20] = "\0",dezipfile[20] = "\0" ,*pstr;
    char strcode[90000] = { 0 };      // 编码后0和1的串
    unsigned char *bicode = NULL;     // 压缩编码后01二进制  
    char strdecode[90000] = { 0 };    // 解压编码后0和1的串 
    unsigned char destr[9000] = { 0 };        // 解压后destr原来串 
    int w[256] = { 0 };             // 权值数组
    int i,n = 256, count = 0, left, len = 0;
   

    strcpy(filename,"test.bmp");
    // 1. 修改压缩文件后的文件名
    for(pstr = filename, i = 0; *pstr != '.'; pstr++, i++)
        zipfile[i] = *pstr;
    strcpy(dezipfile,zipfile);
    strcat(zipfile, ".zip");
    strcat(dezipfile, ".zip.bmp");
    // 2. 打开要压缩的bmp图片
    if(!GetWeightAndN(filename, w, &n, str, &len))
        return 0;
    printf("原来字节数为：%d\n",len);
    /*for(i = 0; i < len ; ++i)
        printf("%c",str[i]);
    printf("\n");*/
    // 3. Coding 
    printf("0~255数值对应编码：\n",len);
    HuffmanCoding(HT, HC, w, n);
    for(i = 0;i < 256; i++)
        printf("%3d:%s\n",i, HC[i+1]);

    // 4. GetCodes
    GetCodes(str, HT, HC, strcode, len);
    // printf("编码后为：\n%s\n", strcode);
    // 5. Compress
    count = strlen(strcode) % 8 ? strlen(strcode) / 8 + 1 : strlen(strcode) / 8;
    left = strlen(strcode) % 8;
    printf("压缩后占字节数为：%d\n",count);
    Compress(strcode, &bicode);
  //  printf("压缩后为%s\n",bicode);
    // 6. 写入压缩文件
    if(!WriteZip(zipfile ,bicode, count))
        return 0;

    // 6. DeCompress
    DeCompress( bicode, strdecode, count, left);
  //  printf("解压后编码为：\n%s\n",strdecode);
    // 7. GetStrs
    GetStrs(strdecode, HT, destr);
    //for(i = 0; i < len ; ++i)
    //    printf("%c",destr[i]);
    printf("\n");

    // 6. 写入解码后文件
    if(!WriteZip(dezipfile ,destr,len))
        return 0;
    

    free(bicode);
    free(HT);
    for(i = 1; i <= 5; ++i)
        free(HC[i]);
    free(HC);
    return 0;
}