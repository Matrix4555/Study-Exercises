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

	string getMoneyString()					//from number to string
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
		//cout << s << endl;
		return s;
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

	friend ostream& operator<<(ostream& s, money& a)
	{
		return s << a.getMoneyString();
	}

	friend istream& operator>>(istream& s, money& a)
	{
		return s >> a.dol;
	}

private:
	long double dol;
};


int main()
{
	money a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << c << endl;
	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	return 0;
}