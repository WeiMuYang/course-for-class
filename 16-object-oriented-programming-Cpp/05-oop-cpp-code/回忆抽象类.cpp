#include<iostream>  
#include<string>  
using namespace std;

class Animal
{
public:
	virtual void Color() = 0;
	int a;
};

class Cat:public Animal
{
public:
	virtual void Color()
	{
		cout << "White" << endl;
	}
};
class Dog:public Animal
{
public:
	virtual void Color()
	{
		cout << "Red" << endl;
	}
};


void GetColor(Animal &r)
{
	r.Color();
}
int main(void)
{
	Dog d1;	Cat c1;
	GetColor(d1);
	GetColor(c1);


	return 0;
}