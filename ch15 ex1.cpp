#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void see(const float a[10])
{
	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;
	cout << "============================================" << endl;
}


int main()
{
	float arr[10];

	float temp;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " number is "; cin >> temp;
		arr[i] = temp;
	}

	see(arr);
	sort(arr, arr + 10);
	see(arr);

	return 0;
}