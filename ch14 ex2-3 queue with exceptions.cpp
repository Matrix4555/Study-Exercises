#include <iostream>

using namespace std;

const int MAX = 5;

class full
{ };


class emptyyy
{ };


template <typename T>
class queue
{
public:
	queue() : head(0), tail(0)
	{ }

	void add(T arg)
	{
		if (count >= MAX)
			throw full();
		arr[tail++] = arg;
		count++;
		if (tail >= MAX)
			tail = 0;
	}

	T pop()
	{
		if (count <= 0)
			throw emptyyy();
		T temp = arr[head++];
		count--;
		if (head >= MAX)
			head = 0;
		return temp;
	}

private:
	int count = 0;
	T arr[MAX];
	int head;
	int tail;
};


int main()
{
	queue<int> obj;
	char next;
	int i;
	do
	{
		try
		{
			cout << "a - add an element\np - pop an element\ne - exit" << endl; cin >> next;
			switch (next)
			{
			case 'a':
				cout << "add number: "; cin >> i;
				obj.add(i);
				break;
			case 'p':
				cout << "got number is " << obj.pop() << endl;
				break;
			}
			cout << "===============================================================================" << endl;
		}

		catch (full)
		{
			cout << ":(\nError occurred. You violated boundaries of array." << endl;
		}

		catch (emptyyy)
		{
			cout << ":(\nError occurred. You want to get an empty element from array." << endl;
		}


	} while (next != 'e');

	return 0;
}