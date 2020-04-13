#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	typedef T* Iterator;
	 
public:
	MyVector();
	MyVector(const MyVector & r);
	MyVector(int *arr,size_t size);
	MyVector & operator=(const MyVector & r);
	~MyVector();
	Iterator Begin();
	Iterator End();
	size_t Size()const;
	size_t Capacity() const;
	bool Empty() const;
	T & operator[](size_t index)const;
	T & At(size_t index)const;
	T & Front()const;
	T & Back()const;
	void pushBack(const int &e);
	//
	T popBack();
	void Erase(const int pos);
	void Erase(const int first,const int last);
	void Print();
private:
	Iterator start;
	Iterator finish;
	Iterator end_of_storge;
};










#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	typedef T* Iterator;
	 
public:
	MyVector()
		:start(NULL),finish(NULL),end_of_storge(NULL){}
	MyVector(const MyVector & r)
	{
		start = new T[r.end_of_storge - r.start];
		end_of_storge = start + (r.end_of_storge - r.start);
		finish = start + (r.finish - r.start);
		for (size_t i = 0; i < (finish-start); i++)
			start[i] = r.start[i];
	}
	MyVector(Iterator arr,size_t size)
	{
		start = new T[size];
		end_of_storge = start + size;
		for (size_t i = 0; i < size; i++)
			start[i] = *arr++;
	}
	MyVector & operator=(const MyVector & r)
	{
		if (start)	delete []start;
		start = new T[r.end_of_storge - r.start];
		end_of_storge = start + (r.end_of_storge - r.start);
		finish = start + (r.finish - r.start);
		for (size_t i = 0; i < (finish-start); i++)
			start[i] = r.start[i];
		return *this;//不能丢
	}
	~MyVector()
	{
		if (start)	delete []start;
		start = NULL;
		finish = NULL;
		end_of_storge = NULL;
	}
	Iterator Begin()	{ return start;}
	Iterator End()		{ return finish;}
	size_t Size()const	{ return finish - start;}

	size_t Capacity() const {	return end_of_storge - start;}
	bool Empty() const		{   return start == finish;}
	T & operator[](size_t index)const	
	{ 
		if (index <0 || index >= (finish - start))
		{
			cout << "下标越界！" << endl;
			exit(1);
		}
		return start[index];
	}
	T & At(size_t index)const
	{
		if (index < 0 || index >= (finish - start))
		{
			cout << "下标越界！" << endl;
			exit(1);
		}
		return start[index];
	}
	T & Front()const	{ return *start;}
	T & Back()const		{ return *(finish-1);}
	void pushBack(const int &e)
	{
		if ( finish == end_of_storge)
		{
			Iterator temp = new T[(end_of_storge - start)*2 + 1];
			int len = finish - start;
			for (size_t i = 0; i < len; i++)
				temp[i] = start[i];
			start = temp;
			finish = start + len;
			end_of_storge = start + 2 * len + 1;
		}
		*finish++ = e;
	}
	T popBack()
	{
		if ( finish == start)
		{
			cout << "容器为空，不能删除元素！" << endl;
			exit(1);
		}
		return *--finish;
	}
	void Erase(const int pos)
	{
		if( pos < 0 || pos >= (finish - start))
		{
			cout << "下标越界！" << endl;
			exit(1);
		}
		int len = finish-start;
		for (size_t i = 0; i < len -1 -pos; i++)
		{
			start[pos+i] = start[pos+1+i];
		}
		finish --;
	}
	void Erase(const int first,const int last)
	{
		if( first < 0 || last >= (finish - start) || first > last)
		{
			cout << "下标越界！" << endl;
			exit(1);
		}
		int len = finish-start;
		int num = last - first + 1;
		for (size_t i = 0; i < len - 1 - last; i++)
		{
			start[first+i] = start[first + num + i];
		}
		finish -= num;
	}
	void Print()
	{
		for (size_t i = 0; i < Size(); i++)
		{
			cout << start[i] << endl;
		}
	}
private:
	Iterator start;
	Iterator finish;
	Iterator end_of_storge;
};

int main(void)
{
	MyVector<int> a;
	for (int i = 0; i < 5; i++)
	{
		a.pushBack(i);
	}
	a.Print();
	MyVector<int> b ;
	b = a;
	b.Erase(0,3);
	b.Print();


	return 0;
}

