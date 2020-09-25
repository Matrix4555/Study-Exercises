#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class person
{
public:
	person() : name("no"), age(0)
	{ }

	person(string n, int a) : name(n), age(a)
	{ }

	void getInfo() const							// const is necessary
	{
		cout << "Name is " << name << "\tAge is " << age << endl;
	}

	friend bool operator<(const person&, const person&);

private:
	string name;
	int age;
};


bool operator<(const person& a, const person& b)
{
	if (a.name == b.name)
		return (a.age < b.age) ? true : false;		// necessarily in this format
	return (a.name < b.name) ? true : false;
}


class comparePerson
{
public:
	bool operator() (const person* a, const person* b) const
	{
		return *a < *b;
	}
};


class getPerson
{
public:
	void operator() (const person* a) const
	{
		a->getInfo();
	}
};


int main()
{
	person* ptr1 = new person("Mike", 16);
	person* ptr2 = new person("Jerry", 23);
	person* ptr3 = new person("Kate", 25);
	person* ptr4 = new person("Harry", 20);
	person* ptr5 = new person("Kate", 18);
	person* ptr6 = new person("Tom", 20);

	multiset<person*, comparePerson > sss;
	multiset<person*, comparePerson >::iterator iter;

	sss.insert(ptr1);
	sss.insert(ptr2);
	sss.insert(ptr3);
	sss.insert(ptr4);
	sss.insert(ptr5);
	sss.insert(ptr6);

	for_each(sss.begin(), sss.end(), getPerson());
	cout << "=================================================" << endl;

	for (iter = sss.begin(); iter != sss.end(); iter++)
	{
		delete* iter;
		cout << "deleted" << endl;
	}

	return 0;
}