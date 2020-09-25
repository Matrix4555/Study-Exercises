#include <iostream>
#include <string>

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
		cout << "F " << f << "." << sh << "." << p << endl;
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
		cout << "HERE " << dou << endl;
		return dou;
	}

	long getF()
	{
		return f;
	}

	int getSh()
	{
		return sh;
	}

	int getP()
	{
		return p;
	}

private:
	long f;
	int sh;
	int p;
};


class bMoney
{
public:
	bMoney()
	{
		dol = 0;
	}

	bMoney(long double a)
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

	bMoney(sterling sObj)
	{
		dol = sObj.getF() * 50;							// 1£=50$
		dol += long double(sObj.getSh()) * 0.05;		// 1 sh = 5 c		 we need decimal part to add to answer in form of fraction
		dol += long double(sObj.getP()) * 0.00415;		// 1 p = 0,415 c	 we need decimal part to add to answer in form of fraction
		int excess = dol;
		long double decimal = dol - excess;
		while (decimal > 0.99)
		{
			dol++;
			dol -= 0.1;
			decimal -= 0.1;
		}
	}

	void getMoneyString()				//from number to string
	{
		string a = to_string(dol);
		const char* mas = a.c_str();	//for insertions of array elements to new string
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

	void transformToNumber(string x)	//from string to number
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

	bMoney operator+(bMoney v)
	{
		long double answer = dol + v.dol;
		return bMoney(answer);
	}

	bMoney operator-(bMoney v)
	{
		long double answer = dol - v.dol;
		return bMoney(answer);
	}

	bMoney operator*(long double dd)
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
		return bMoney(answer);
	}

	long double operator/(bMoney v)
	{
		long double answer = dol / v.dol;
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
		return answer;
	}

	bMoney operator/(long double ss)
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
		return bMoney(answer);
	}

	operator sterling()
	{
		double d = dol;
		long ff = d;
		d -= ff;
		ff /= 50;
		double shT = d * 20;
		int shsh = shT;
		shT -= shsh;
		int pp = shT * 12;

		return sterling(ff, shsh, pp);
	}

	long double getDol()
	{
		return dol;
	}

private:
	long double dol;
};


int main()
{
	sterling a(543, 19, 11);
	bMoney b;
	a.getSterling();
	b = a;
	b.getMoneyString();

	sterling c;
	c = b;
	c.getSterling();

	return 0;
}