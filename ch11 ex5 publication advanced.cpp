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
		number++;
		cout << number << ") " << "The book called " << name << " and costs " << price << "$" << endl;
	}

	virtual bool isOverSize()
	{
		return 0;
	}

private:
	string name;
	float price;
	static int number;
};
int publication::number = 0;


class book : public publication
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

	bool isOverSize()
	{
		if (page > 800)
			return 1;
		else
			return 0;
	}

private:
	int page;
};


class tape : public publication
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

	bool isOverSize()
	{
		if (timeRecording > 90)
			return 1;
		else
			return 0;
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

	int remain;
	cout << endl << "Do you wanna recognize whether a book or a tape got oversized? y/n: "; cin >> next;
	while (next == 'y')
	{
		cout << "What's number of publication do you gonna get information from? "; cin >> count;
		count--;
		remain = count % 2;		//return 0 if it's even number
		if (!remain)
		{
			if (parr[count]->isOverSize())
				cout << "The book is oversized" << endl;
			else
				cout << "The book is small" << endl;
		}
		else
		{
			if (parr[count]->isOverSize())
				cout << "The tape has too much duration" << endl;
			else
				cout << "The tape has much memory yet" << endl;
		}
		cout << "Do you recognize something else? y/n: "; cin >> next;
	}

	return 0;
}