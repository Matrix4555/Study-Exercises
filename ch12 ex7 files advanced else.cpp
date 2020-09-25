#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class worker
{
public:
	worker() : name(" "), secondName(" "), lastName(" "), number(0)
	{
		filehp.open("exxxer.txt", ios::app | ios::in | ios::out | ios::binary);
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
		char str[200];
		int count = 0;

		while (filehp)
		{
			str[count++] = filehp.get();
		}
		str[count] = '\0';
		cout << str << endl;
	}

	void inputWork()
	{
		char next;
		do
		{
			cout << "Input a data:\t"; cin >> *this;
			filehp << *this << endl;
			cout << "next? y/n: "; cin >> next;
		} while (next == 'y');
	}

	static void ptrReplacement();

private:
	static fstream filehp;
	string name;
	string secondName;
	string lastName;
	int number;
};
fstream worker::filehp;


void worker::ptrReplacement()
{
	filehp.seekg(0);
}


int main()
{
	worker obj;
	obj.inputWork();
	obj.ptrReplacement();
	obj.outputWork();

	return 0;
}