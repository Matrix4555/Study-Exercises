#include <iostream>

using namespace std;

const int limit = 100;

class safeArray
{
public:
	void putel(int index, int value)
	{
		if (index > 0 && index < limit - 1)
			arr[index] = value;
	}

	int getel(int index)
	{
		if (index > 0 && index < limit - 1)
			return arr[index];
	}

private:
	int arr[limit];
};


int main()
{
	safeArray saf;
	int temp = 12345;
	saf.putel(7, temp);
	int a;
	a = saf.getel(7);
	cout << a;

	return 0;
}