#include <iostream>

using namespace std;

class sterling
{
public:
	sterling() { f = 0; sh = 0; p = 0; }
	sterling(long a) { f = a; sh = 0; p = 0; }
	sterling(long a, int b, int c) { f = a; sh = b; p = c; }

	sterling(double doo)		//permutation from double to sterling
	{
		f = doo;
		doo -= f;
		sh = doo *= 20;
		doo -= sh;
		p = doo * 12;
	}

	void getSterling()
	{
		cout << "$" << f << "." << sh << "." << p << endl;
	}

	void putSterling(long a, int b, int c)
	{
		f = a; sh = b; p = c;
	}

	sterling operator+(sterling a)
	{
		long aa = f;
		int bb = sh, cc = p;
		return sterling(double(sterling(aa, bb, cc)) + double(a));
	}

	sterling operator-(sterling a)
	{
		long aa = f;
		int bb = sh, cc = p;
		return sterling(double(sterling(aa, bb, cc)) - double(a));
	}

	sterling operator*(sterling a)
	{
		long aa = f;
		int bb = sh, cc = p;
		return sterling(double(sterling(aa, bb, cc)) * double(a));
	}

	sterling operator/(sterling a)
	{
		long aa = f;
		int bb = sh, cc = p;
		return sterling(double(sterling(aa, bb, cc)) / double(a));
	}

	sterling operator/(double a)
	{
		sterling obj(f, sh, p);
		double objDouble = double(obj);
		objDouble /= a;
		obj = sterling(objDouble);
		return sterling(obj.f, obj.sh, obj.p);
	}

	operator double()			//permutation from sterling to double
	{
		double dou = f;
		dou += double(sh) / 20;
		dou += double(p) / 12 / 20;
		return dou;
	}

private:
	long f;
	int sh;
	int p;
};


int main()
{
	sterling a(87, 19, 11);
	sterling b(3, 10, 13);
	sterling c;

	c = a + b;
	c.getSterling();
	cout << endl;

	c = a - b;
	c.getSterling();
	cout << endl;

	c = a * b;
	c.getSterling();
	cout << endl;

	c = a / b;
	c.getSterling();
	cout << endl;

	double del = 5.4;
	c = a / del;
	c.getSterling();
	cout << endl;

	return 0;
}