#include <iostream>
using namespace std;



template <typename T>
void bubbleSort(T * const arr, int size)
{
	for (int i = 0; i < size - 1; i++)//循环一次冒出一个大数
	for (int j = 0; j < size - i - 1; j++)
	{
		if (arr[j] > arr[j + 1])
		{
			T temp = arr[j];	arr[j] = arr[j + 1];	arr[j + 1] = temp;
		}
	}
}



int main(void)
{
	int arr[] = { 5, 4, 3, 2, 1 };
	bubbleSort <int>(arr,5);



	return 0;
}