#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class time
{
public:
	time()
	{
		h = 0; m = 0; s = 0;
	}

	void setTime()
	{
		while (true)
		{
			cout << "put h: ";
			cin.clear();
			cin >> h;
			if (h > 23)
			{
				cin.clear(ios::failbit);
				cout << "incorrect, please repeat" << endl;
			}
			if (cin.good())
				break;
		}
		while (true)
		{
			cout << "put m: ";
			cin.clear();
			cin >> m;
			if (m > 59)
			{
				cin.clear(ios::failbit);
				cout << "incorrect, please repeat" << endl;
			}
			if (cin.good())
				break;
		}
		while (true)
		{
			cout << "put s: ";
			cin.clear();
			cin >> s;
			if (s > 59)
			{
				cin.clear(ios::failbit);
				cout << "incorrect, please repeat" << endl;
			}
			if (cin.good())
				break;
		}
	}

	void getTime()
	{
		cout << h << ":" << m << ":" << s << endl;
	}

private:
	int h;
	int m;
	int s;
};


int main()
{
	time car;
	char next;
	do
	{
		car.setTime();
		cout << "The time is ";
		car.getTime();
		cout << "Do you wanna continue? y/n "; cin >> next;
	} while (next == 'y');

	return 0;
}