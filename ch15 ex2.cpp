#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<string> vvv;
	string temp;
	char next;

	do
	{
		cout << "add word: "; cin >> temp >> next;
		vvv.push_back(temp);
	} while (next == '+');

	for (int i = 0; i < vvv.size(); i++)
	{
		cout << i + 1 << " word is " << vvv[i] << endl;
	}

	sort(vvv.begin(), vvv.end());
	cout << "=============================================" << endl;

	for (int i = 0; i < vvv.size(); i++)
	{
		cout << i + 1 << " word is " << vvv[i] << endl;
	}

	return 0;
}