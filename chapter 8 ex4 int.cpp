#include <iostream>

using namespace std;

class Int
{
public:
	Int() { value = 0; }
	Int(int aaa) { value = aaa; }

	Int operator+(Int a)
	{
		long double te = rich + a.rich;
		check(te);
		int temp = set(te);
		return Int(temp);
	}

	Int operator-(Int a)
	{
		long double te = rich - a.rich;
		check(te);
		int temp = set(te);
		return Int(temp);
	}

	Int operator*(Int a)
	{
		long double te = rich * a.rich;
		check(te);
		int temp = set(te);
		return Int(temp);
	}

	Int operator/(Int a)
	{
		if (a.rich == 0)
			cout << "You use zero like divider. That's awful!(" << endl; system("pause"); exit(1);
		long double te = rich / a.rich;
		check(te);
		int temp = set(te);
		return Int(temp);
	}

	void getInfo()
	{
		cout << "answer is " << value << endl;
	}

	void setVar(long double var)
	{
		rich = var;
	}

private:
	int value;
	long double rich;

	void check(long double pro)
	{
		long double rake = 2147483647;
		if (pro > rake || pro < -rake)
		{
			cout << "You violated the boundaries of this number type!!! Bye!(" << endl;
			system("pause");
			exit(1);
		}
	}

	int set(long double yes)
	{
		int poor = static_cast<int>(yes);
		return poor;
	}
};


int main()
{
	Int a, b, c, d, e, f, g, z;
	a.setVar(6);
	b.setVar(7);
	c.setVar(3);
	z.setVar(0);
	Int kill;
	kill.setVar(2147483642);
	d = a + b;		//13
	d.getInfo();
	e = b - c;		//4
	e.getInfo();
	f = b * c;		//27
	f.getInfo();

	g = kill + a;
	g.getInfo();

	return 0;
}