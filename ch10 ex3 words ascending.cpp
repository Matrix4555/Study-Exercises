#include <iostream>

using namespace std;

const int days = 7;

void second(const char** a, const char** b)
{
	if (strcmp(*a, *b) > 0)
	{
		const char* temp = *a;
		*a = *b;
		*b = temp;
	}
}


void first(const char** word)
{
	for (int i = 0; i < days; i++)
		for (int j = i + 1; j < days; j++)
			second(word + i, word + j);
}


int main()
{
	const char* week[days] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	for (int p = 0; p < days; p++)
		cout << *(week + p) << endl;

	cout << "======================================" << endl;

	first(week);

	for (int p = 0; p < days; p++)
		cout << *(week + p) << endl;

	return 0;
}