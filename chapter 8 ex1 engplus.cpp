#include <iostream>

using namespace std;

class dist
{
public:
	dist()
	{
		feet = 0;
		inches = 0;
	}

	dist(int x, float y)
	{
		feet = x;
		inches = y;
	}

	dist operator-(dist f)
	{
		int fTemp = feet - f.feet;
		float iTemp = inches - f.inches;
		if (iTemp < 0)
		{
			iTemp += 12;
			fTemp--;
		}
		return dist(fTemp, iTemp);
	}

	void getInfo()
	{
		cout << feet << "\'" << inches << "\"" << endl;
	}

private:
	int feet;
	float inches;
};


int main()
{
	dist a(8, 3.5);
	dist b(4, 7.3);
	dist c;
	c = a - b;
	c.getInfo();

	return 0;
}