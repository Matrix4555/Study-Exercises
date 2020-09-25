#include <iostream>
#include <string>

using namespace std;

struct pairPair
{
	int x = 6;
	int y = 3;
};


class Stack
{
public:
	Stack()
	{
		top = -1;
	}

	void push(int var)
	{
		st[++top] = var;
	}

	int pop()
	{
		return st[top--];
	}

protected:
	enum { MAX = 3 };
	int st[MAX];
	int top;
};


class Stack2 : public Stack
{
public:
	void push(int var)
	{
		if (top >= MAX - 1)
		{
			cout << "\nОшибка: стек полон"; exit(1);
		}
		Stack::push(var);
	}

	int pop()
	{
		if (top < 0)
		{
			cout << "\nОшибка: стек пуст\n"; exit(1);
		}         return Stack::pop();
	}
};


class pairStack : public Stack2
{
public:
	void push(pairPair x)
	{
		Stack2::push(x.x);
		Stack2::push(x.y);
	}

	int pop()
	{
		return Stack2::pop();
		return Stack2::pop();
	}
};


int main()
{
	pairPair hh;
	pairStack yy;
	yy.push(hh);
	cout << yy.pop() << endl;

	return 0;
}