#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void description(vector<int>& a, vector<int>& b, vector<int>::iterator& c, vector<int>::iterator& d, vector<int>::iterator& f)
{
	int dest;
	cout << "Indicate what's position to begin a copy from: "; cin >> dest;
	dest--;
	c = a.begin() + dest;
	cout << "Then indicate where to end a copy: "; cin >> dest;
	d = a.begin() + dest;
	cout << "Then indicate where is point of destination for second vector: "; cin >> dest;
	dest--;
	f = b.begin() + dest;
}


void show(const vector<int> see)
{
	for (int i = 0; i < see.size(); i++)
		cout << see[i] << "  ";
	cout << endl;
}


void justxD()
{
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
}


int main()
{
	vector<int> vv1 = { 43,28,56,34,28,10,96,46,12,57,12,45,24 };
	vector<int> vv2 = { 33,66,43,80,12,43,67,39,53,89,24,33,64,23,56,42,32,56,65,67 };
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	vector<int>::iterator destination;

	char next;
	int dest;
	do
	{
		cout << "f - show first vector\ns - show second vector\nc - copy\nb - copy backward\ne - exit\nselect: "; cin >> next;
		justxD();
		switch (next)
		{
		case 'f':
			show(vv1);
			justxD();
			break;
		case 's':
			show(vv2);
			justxD();
			break;
		case 'c':
			description(vv1, vv2, iter1, iter2, destination);
			copy(iter1, iter2, destination);
			justxD();
			break;
		case 'b':
			description(vv1, vv2, iter1, iter2, destination);
			copy_backward(iter1, iter2, destination);
			justxD();
			break;
		default:
			break;
		}
	} while (next != 'e');

	return 0;
}