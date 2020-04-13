#include <iostream>
#include <string>
using namespace std;
class A
{  	int  i, j;
  	public:
   	A() { i=j=0; }
};
class B
{  	A *p;
  	public:
   	 B()  {  p = new A;  }
   	~B() {  delete p;  }
};
void f(B x)
{ 
}
void main()
{	B b;
  	f(b);
}