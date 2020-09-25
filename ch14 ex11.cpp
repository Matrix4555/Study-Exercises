#include <iostream>
#include <stdlib.h>

using namespace std;

class errorConstructor
{ };


class errorOperator
{ };


class String
{
public:
	String() { strcpy_s(str, ""); }

	String(const char s[])
	{
		if (strlen(s) >= SZ)
			throw errorConstructor();
		strcpy_s(str, s);
	}

	void display() const
	{
		cout << str << endl;
	}

	String operator+ (String ss) const
	{
		String temp;
		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcpy_s(temp.str, str);
			strcat_s(temp.str, ss.str);
		}
		else
		{
			throw errorOperator();
		}
		return temp;
	}

private:
	enum { SZ = 80 };
	char str[SZ];
};


int main()
{
	const char* first = "Happy Christmas! ";
	const char* second = "Happy New Year!";

	try
	{
		String s1(first);
		String s2(second);
		String s3;

		s1.display();
		s2.display();
		s3.display();

		s3 = s1 + s2;

		s3.display();
	}
	catch (errorConstructor)
	{
		cout << "constructor is invalid" << endl;
	}
	catch (errorOperator)
	{
		cout << "concatenation is overloaded" << endl;
	}

	return 0;
}