#include <iostream>

using namespace std;

class String
{
public:
	String(char* s)
	{
		int length = strlen(s);
		str = new char[length + 1];
		strcpy_s(str, length + 1, s);
	}

	~String()
	{
		cout << "Delete a string\n";
		delete[] str;
	}

	void display()
	{
		cout << str << endl;
	}

	void upit()
	{
		char* newWord = str;
		while (*newWord)
		{
			*newWord = toupper(*newWord);
			newWord++;
		}
	}

private:
	char* str;
};


int main()
{
	char word[] = "hello";
	String ff(word);
	ff.upit();
	ff.display();

	return 0;
}