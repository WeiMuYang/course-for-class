#include<iostream>
#include<string>
using namespace std;

class MyClass
{
public:
	MyClass& operator()(int a)
	{
		cout << a << endl;
		return *this;
	}
	int operator()(int a,int b)
	{
		return a+b;
	}
};

int main(void)
{
	MyClass obj;
	cout << obj(2)(7)(9)(7,9) << endl;
	return 0;
}