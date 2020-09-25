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

	void ldtoms()						//from number to string
	{
		string a = to_string(dol);
		const char* mas = a.c_str();	//for insertions of array elements to new string
		string s = "$";
		string temp;
		bool decimal = true;
		for (int i = a.length() - 1, count = -1; i >= 0; i--)
		{
			if (decimal && mas[i] == '0')
				continue;
			if (!decimal)
				count++;
			if (count == 3)
			{
				count = 0;
				s.insert(1, ",");
			}
			if (mas[i] == '.')
				decimal = false;
			temp = mas[i];
			s.insert(1, temp);
		}
		cout << s;
	}

	void putMoney(string x)				//from string to number
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

	long double getMoney()
	{
		return dol;
	}

	void madd(long double x, long double y)
	{
		dol = x + y;
	}

private:
	long double dol;
};


int main()
{
	string a, b;
	cout << "input 1st number: "; cin >> a;
	cout << "input 2nd number: "; cin >> b;
	money first, second;
	first.putMoney(a);
	second.putMoney(b);
	money third;
	third.madd(first.getMoney(), second.getMoney());
	third.ldtoms();

	return 0;
}