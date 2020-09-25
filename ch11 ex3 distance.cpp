#include <iostream>

using namespace std;

class Distance
{
public:
	Distance() : feet(0), inches(0.0)
	{  }

	Distance(int ft, float in) : feet(ft), inches(in)
	{  }

	Distance(float ff)
	{
		feet = ff / 12;
		inches = ff - feet * 12;
	}

	void showdist()
	{
		cout << feet << "\'-" << inches << '\"';
	}

	friend float square(Distance d)
	{
		float fltfeet = d.feet + d.inches / 12;
		float feetsqrd = fltfeet * fltfeet;
		return feetsqrd;
	}

	friend Distance operator*(Distance a, Distance b)		//we add "friend" to paste second argument
	{
		int f = a.feet * b.feet;
		float i = a.inches * b.inches;
		while (i >= 12)
		{
			i -= 12;
			f++;
		}
		return Distance(f, i);
	}

private:
	int feet;
	float inches;
};


int main()
{
	Distance a(53.752);
	Distance b(4, 5.6);
	Distance d(69.43);
	Distance c;
	c = 64.7 * b;
	c.showdist();

	return 0;
}