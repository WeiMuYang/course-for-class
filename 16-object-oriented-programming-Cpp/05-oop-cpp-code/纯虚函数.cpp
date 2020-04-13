#include <iostream>
using namespace std;
class Animal
{
public:
	virtual void Color() = 0;
};
class Cat:public Animal
{
public:
	void Color(){
		cout << "Yellow and White" << endl;
	}
};
class Dog:public Animal
{
public:
	void Color(){
		cout << "Red" << endl;
	}
};

void GetColor(Animal *p)
{
	p->Color();
}



int main(void) {
	Dog d1;	
	Animal *p = &d1;
	GetColor(&d1);
	Cat c1;
	GetColor(&c1);

	return 0;
}
