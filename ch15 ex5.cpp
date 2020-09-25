#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int arr[] = { 4,6,8,12,16,19,20 };

	set<int, less<int> > sss;
	set<int, less<int> >::iterator iter;
	sss.insert(3);
	sss.insert(11);
	sss.insert(7);
	sss.insert(1);
	sss.insert(5);

	vector<int> vvv;

	for (int i = 0; i < 7; i++)
		cout << arr[i] << endl;
	cout << "==============================" << endl;

	iter = sss.begin();
	while (iter != sss.end())
		cout << *iter++ << endl;
	cout << "==============================" << endl;

	merge(arr, arr + 7, sss.begin(), sss.end(), back_inserter(vvv));

	for (int i = 0; i < vvv.size(); i++)
		cout << vvv[i] << endl;

	return 0;
}