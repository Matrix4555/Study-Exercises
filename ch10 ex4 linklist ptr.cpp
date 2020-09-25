#include <iostream>

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
	}

	~linklist()
	{
		link* current = first;
		while (current)
		{
			link* temp = current;
			current = current->next;
			delete temp;
			cout << "dest works!" << endl;
		}
		system("pause");
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

private:
	link* first;
};


int main()
{
	linklist lll;
	lll.additem(52);
	lll.additem(46);
	lll.additem(31);
	lll.additem(78);
	lll.additem(32);
	lll.display();

	return 0;
}