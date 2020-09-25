#include <iostream>
#include <string>
#include <cstdlib>

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
		cout << endl << "answer is " << num << "/" << den << endl;
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
	
	friend istream& operator>>(istream& s, fraction& a)
	{
		char sign;
		while (true)
		{
			s >> a.num >> sign >> a.den;
			if (cin.peek() == '\n' && a.den != 0)
			{
				cin.get();							
				break;
			}
			else
			{
				if (a.den == 0 && cin.peek() == '\n')	
					cout << "Den can't be zero. ";
				cout << "Error. Please repeat: ";
				cin.clear();							
				while (cin.get() != '\n') {}		
			}
		}
		return s;
	}

	friend ostream& operator<<(ostream& s, fraction a)
	{
		return s << a.num << "\/" << a.den;
	}

private:
	int num;
	int den;
};


int main()
{
	fraction a, b;
	char op;
	char next;

	do
	{
		cout << "input first frac: "; cin >> a;
		cout << "Input the operator: a/s/m/d - "; cin >> op;
		cout << "input second frac: "; cin >> b;
		switch (op)
		{
		case 'a':
			cout << a + b;
			break;
		case 's':
			cout << a - b;
			break;
		case 'm':
			cout << a * b;
			break;
		case 'd':
			cout << a / b;
			break;
		}
		cout << endl << "next? y/n - "; cin >> next;
	} while (next == 'y');

	return 0;
}