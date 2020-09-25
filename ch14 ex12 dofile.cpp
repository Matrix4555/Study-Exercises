#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class dofile
{
public:
	dofile(string nameF)
	{
		this->nameF = nameF;
		myfile.open(nameF, ios::app | ios::out | ios::in /*| ios::trunc*/);
		if (!myfile)
			throw dofile::excNoOpen();
	}

	class excNoOpen
	{};

	class excNoWrite
	{};

	class excNoRead
	{};

	void fileWrite(const char* word)
	{
		if (!myfile)
			throw dofile::excNoWrite();
		for (int i = 0; i < strlen(word); i++)
			myfile.put(word[i]);
		myfile.put('\n');
	}

	string fileRead()
	{
		if (!myfile)
			throw dofile::excNoRead();
		string ret;
		char temp;
		myfile.seekg(0);
		while (!myfile.eof())
		{
			myfile.get(temp);
			ret += temp;
		}
		return ret;
	}

private:
	fstream myfile;
	string nameF;
};


int main()
{
	try
	{
		dofile a("exceptions.txt");
		a.fileWrite("C++");
		a.fileWrite("Forever");
		cout << a.fileRead() << endl;
	}
	catch (dofile::excNoOpen)
	{
		cout << "File didn't open" << endl;
	}
	catch (dofile::excNoWrite)
	{
		cout << "Impossibly to write" << endl;
	}
	catch (dofile::excNoRead)
	{
		cout << "Impossibly to read" << endl;
	}

	return 0;
}