#include <iostream>
#include <ctime>

using namespace std;

const int limit = 1000;

class safeArray
{
public:
	int left;
	int right;

	safeArray()
	{
		left = 0;
		right = 0;
	}

	void putElement(int index, int value)
	{
		if (index > 0 && index < limit - 1)
			arr[index] = value;
	}

	int getElement(int index)
	{
		if (index > 0 && index < limit - 1)
			return arr[index];
	}

	int& operator[](int index) // ссылка нужна для того чтобы мы изменяли элемент в массиве из функции main
	{
		if (index >= left && index < right)
			return arr[index];
		else
			cout << "YOU VIOLATED ARRAY BOUNDARIES" << endl; system("pause"); exit(1);
	}

private:
	int arr[limit];
};


class safehilo :public safeArray
{
public:
	safehilo(int l, int r)
	{
		left = l;
		right = r;
	}
};


int main()
{
	srand(time(NULL));

	const int beg = 100, end = 200;
	safehilo a(beg, end);

	for (int i = beg; i < end; i++)
	{
		a.putElement(i, rand());
	}

	for (int i = beg; i < end; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}