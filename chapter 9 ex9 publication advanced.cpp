#include <iostream>
#include <string>

using namespace std;

class sales
{
public:
	void putData()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "For " << i + 1 << " month we get: "; cin >> hz[i];
		}
	}

	void getData()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Open information... Wait please... Summary amount of money per book we get for " << i + 1 << " month " << hz[i] << "$" << endl;
		}
	}

private:
	float hz[3];
};


class publication
{
public:
	void putData()
	{
		cout << "name is "; cin >> name;
		cout << "price is "; cin >> price;
	}

	void getData()
	{
		cout << "The book called " << name << " and costs " << price << "$" << endl;
	}

private:
	string name;
	float price;
};


class publication2 : public publication
{
public:
	void putData()
	{
		publication::putData();
		cout << "what is creation data of the book: "; cin >> data;
	}
	void getData()
	{
		publication::getData();
		cout << "Creation data of this book is " << data << endl;
	}

private:
	string data;
};


class book :public publication2
{
public:
	void putData()
	{
		publication2::putData();
		cout << "amount of pages is "; cin >> page;
	}

	void getData()
	{
		publication2::getData();
		cout << "Also the book has " << page << " pages" << endl;
	}

private:
	int page;
};


class type :public publication2
{
public:
	void putData()
	{
		publication2::putData();
		cout << "Time of book typing is "; cin >> timeRecording;
	}

	void getData()
	{
		publication2::getData();
		cout << "Also we have information about what's time the book is typing. Answer is " << timeRecording << " hours" << endl;
	}

private:
	float timeRecording;
};


class disk :public publication
{
public:
	void putData()
	{
		publication::putData();
		cout << "what's type of disk? select C if it's CD type or select D if it's DVD type. you selected: ";
		char answer;
		cin >> answer;
		switch (answer)
		{
		case 'c':
			typeOf = CD;
			break;
		case 'd':
			typeOf = DVD;
			break;
		}
	}

	void getData()
	{
		publication::getData();
		cout << "Type of book's disk is ";
		if (typeOf == CD)
			cout << "CD";
		if (typeOf == DVD)
			cout << "DVD";
	}

private:
	enum typeOfIt { CD, DVD };
	typeOfIt typeOf;
};


int main()
{
	book inst;
	inst.putData();
	inst.getData();

	type i1nst;
	i1nst.putData();
	i1nst.getData();

	return 0;
}