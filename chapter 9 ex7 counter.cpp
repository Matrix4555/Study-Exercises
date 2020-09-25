#include <iostream>

using namespace std;

class Counter
{
public:
	Counter() : count()
	{ }

	Counter(int c) : count(c)
	{ }

	unsigned int get_count() const
	{
		return count;
	}

	Counter operator++ ()
	{
		return Counter(++count);
	}

protected:
	unsigned int count;
};


class CountDn : public Counter
{
public:
	CountDn() : Counter()
	{ }

	CountDn(int c) : Counter(c)
	{ }

	CountDn operator-- ()
	{
		return CountDn(--count);
	}
};


class PostAct : public Counter
{
public:
	PostAct()
	{
		Counter();
	}

	PostAct(int pp) : Counter(pp)
	{}

	PostAct operator++(int)
	{
		return PostAct(count++);
	}

	PostAct operator--(int)
	{
		return PostAct(count--);
	}
};


int main()
{
	PostAct a(6);
	a--;
	cout << a.get_count() << endl;

	return 0;
}