#include <iostream>

using namespace std;

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
		*(ap + j) = new int[maxSize];

	ap[7][3] = 5;

	cout << *(*(ap + 7) + 3) << endl;
	cout << ap[7][3] << endl;

	return 0;
}