#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	string firstName, secondName;
	cout << "input name of first file: "; cin >> firstName;			// write name of first file which get data
	cout << "input name of second file: "; cin >> secondName;		// write name of second file where content is there for copy

	ofstream fileOne(firstName);									// open file with this name
	ifstream fileTwo(secondName);									// open file with this name

	ostream_iterator<int> convey(fileOne, ", ");					// create iterator for file which get data, it's begin()

	istream_iterator<int> beginn(fileTwo);							// create iterator for file which relay data, it's begin()
	istream_iterator<int> endd;										// create iterator else, it's end()

	copy(beginn, endd, convey);										// 1 way

	/*while (beginn!=endd)											// 2 way
	{
		*convey++ = *beginn++;
	}*/

	return 0;
}