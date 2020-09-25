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
		cout << strg << endl;
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


int main()
{
	char Word[] = "Hello everybody!Hello everybody!Hello everybody!Hello everybody!Hello everybody!"
				  "Hello everybody!Hello everybody!Hello everybody!Hello everybody!Hello everybody!";
	Pstring TheWord = Word;
	TheWord.show();

	char Word2[] = "Go play!";
	Pstring TheWord2(Word2);
	TheWord2.show();

	return 0;
}