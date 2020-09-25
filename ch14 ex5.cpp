#include <iostream>
#include <string>

using namespace std;

template <typename T>
T amax(T* arr, const int sz)
{
	T temp = *arr;
	for (int i = 0; i < sz; i++)
	{
		if (*(arr + i) > temp)
			temp = *(arr + i);
	}
	return temp;
}


int main()
{
	const int len = 10;
	char aaa[len] = { 'w','b','j','s','d','p','o','e','a','c' };
	cout << amax(aaa, len) << endl;

	return 0;
}