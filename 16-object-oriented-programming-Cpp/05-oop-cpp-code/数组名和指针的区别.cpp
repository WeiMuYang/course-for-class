#include <iostream>
using namespace std;

void printArr(int p[], const int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        cout << *(p+i) << " ";
    }
    cout << endl;
    return;
}
int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};  int k = 0;
	int *p = &k;
	cout << p[0] << endl;

	printArr(arr, 10);
    return 0;
}