#include <iostream>

using namespace std;

class time
{
public:
	time()
	{
		s = 0; m = 0; h = 0;
	}

	time(int x, int y, int z)
	{
		h = x, m = y, s = z;
	}

	time operator+(time temp)
	{
		int ts = s + temp.s;
		int tm = m + temp.m;
		int th = h + temp.h;
		if (ts > 59)
		{
			ts -= 60;
			tm++;
		}
		if (tm > 59)
		{
			tm -= 60;
			th++;
		}
		return time(th, tm, ts);
	}

	time operator-(time temp)
	{
		int ts = s - temp.s;
		int tm = m - temp.m;
		int th = h - temp.h;
		if (ts < 0)
		{
			ts += 60;
			tm--;
		}
		if (tm < 0)
		{
			tm += 60;
			th--;
		}
		return time(th, tm, ts);
	}

	time operator*(time temp)
	{
		int ts = s * temp.s;
		int tm = m * temp.m;
		int th = h * temp.h;
		while (ts > 59)
		{
			ts -= 60;
			tm++;
		}
		while (tm > 59)
		{
			tm -= 60;
			th++;
		}
		return time(th, tm, ts);
	}

	time operator++()
	{
		int a = ++h;
		int b = ++m;
		int c = ++s;
		if (s > 59)
		{
			s -= 60;
			m++;
		}
		if (m > 59)
		{
			m -= 60;
			h++;
		}
		return time(a, b, c);
	}

	time operator++(int)
	{
		int a = ++h;
		int b = ++m;
		int c = ++s;
		if (s > 59)
		{
			s -= 60;
			m++;
		}
		if (m > 59)
		{
			m -= 60;
			h++;
		}
		return time(a, b, c);
	}

	time operator--()
	{
		int a = --h;
		int b = --m;
		int c = --s;
		if (s < 0)
		{
			s += 60;
			m--;
		}
		if (m < 0)
		{
			m += 60;
			h--;
		}
		return time(a, b, c);
	}

	time operator--(int)
	{
		int a = --h;
		int b = --m;
		int c = --s;
		if (s < 0)
		{
			s += 60;
			m--;
		}
		if (m < 0)
		{
			m += 60;
			h--;
		}
		return time(a, b, c);
	}

	void getInfo()
	{
		if (h < 10)
			cout << "0";
		cout << h << " : ";
		if (m < 10)
			cout << "0";
		cout << m << " : ";
		if (s < 10)
			cout << "0";
		cout << s << endl;
	}

private:
	int s;
	int m;
	int h;
};


int main()
{
	time a(20, 01, 59), b(3, 22, 30), c = a - b;
	a.getInfo();
	b.getInfo();
	c.getInfo();

	return 0;
}