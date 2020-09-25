#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class worker
{
public:
	worker()
	{
		name = " "; secondName = " "; lastName = " "; number = 0;
	}

	friend ostream& operator<<(ostream& s, worker& a)
	{
		s << a.number << " is " << a.lastName << " " << a.name << " " << a.secondName;
		return s;
	}

	friend istream& operator>>(istream& s, worker& a)
	{
		char temp;
		s >> a.number >> temp >> temp >> a.lastName >> a.name >> a.secondName;
		return s;
	}

	void outputWork()
	{
		ifstream fileOut("exer.txt");
		char str[200];
		int count = 0;

		while (fileOut)
		{
			str[count++] = fileOut.get();
		}
		str[count] = '\0';
		cout << str << endl;
	}

	void inputWork()
	{
		ofstream fileIn("exer.txt");
		char next;
		do
		{
			cout << "Input a data:\t"; cin >> *this;
			fileIn << *this << endl;
			cout << "next? y/n: "; cin >> next;
		} while (next == 'y');
	}

private:
	string name;
	string secondName;
	string lastName;
	int number;
};


int main()
{
	worker obj;

	obj.inputWork();
	cout << "real info:" << endl;
	obj.outputWork();

	return 0;
}