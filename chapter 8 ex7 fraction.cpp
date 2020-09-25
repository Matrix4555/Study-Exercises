#include <iostream>

using namespace std;

class fraction
{
public:
	fraction() { num = 0; den = 0; }
	fraction(int a, int b) { num = a; den = b; }

	fraction operator+(fraction a)
	{
		int n = num * a.den + den * a.num;
		int d = den * a.den;
		return fraction(n, d);
	}

	fraction operator-(fraction a)
	{
		int n = num * a.den - den * a.num;
		int d = den * a.den;
		return fraction(n, d);
	}

	fraction operator*(fraction a)
	{
		int n = num * a.num;
		int d = den * a.den;
		return fraction(n, d);
	}

	fraction operator/(fraction a)
	{
		int n = num * a.den;
		int d = den * a.num;
		return fraction(n, d);
	}

	bool operator==(fraction a)
	{
		float n = num;
		float d = den;
		float nO = a.num;
		float dO = a.den;
		bool answer = (n / d) == (nO / dO);
		return(answer);
	}

	bool operator!=(fraction a)
	{
		float n = num;
		float d = den;
		float nO = a.num;
		float dO = a.den;
		bool answer = (n / d) != (nO / dO);
		return(answer);
	}

	void getInfo()
	{
		cout << "answer is " << num << "/" << den << endl;
	}

	void setValues()
	{
		int x, y;
		cout << "input the numerator: "; cin >> x;
		cout << "input the denominator: "; cin >> y;
		num = x;
		den = y;
	}

	void lowTerms()
	{
		int check = 2;
		if (num % den == 0)
		{
			num /= den; den /= den;
		}
		else if (den % num == 0)
		{
			den /= num; num /= num;
		}
		else
		{
			while (check < num || check < den)
			{
				if (num % check == 0 && den % check == 0)
				{
					num /= check; den /= check;
				}
				check++;
			}
		}
	}

private:
	int num;
	int den;
};


int main()
{
	fraction a(7, 5), b(1, 5);
	fraction c = a + b, d = c - a, e = d * b, f = a / d;

	c.getInfo();
	d.getInfo();
	e.getInfo();
	f.getInfo();

	cout << "==========" << endl;

	c.lowTerms();
	d.lowTerms();
	e.lowTerms();
	f.lowTerms();

	c.getInfo();
	d.getInfo();
	e.getInfo();
	f.getInfo();

	return 0;
}