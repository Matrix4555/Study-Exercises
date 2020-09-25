#include <iostream>

using namespace std;

float* avera(float mas[10])
{
	float yyy = 0;
	float* t = &yyy;
	for (int i = 0; i < 10; i++)
		*t += *(mas + i);
	*t /= 10;
	return t;
}


int main()
{
	float arr[10];
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " number is ";
		cin >> *(arr + i);
	}

	cout << *(avera(arr)) << endl;

	return 0;
}