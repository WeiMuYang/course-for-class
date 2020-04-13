#include <iostream>  
#include <string>  
using namespace std;

class Base
{
public:
	virtual void display()	{ cout << "Base::display()" << endl; }
};
class Derived:public Base
{
public:
	virtual void display()	{ cout << "Derived::display()" << endl; }
};


int main(void)
{
	Base *pb;	
	Base b1;	Derived d1;
	((void (*)())**(int**)&b1)();

	return 0;
}