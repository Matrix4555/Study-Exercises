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
		first = NULL;
	}

	void ownDestructor()
	{
		link* current = first;
		while (current)
		{
			link* temp = current;
			cout << "current is " << current->data << "   temp is " << temp->data << endl;
			current = current->next;
			delete temp;
			cout << "dest works!" << endl;
		}
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

	void operator=(linklist& a)
	{
		link* convey[5];
		int index = 0;
		link* currentA = a.first;

		while (currentA)
		{
			convey[index] = currentA;
			currentA = currentA->next;
			index++;
		}

		for (int i = 4; i >= 0; i--)
		{
			link* newlink = new link;
			newlink->data = convey[i]->data;
			newlink->next = first;
			first = newlink;
		}
	}

private:
	link* first;
};


int main()
{
	linklist lll;
	linklist ggg;

	lll.additem(52);
	lll.additem(46);
	lll.additem(31);
	lll.additem(78);
	lll.additem(32);
	lll.display();

	cout << endl << "=========================================" << endl << endl;

	ggg = lll;
	ggg.display();
	lll.ownDestructor();

	cout << endl << "=========================================" << endl << endl;

	ggg.display();

	return 0;
}