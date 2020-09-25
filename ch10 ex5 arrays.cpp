#include <iostream>

using namespace std;

void addarrays(float* ar1, float* ar2, float* ar3, int len)
{
	for (int i = 0; i < len; i++)
		*(ar3 + i) = *(ar1 + i) + *(ar2 + i);
}


int main()
{
	const int size = 5;
	float arr1[size] = { 33.6,47.2,78.9,37.23,19.1 };
	float arr2[size] = { 5.6,4.3,8.99,22.17,6.3 };
	float arr3[size];

	addarrays(arr1, arr2, arr3, size);

	for (int i = 0; i < size; i++)
		cout << *(arr3 + i) << endl;

	return 0;
}