#include <iostream>
#include <string>

using namespace std;

class publication
{
public:
	virtual void putData()
	{
		cout << "name is "; cin >> name;
		cout << "price is "; cin >> price;
	}

	virtual void getData()
	{
		cout << "The book called " << name << " and costs " << price << "$" << endl;
	}

private:
	string name;
	float price;
};


class book :public publication
{
public:
	void putData()
	{
		publication::putData();
		cout << "amount of pages is "; cin >> page;
	}

	void getData()
	{
		publication::getData();
		cout << "Also the book has " << page << " pages" << endl;
	}

private:
	int page;
};


class tape :public publication
{
public:
	void putData()
	{
		publication::putData();
		cout << "Time of book typing is "; cin >> timeRecording;
	}

	void getData()
	{
		publication::getData();
		cout << "Also we have information about what's time the book is typing. Answer is " << timeRecording << " hours" << endl;
	}

private:
	float timeRecording;
};


int main()
{
	publication* parr[100];

	int count = 0;
	char next;

	do
	{
		parr[count] = new book;
		parr[count]->putData();
		count++;

		parr[count] = new tape;
		parr[count]->putData();
		count++;

		cout << "Do you wanna continue? y/n: "; cin >> next;
	} while (next == 'y');

	for (int i = 0; i < count; i++)
	{
		parr[i]->getData();
	}

	return 0;
}