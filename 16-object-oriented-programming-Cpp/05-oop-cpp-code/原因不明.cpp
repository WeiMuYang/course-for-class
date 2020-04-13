#include <iostream>
#include <string>
using namespace std;

int * Max1(int *p,int *q)
{
	int *s = new int[100];
	int i = 0;
	for(;i < 10;i++)
	{
		s[i] = p[i];
	}
	for(;i < 20;i++)
	{
		s[i] = q[i-10];
	}
	return s;
}

int * Max2(int *p,int *q)
{
	int s[20];
	int i = 0;
	for(;i < 10;i++)
	{
		s[i] = p[i];
	}
	for(;i < 20;i++)
	{
		s[i] = q[i-10];
	}
	return s;
}

int main(void)
{
	int p[10],q[10];
	for(int i = 0; i < 10 ; i++)	p[i] = i;
	for(int i = 0; i < 10 ; i++)	q[i] = i+10;
	int *s1 = Max1(p,q);
	cout << s1[5] << endl << s1[10] << endl;
	int *s2 = Max2(p,q);
	cout << s2[5] << endl << s2[10] << endl;
	return 0;
}