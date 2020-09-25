#include <iostream>

using namespace std;

class str
{
public:
	str()
	{
		strcpy_s(arr, "");
	}

	str(char mas[])
	{
		strcpy_s(arr, mas);
	}

	str operator+=(str word)
	{
		if (strlen(arr) + strlen(word.arr) > max)
		{
			cout << "Array is over" << endl; system("pause");  exit(1);
		}
		strcat_s(arr, word.arr);
		return str(arr);
	}

	void getInfo()
	{
		cout << arr << endl;
	}

private:
	enum { max = 80 };
	char arr[max];
};


int main()
{
	char w[] = "hello";
	char e[] = " car";
	str a(w);
	str b;
	str c(e);
	b = a += c;
	a.getInfo();
	b.getInfo();

	return 0;
}