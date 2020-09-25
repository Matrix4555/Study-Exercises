#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

bool searching(string name)
{
	return name == "Dominic";
}


int main()
{
	vector<string> vvv = { "Alex", "Harry", "Dominic", "The Rock", "Kate" };
	vector<string>::iterator iter;

	iter = find_if(vvv.begin(), vvv.end(), searching);

	if (iter == vvv.end())
		cout << "no there";
	else
		cout << "Dominic on " << (++iter - vvv.begin()) << " position" << endl;

	return 0;
}