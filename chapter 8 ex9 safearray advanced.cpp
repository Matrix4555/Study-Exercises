#include <iostream>
#include <ctime>

using namespace std;

const int limit = 1000;

class safeArray
{
public:
	safeArray(int l, int r)
	{
		left = l;
		right = r;
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
	int left;
	int right;
};


int main()
{
	srand(time(NULL));

	const int beg = 100, end = 200;
	safeArray a(beg, end);

	const int size = end - beg;
	int mas[size];

	for (int i = beg, j = 0; i < end; i++, j++)
	{
		mas[j] = a[i] = rand();
	}

	cout << a[100] << endl;
	cout << mas[0] << endl;
	cout << a[199] << endl;
	cout << mas[99] << endl;

	return 0;
}