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
		s << a.lastName << " " << a.name << " " << a.secondName << " has " << a.number << " number";
		return s;
	}

	friend istream& operator>>(istream& s, worker& a)
	{
		char temp;
		s >> a.lastName >> a.name >> a.secondName >> temp >> temp >> temp >> a.number;
		return s;
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
	ofstream myFile;
	myFile.open("muu.txt");
	char next;
	const int max = 1000;
	char word[max];

	do
	{
		cout << "input an info: ";
		cin >> obj;
		myFile << obj << endl;
		cout << "Continue? y/n: "; cin >> next;
	} while (next == 'y');

	myFile.close();
	ifstream filee("muu.txt");
	int count = 0;

	while (!filee.eof())
	{
		word[count++] = filee.get();
	}

	cout << endl << endl << endl << "GETTING AN INFO: " << endl;
	word[count] = '\0';
	cout << word << endl;

	return 0;
}