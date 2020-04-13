#include <iostream>
using namespace std;
class Base
{
public:
	virtual void display()
	{
		cout << "Base::display()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void display()
	{
		cout << "Derived::display()" << endl;
	}
};
class Other
{

};


int main(void) {
	Base b1;	Derived d1;	Other o1;
	cout << sizeof(b1) << endl;
	cout << sizeof(d1) << endl;
	cout << sizeof(o1) << endl;
	((void(*)())(**(int **)&b1))();
	((void(*)())(**(int **)&d1))();

	
	return 0;
}