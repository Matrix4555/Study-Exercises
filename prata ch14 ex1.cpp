#include <iostream>
#include <string.h>
#include <valarray>

using namespace std;

template<typename T1, typename T2>		// forward declaration
class Pair;

using ArrayInt = valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;

template<typename T1, typename T2>
class Pair
{
public:
	Pair() { }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) { }
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair<T1, T2>& operator=(const Pair<T1, T2>& t);
private:
	T1 a;
	T2 b;
};

template<typename T1, typename T2>
T1& Pair<T1, T2>::first() { return a; }

template<typename T1, typename T2>
T2& Pair<T1, T2>::second() { return b; }

template<typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair<T1, T2>& t)
{
	a = t.a;
	b = t.b;
	return *this;
}

class Wine
{
public:
	Wine();
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	~Wine();
	void GetBottles();
	const char* Label() const;
	const int sum() const;
	void show() const;
private:
	PairArray pairs;
	char* label;
	int years;
};

Wine::Wine() : years(0), label(nullptr), pairs(ArrayInt(), ArrayInt())
{ }

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : years(y), pairs(ArrayInt(yr, y), ArrayInt(bot, y))
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
}

Wine::Wine(const char* l, int y) : years(y), pairs(ArrayInt(0, y), ArrayInt(0, y))
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
}

Wine::~Wine()
{
	delete[] label;
}

void Wine::show() const
{
	cout << "Wine: " << Wine::Label() << endl;
	cout << "Year\tBottles" << endl;
	for (int i = 0; i < pairs.first().size(); i++)
	{
		cout << pairs.first()[i] << '\t';
		cout << pairs.second()[i] << endl;
	}
}

void Wine::GetBottles()
{
	ArrayInt forF(years), forS(years);
	cout << "Enter " << label << " data for " << years << " year(s):" << endl;
	for (int i = 0; i < years; i++)
	{
		int temp;
		cout << "Enter year: ";
		cin >> forF[i];
		cout << "Enter bottles for that year: ";
		cin >> forS[i];
	}
	pairs = PairArray(forF, forS);
}

const int Wine::sum() const
{
	int total = 0;
	for (int i = 0; i < pairs.second().size(); i++)
		total += pairs.second()[i];
	return total;
}

const char* Wine::Label() const
{
	return label;
}

int main()
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;
	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.show();
	const int YRS = 3;
	int yyy[YRS] = { 1993,1995,1998 };
	int bbb[YRS] = { 48,60,72 };
	Wine more("Gushing Grape Red", YRS, yyy, bbb);
	more.show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye!" << endl;

	return 0;
}
