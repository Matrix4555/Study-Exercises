#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vv1 = { 43,28,56,34,28,1,96,46,12,57,12,452,214 };
	vector<int> vv2 = { 33,66,43,8,12,43,67,329,573,899,24,1233,654,243,56,2,432,567,65,67 };
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	vector<int>::iterator destination;

	int dest;
	cout << "Indicate what's position to begin a copy from: "; cin >> dest;
	dest--;
	iter1 = vv1.begin() + dest;
	cout << "Then indicate where to end a copy: "; cin >> dest;
	iter2 = vv1.begin() + dest;
	cout << "Then indicate where is point of destanation for second vector: "; cin >> dest;
	dest--;
	destination = vv2.begin() + dest;

	copy(iter1, iter2, destination);

	for (int i = 0; i < vv2.size(); i++)
		cout << vv2[i] << endl;

	return 0;
}