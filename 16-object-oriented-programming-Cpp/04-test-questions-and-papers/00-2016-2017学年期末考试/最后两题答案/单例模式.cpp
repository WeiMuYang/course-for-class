#include <iostream>
using namespace std;
class Mouse
{
public:
	static Mouse *GetMouse();
private:
	Mouse();
	static Mouse *pobj;
};
Mouse *Mouse::pobj = NULL;
Mouse::Mouse()
{
}
Mouse *Mouse::GetMouse()
{
	if(pobj == NULL)
		pobj = new Mouse;
	return pobj;
}
int main(void)
{
	Mouse *p1 = Mouse::GetMouse();
	Mouse *p2 = p1->GetMouse();


	return 0;
}