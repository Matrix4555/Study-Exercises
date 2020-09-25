#include <iostream>

using namespace std;

int compstr(const char* word1, const char* word2)
{
	int check = strlen(word1);
	int c = 0;
	while (check--)
	{
		if (*(word1 + c) > *(word2 + c))
			return 1;
		else if (*(word1 + c) < *(word2 + c))
			return -1;
		else
			c++;
	}
	return 0;
}


int main()
{
	const char* first = "qwerAy";
	const char* second = "qwerty";

	cout << "My Function's Answer is " << compstr(first, second) << endl;

	cout << "The Real Answer is " << strcmp(first, second) << endl;

	return 0;
}