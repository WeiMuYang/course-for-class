#include <iostream>  
#include <string>  
using namespace std;

template <typename Ty,class T1>
T1 add(Ty a, T1 b)
{
	return a + b;
}


template <typename T,int size>
T* Myallco()
{
	return new T[size];
}


int main(void)
{
	cout << add<int ,double>(2,3.98) << endl;

	double a = 1,b = 3;
	swap(a,b);
	cout << a <<"  "<< b << endl;


	int* p = Myallco<int ,10>();


	return 0;
}