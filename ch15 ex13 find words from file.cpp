#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iterator>
#include <ctype.h>

using namespace std;


int main()
{
	string name;
	cout << "input name of file: "; cin >> name;
	ifstream myfile(name);
	istream_iterator<string> fileIter(myfile);
	istream_iterator<string> fileIterEnd;

	map <string, int, less<string> > table;
	map <string, int, less<string> >::iterator tableIter;

	while (fileIter != fileIterEnd)
	{
		name = (*fileIter++);
		if (name.front() < 'A' || name.front() > 'z')
			continue;
		if (ispunct(name.back()) != 0)
			name.pop_back();
		if (name.front() >= 'A' && name.front() <= 'Z')
			name.front() = tolower(name.front());
		tableIter = table.find(name);
		if (tableIter == table.end())
			table.emplace(name, 1);
		else
			tableIter->second++;
	}

	cout << "----------------------------------------------------------------------------" << endl;

	for (tableIter = table.begin(); tableIter != table.end(); tableIter++)
		cout << tableIter->first << "\t\t\tmeets\t" << tableIter->second << " \ttimes" << endl;

	return 0;
}