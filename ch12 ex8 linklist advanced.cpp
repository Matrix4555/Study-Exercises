#include <iostream>
#include <fstream>

using namespace std;

struct link
{
	int data;
	link* next;
};


class linklist
{
public:
	linklist()
	{
		first = nullptr;
		myfile.open("LinkList.txt", ios::app | ios::in | ios::out | ios::binary);
	}

	void additem(int d)
	{
		link* newlink = new link;
		newlink->data = d;
		newlink->next = first;
		first = newlink;
	}
	void display()
	{
		link* current = first;
		while (current)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	void fileWrite()
	{
		link* current = first;
		while (current)
		{
			myfile << current->data << endl;
			current = current->next;
		}
		cout << "Successfully" << endl;
	}

	void fileRead()
	{
		char word[100];
		int content[40];
		int count = 0;

		myfile.seekg(0);
		while (myfile)
		{
			if (myfile.get() != '\n')
			{
				myfile.seekg(-1, ios::cur);
				content[count] = static_cast<int>(myfile.get() - '0');
			}
			else
				count++;
		}

		int whole = count;

		for (int i = 0; i < whole; i++)
			cout << i + 1 << " number is " << content[i] << endl;

		first = nullptr;

		while (--count >= 0)
		{
			link* newlink = new link;
			newlink->data = content[count];
			newlink->next = first;
			first = newlink;
		}
		cout << "new values created" << endl;
	}

private:
	link* first;
	fstream myfile;
};


int main()
{
	linklist lll;
	char select;
	int val;

	do
	{
		cout << "action? add/show/write/read/exit : "; cin >> select;
		switch (select)
		{
		case 'a':
			cout << "value="; cin >> val;
			lll.additem(val);
			break;
		case 's':
			lll.display();
			break;
		case 'w':
			lll.fileWrite();
			break;
		case 'r':
			lll.fileRead();
			break;
		}
	} while (select != 'e');

	return 0;
}