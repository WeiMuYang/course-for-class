#include <iostream>
using namespace std;

class MyVector
{
public:

public:
	MyVector();
	MyVector(const MyVector & r);
	MyVector(int *arr,size_t size);
	MyVector & operator=(const MyVector & r);
	~MyVector();
	int * Begin();
	int * End();
	size_t Size()const;
	size_t Capacity() const;
	bool Empty() const;
	int & operator[](size_t index)const;
	int & At(size_t index)const;
	int & Front()const;
	int & Back()const;
	void pushBack(const int &e);
	//
	int popBack();
	void Erase(const int pos);
	void Erase(const int first,const int last);
	void Print();
private:
	int* start;
	int* finish;
	int* end_of_storge;
};
MyVector::MyVector()
	:start(NULL),finish(NULL),end_of_storge(NULL){}
MyVector::MyVector(const MyVector & r)
	:start(new int[r.end_of_storge - r.start])
	,finish(start + (r.finish - r.start))
	,end_of_storge(start + (r.end_of_storge - r.start))
{
	for (int i = 0; i < (finish-start); i++)
	{
		start[i] = r.start[i];
		//*(start+i) = *(r.start+i);
	}
	//或者
	//int *t = start;	int *rt = r.start;
	//while (t < finish)
	//{
	//	*t++ = *(rt++);
	//}
}
MyVector::MyVector(int *arr,size_t size)
{
	start = new int[size];
	finish = start;
	end_of_storge = start + size;
	for (size_t i = 0; i < size; i++)
	{
		start[i] = arr[i];
		finish++;
	}
}
MyVector & MyVector::operator=( const MyVector & r)
{
	if(start != NULL)  delete []start;
	start = new int[r.end_of_storge - r.start];
	finish = start + (r.finish - r.start);
	end_of_storge = start + (r.end_of_storge - r.start);
	for (size_t i = 0; i < (finish-start); i++)
	{
		start[i] = r.start[i];
		//*(start+i) = *(r.start+i);
	}
	return *this;
}
MyVector::~MyVector()
{
	if(start) delete []start;
	start = NULL;
	finish = NULL;
	end_of_storge = NULL;
}
int * MyVector::Begin()
{
	return start;
}
int * MyVector::End(){//最后元素的下一个元素
	return finish;
}
			
size_t MyVector::Size()const
{
	return finish - start;
}
size_t MyVector::Capacity() const
{
	return end_of_storge - start;
}
bool MyVector::Empty() const
{
	return start == finish;
}
int & MyVector::operator[](size_t index)const
{
	if ( index < 0 || index >= (finish - start))
	{
		cout << " 下标越界" << endl;
		exit(1);
	}
	return start[index];//*(start+index);
}
int & MyVector::At(size_t index)const
{
	if ( index < 0 || index >= (finish - start))
	{
		cout << " 下标越界" << endl;
		exit(1);
	}
	return start[index];
}
int & MyVector::Front()const
{
	return *start;
}
int & MyVector::Back()const
{
	return *(finish-1);//finish[-1];
}
void MyVector::pushBack(const int &e)
{
	if (finish == end_of_storge)
	{
		int * temp = new int[(finish - start) * 2 + 1];
		int len = finish - start;
		for (int i = 0; i < len; i++)
			temp[i] = start[i];
		if(start)	delete []start;
		start = temp;
		finish = start + len;
		end_of_storge = start + len * 2 + 1;
	}
	*finish++ = e;
}
//
int MyVector::popBack()
{
	return *--finish;
}

void MyVector::Erase(const int pos)
{
	int len = finish - start;
	if (pos >= len || pos < 0)
	{
		cout << "下标越界!" << endl;
		exit(1);
	}
	for (int i = 0; i < (len - pos); i++)
	{
		start[pos + i] = start[pos + i + 1];
	}
	finish--;
}
void MyVector::Erase(const int first,const int last)
{
	int len = finish - start;
	if (last >= len || first < 0 || first > last)
	{
		cout << "下标有误!" << endl;
		exit(1);
	}
	int num = last - first + 1;
	for (int i = 0; i < len - last - 1; i++)
	{
		start[first + i] = start[first + i + num ];
	}
	finish = finish - num;
}
void MyVector::Print()
{
	for (int i = 0; i < Size(); i++)
		cout << At(i) << endl;
}
int main(void)
{
	MyVector a;
	for (int i = 0; i < 5; i++)
	{
		a.pushBack(i);
	}
	a.Print();
	
	a.Erase(0,2);
	a.Print();


	return 0;
}

