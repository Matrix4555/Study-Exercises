#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	list<int> lll;
	list<int>::iterator itFirst;
	list<int>::iterator itSecond;

	int temp;
	char next;
	do
	{
		cout << "add a number: "; cin >> temp >> next;
		lll.push_back(temp);
	} while (next == '+');

	cout << "=====================================================" << endl;

	for (itFirst = lll.begin(); itFirst != lll.end();)
		cout << *itFirst++ << endl;

	cout << "=====================================================" << endl;

	itFirst = lll.begin();
	itSecond = lll.end();
	itSecond--;
	int further = 0;
	while (true)
	{
		if (further >= lll.size() / 2)
			break;							//if we won't dereference them their pointers will have swaped and in further we couldn't increment and decrement them because
		swap(*itFirst++, *itSecond--);		//itFirst is element before end() and itSecond is begin() and we can't write begin()-- (we'll get error) and itFirst++ (we'll get end())
		further++;
	}

	for (itFirst = lll.begin(); itFirst != lll.end();)
		cout << *itFirst++ << endl;

	return 0;
}