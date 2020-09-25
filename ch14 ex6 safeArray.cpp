#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int limit = 1000;

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

	T& operator[](int index)		//reference is needed because we gonna change array element in main function
	{
		if (index >= left && index < right)
			return arr[index];
		else
			cout << "YOU VIOLATED ARRAY BOUNDARIES" << endl; system("pause"); exit(1);
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

	return 0;
}