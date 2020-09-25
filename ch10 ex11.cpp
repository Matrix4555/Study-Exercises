#include <iostream>

using namespace std;

class someArr
{
public:
	int& operator[](int index)
	{
		//return *(arr+index);
		return *(arr + index);
	}

	int* operator+(int ind)
	{
		int* temp = arr + ind;
		return temp;
	}

private:
	enum { size = 100 };
	int arr[size];
};


int main()
{
	/*
	int a0[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a3[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a4[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a5[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a6[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a7[] = { 1,2,3,4,5,6,743,8,9,10 };
	int a8[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a9[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ap[] = { a0,a1,a2,a3,a4,a5,a6,a7,a8,a9 };
	*/

	const int numArrays = 10;
	const int maxSize = 10;
	int* ap[numArrays];

	for (int j = 0; j < numArrays; j++)
	{
		*(ap + j) = new int[maxSize];
		for (int k = 0; k < maxSize; k++)
		{
			*(*(ap + j) + k) = j * 10;
		}
	}

	someArr abc;

	for (int j = 0, i = 0; j < numArrays; j++)
		for (int k = 0; k < maxSize; k++, i++)
			abc[i] = *(*(ap + j) + k);

	for (int y = 0; y < (numArrays * maxSize); y++)
		cout << *(abc + y) << "\t";

	return 0;
}