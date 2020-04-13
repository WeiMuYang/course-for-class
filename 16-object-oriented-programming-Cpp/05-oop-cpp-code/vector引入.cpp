#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	cout << a.capacity() << endl;

	
	return 0;
}