#include <iostream>

using namespace std;

class str
{
public:
	str()
	{
		strcpy_s(strg, "");
	}

	void show()
	{
		cout << strg << ".end" << endl;
	}

protected:
	enum sz { max = 80 };
	char strg[max];
private:
};


class Pstring : public str
{
public:
	Pstring(char word[])
	{
		int i = 0;
		for (; i < max - 1; i++)
		{
			strg[i] = word[i];
		}
		strg[i] = '\0';
	}
};


class Pstring2 : public str
{
public:
	void left(char word[], int n)
	{
		int j = 0;
		for (int i = 0; i < n; i++, j++)
			strg[j] = word[i];
		strg[j] = '\0';
	}

	void mid(char word[], int n, int s)
	{
		int j = 0;
		for (int i = n; i < n + s; i++, j++)
			strg[j] = word[i];
		strg[j] = '\0';
	}

	void right(char word[], int n)
	{
		int j = 0;
		for (int i = strlen(word) - n; i <= strlen(word); i++, j++)
			strg[j] = word[i];
		strg[j] = '\0';
	}
};


int main()
{
	char temp[] = "hello everybody! hello everybody!";

	Pstring2 a, b, c;

	a.left(temp, 9);
	a.show();

	b.mid(temp, 4, 11);
	b.show();

	c.right(temp, 20);
	c.show();

	return 0;
}