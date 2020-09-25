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
	string workers[] = { "Alex", "Harry", "Dominic", "The Rock", "Kate" };

	string* ptr;
	ptr = find_if(workers, workers + 5, searching);

	if (ptr == workers + 5)
		cout << "no there";
	else
		cout << "Dominic on " << (ptr - workers) << " position" << endl;

	return 0;
}