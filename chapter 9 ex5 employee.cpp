#include <iostream>
#include <string>

using namespace std;

const int LEN = 80;

class employee
{
public:
	void getdata()
	{
		cout << "\n  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";     cin >> number;
	}

	void putdata() const
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}

private:
	char name[LEN];
	unsigned long number;
};


class manager : public employee
{
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите должность: "; cin >> title;
		cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n  Должность: " << title;
		cout << "\n  Сумма взносов в гольф-клуб: " << dues;
	}

private:
	char title[LEN];
	double dues;
};


class scientist : public employee
{
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите количество публикаций: "; cin >> pubs;
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n  Количество публикаций: " << pubs;
	}

private:
	int pubs;
};


class laborer : public employee
{

};


class employee2 : public employee
{
public:
	void getdata()
	{
		cout << "size of compensation is "; cin >> compensation;
		char answer;
		cout << "this per what's period? h/w/m - "; cin >> answer;
		switch (answer)
		{
		case 'h':
			period = forHour;
			break;
		case 'w':
			period = forWeek;
			break;
		case 'm':
			period = forMonth;
			break;
		}
	}

	void putdata()
	{
		cout << endl << "This employee will get " << compensation << "$ compensation per ";
		if (period == forHour)
			cout << "hour-period";
		if (period == forWeek)
			cout << "week-period";
		if (period == forMonth)
			cout << "month-period";
		cout << endl;
	}

private:
	double compensation;
	enum periodIs { forHour, forWeek, forMonth };
	periodIs period;
};


class manager2 :public employee2, public manager
{
public:
	void getdata()
	{
		manager::getdata();
		employee2::getdata();
	}

	void putdata()
	{
		manager::putdata();
		employee2::putdata();
	}
};


class scientist2 :public employee2, public scientist
{
public:
	void getdata()
	{
		scientist::getdata();
		employee2::getdata();
	}

	void putdata()
	{
		scientist::putdata();
		employee2::putdata();
	}
};


class laborer2 :public employee2, public laborer
{
public:
	void getdata()
	{
		laborer::getdata();
		employee2::getdata();
	}

	void putdata()
	{
		laborer::putdata();
		employee2::putdata();
	}
};


int main()
{
	setlocale(LC_ALL, ("rus"));
	manager2 m;
	scientist2 s;
	laborer2 l;

	m.getdata();
	cout << endl;
	m.putdata();
	cout << endl;

	s.getdata();
	cout << endl;
	s.putdata();
	cout << endl;

	l.getdata();
	cout << endl;
	l.putdata();
	cout << endl;

	return 0;
}