#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int limit = 1000;

class myException
{
public:
	myException(int ind)
	{
		this->ind = ind;
	}
	int ind;
};


template <typename T>
class safeArray
{
public:
	safeArray(int l, int r)
	{
		left = l;
		right = r;
	}

	void putElement(int index, T value)
	{
		if (index > 0 && index < limit - 1)
			arr[index] = value;
	}

	T getElement(int index)
	{
		if (index > 0 && index < limit - 1)
			return arr[index];
	}

	T& operator[](int index)
	{
		if (index >= left && index < right)
			return arr[index];
		else
			throw myException(index);
	}

private:
	T arr[limit];
	int left;
	int right;
};


int main()
{
	const int beg = 100, end = 200;
	safeArray<char> a(beg, end);

	for (int i = beg; i < end; i++)
	{
		a[i] = 'a' + i - beg;
		cout << a[i] << endl;
	}

	try
	{
		a[79] = 'x';
		cout << "number is " << a.getElement(100) << " and " << a[100] << endl;
	}

	catch (myException ex)
	{
		cout << "you have violated boundaries of array! =(" << endl;
		cout << "exactly: " << ex.ind << " index is violated" << endl;
	}

	return 0;
}