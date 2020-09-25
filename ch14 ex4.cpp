#include <iostream>

using namespace std;

template <typename T>
void swaps(T& aaa, T& bbb)
{
	T temp = aaa;
	aaa = bbb;
	bbb = temp;
}


int main()
{
	char a = 'Y';
	char  b = 'm';
	cout << a << " and " << b << endl;

	swaps(a, b);

	cout << a << " and " << b << endl;

	return 0;
}