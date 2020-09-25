#include <iostream>

using namespace std;

template<typename T>
class fraction
{
public:
	fraction() { num = 0; den = 0; }
	fraction(T a, T b) { num = a; den = b; }

	fraction operator+(fraction a)
	{
		T n = num * a.den + den * a.num;
		T d = den * a.den;
		return fraction(n, d);
	}

	fraction operator-(fraction a)
	{
		T n = num * a.den - den * a.num;
		T d = den * a.den;
		return fraction(n, d);
	}

	fraction operator*(fraction a)
	{
		T n = num * a.num;
		T d = den * a.den;
		return fraction(n, d);
	}

	fraction operator/(fraction a)
	{
		T n = num * a.den;
		T d = den * a.num;
		return fraction(n, d);
	}

	void getInfo()
	{
		cout << endl << "answer is " << num << "/" << den << endl;
	}

	void setValues()
	{
		T x, y;
		cout << "input the numerator: "; cin >> x;
		cout << "input the denominator: "; cin >> y;
		num = x;
		den = y;
	}
	
private:
	T num;
	T den;
};


int main()
{
	fraction<char> a('f', 'r'), b('a', 'c'), c;
	c = a + b;
	c.getInfo();
	c = a - b;
	c.getInfo();
	c = a * b;
	c.getInfo();
	c = a / b;
	c.getInfo();

	return 0;
}