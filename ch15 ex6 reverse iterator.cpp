#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	vector<int> vvv = { 1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator iter;
	vector<int>::reverse_iterator revIter;

	for (int i = 0; i < vvv.size(); i++)
		cout << vvv[i] << endl;
	cout << "==============================================" << endl;

	iter = vvv.begin();
	revIter = vvv.rbegin();
	int further = 0;
	while (true)
	{
		if (further >= vvv.size() / 2)
			break;							//if we won't dereference them their pointers will have swaped and in further we couldn't increment and decrement them because
		swap(*iter++, *revIter++);			//itFirst is element before end() and itSecond is begin() and we can't write begin()-- (we'll get error) and itFirst++ (we'll get end())
		further++;
	}

	for (int i = 0; i < vvv.size(); i++)
		cout << vvv[i] << endl;

	return 0;
}