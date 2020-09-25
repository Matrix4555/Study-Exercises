#include <iostream>

using namespace std;

class Array
{
public:
	Array(int s)
	{
		size = s;
		ptr = new int[s];
	}

	Array(Array& a)
	{
		size = a.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			*(ptr + i) = a[i];
	}

	~Array()
	{
		delete[] ptr;
	}

	int& operator[](int index)
	{
		return *(ptr + index);
	}

	Array& operator=(Array& a)
	{
		delete[] ptr;
		size = a.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(ptr + i) = a[i];
		}
		return *this;
	}

private:
	int* ptr;
	int size;
};


int main()
{
	Array arr1(5);
	Array arr3(5);

	Array arr2(arr1);
	arr3 = arr1;

	return 0;
}