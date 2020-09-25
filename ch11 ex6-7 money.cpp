#include <iostream>
#include <string>

using namespace std;

class money
{
public:
	money()
	{
		dol = 0;
	}

	money(long double a)
	{
		if (a < 9999999999999990.00)
			dol = a;
		else
		{
			cout << "Your variable is too large" << endl;
			system("pause");
			exit(1);
		}
	}

	void getMoneyString()					//from number to string
	{
		string a = to_string(dol);
		const char* mas = a.c_str();		//for insertions of array elements to new string
		string s = "$";
		string temp;
		bool decimal = true;
		bool deleteZero = true;
		for (int i = a.length() - 1, count = -1; i >= 0; i--)
		{
			////////////////////////////////////
			if (mas[i] != '0')
				deleteZero = false;
			if (deleteZero && mas[i] == '0')
				continue;
			////////////////////////////////////
			if (!decimal)
				count++;
			if (mas[i] == '.')
				decimal = false;
			////////////////////////////////////
			if (count == 3)
			{
				count = 0;
				s.insert(1, ",");
			}
			temp = mas[i];
			s.insert(1, temp);
		}
		cout << s << endl;
	}

	void transformToNumber(string x)		//from string to number
	{
		const char* arr = x.c_str();
		string number;
		for (int i = 0; i < x.length(); i++)
		{
			if (arr[i] != '$' && arr[i] != ',')
				number += arr[i];
		}
		cout << number << endl;
		const char* elseArr = number.c_str();
		dol = atof(elseArr);
	}

	void getMoney()
	{
		cout << dol << endl;
	}

	money operator+(money v)
	{
		long double answer = dol + v.dol;
		return money(answer);
	}

	money operator-(money v)
	{
		long double answer = dol - v.dol;
		return money(answer);
	}

	money operator*(long double dd)
	{
		long double answer = dol * dd;
		////////////////////////////////
		int i = answer;
		long double change = answer - i;
		while (change >= 0.1)
		{
			change -= 0.1;
			answer -= 0.1;
			answer++;
		}
		////////////////////////////////
		return money(answer);
	}

	money operator/(long double ss)
	{
		long double answer = dol / ss;
		////////////////////////////////
		int i = answer;
		long double change = answer - i;
		while (change >= 0.1)
		{
			change -= 0.1;
			answer -= 0.1;
			answer++;
		}
		////////////////////////////////
		return money(answer);
	}

	friend money operator*(money a, money b)
	{
		long double answer = a.dol * b.dol;
		return money(answer);
	}

	friend money operator/(money a, money b)
	{
		long double answer = a.dol / b.dol;
		return money(answer);
	}

	friend money round(money a)
	{
		int whole = a.dol;
		float remain = a.dol - whole;
		if (remain >= 0.5)
			return money(++whole);
		else
			return money(whole);
	}

private:
	long double dol;
};


int main()
{
	money a(4.732);
	money b(33.76);
	money c(28.43);
	money d(37.1);
	money e(78.012);
	money f(12.301);
	money answer;

	answer = (a * 44.5 + b / c - d / (4.55 / e) + (78.3 * f)) + 54.2;
	answer.getMoney();
	answer.getMoneyString();

	money g;
	money h = 5.50;
	g = round(h);
	g.getMoney();

	return 0;
}