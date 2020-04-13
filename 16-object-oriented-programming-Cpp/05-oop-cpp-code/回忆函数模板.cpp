#include <iostream>
using namespace std;

template <typename T1,typename T2>
T1 myAdd(T1 a, T2 b)
{
	return a+b;
}

template <typename T, int size>
T* Myallco()
{
	return new T[size];
}


int main(void)
{
	cout << myAdd(1.2,3) << endl;
	cout << myAdd<double,int>(3,1.2) << endl;
	cout << myAdd<double,double>(3, 1.2) << endl;
	const int a = 10;
	int *p = Myallco<int , a >();
	/*int b = 10;
	int *p = Myallco<int, b >(); */   //error

	return 0;
}