#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class myException
{
public:
	myException(int a)
	{
		errorCode = a;
	}

	int errorCode;
};


bool isFeet(string);


class Distance
{
public:
	Distance()
	{
		feet = 0; inches = 0.0;
	}

	Distance(int ft, float in)
	{
		if (ft > 999 || ft < -999 || in >= 12 || in < 0)
			throw myException(1);
		feet = ft; inches = in;
	}

	void showdist()
	{
		cout << feet << "\'-" << inches << '\"';
	}

	void getdist();

private:
	int feet;
	float inches;
};


void Distance::getdist()
{
	string instr;
	while (true)
	{
		cout << "\n\nВведите футы: ";
		cin.unsetf(ios::skipws);
		cin >> instr;
		if (isFeet(instr))
		{
			cin.ignore(10, '\n');
			feet = atoi(instr.c_str());
			break;
		}
		cin.ignore(10, '\n');						
		cout << "Футы должны быть целыми < 1000\n";
	}
	while (true)
	{
		cout << "Введите дюймы: ";
		cin.unsetf(ios::skipws);
		cin >> inches;
		if (inches >= 12.0 || inches < 0.0)
		{
			throw myException(2);
			cout << "Дюймы должны быть между 0.0 и 11.99\n";
		}
		if (cin.good())
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		throw myException(3);
		cout << "Неверно введены дюймы\n";
	}
}


bool isFeet(string str)
{
	int slen = str.size();
	if (slen == 0 || slen > 5)
	{
		cin.clear();
		throw myException(4);
	}
	for (int j = 0; j < slen; j++)
		if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
			throw myException(5);
	double n = atof(str.c_str());
	if (n < -999.0 || n>999.0)
		throw myException(6); 
	return true;
}


int main()
{
	setlocale(LC_ALL, "ru");
	Distance d;
	char ans;

	do
	{
		try
		{
			d.getdist();
			cout << "\nРасстояние = ";
			d.showdist();
		}
		catch (myException ex)
		{
			switch (ex.errorCode)
			{
			case 1:
				cout << ":(\nYou improperly set values in constructor for class." << endl;
				break;
			case 2:
				cout << ":(\nInches should be between 0.0 and 11.99." << endl;
				break;
			case 3:
				cout << ":(\nImproperly inputed an inches." << endl;
				break;
			case 4:
				cout << ":(\nFeets inputed improperly. Maybe you inputed bigger value or nothing even." << endl;
				break;
			case 5:
				cout << ":(\nYou inputed extraneous symbols." << endl;
				break;
			case 6:
				cout << ":(\nYou seted very big than 999.0 feets of very small than -999.0." << endl;
				break;
			}
		}
		cout << "\nЕще раз (y/n)? ";
		cin.ignore(10, '\n');
		cin >> ans;
		cin.ignore(10, '\n');
	} while (ans != 'n');

	return 0;
}