#include <iostream>
#include <string>

using namespace std;

template <typename T>
T average(T name[], int sz)
{
	T whole = 0;
	for (int i = 0; i < sz; i++)
		whole += name[i];
	return whole / sz;
}


int main()
{
	int i[7] = { 1,2,3,4,5,6,7 };
	long l[5] = { 4352,4523565,14356,6575,4352 };
	double d[6] = { 345.6453,1345.75,546.765,356.121, 54.87, 431.5 };
	char c[4] = { 'r', 'y', 'c', 'p' };

	cout << average(i, 7) << endl;
	cout << average(l, 5) << endl;
	cout << average(d, 6) << endl;
	cout << average(c, 4) << endl;

	return 0;
}