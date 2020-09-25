#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
	string name;
	float salary;
public:
	void setData()
	{
		cout << "Input name: ";
		cin >> name;
		cout << "Input a salary: ";
		cin >> salary;
	}

	void printData()
	{
		cout << "Name is " << name << "\t and salary is \t" << salary << endl;
	}

	string getName()
	{
		return name;
	}

	float getSalary()
	{
		return salary;
	}
};


void salarySort(person** obj, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ((*(obj + i))->getSalary() > (*(obj + j))->getSalary())
			{
				person* temp = *(obj + i);
				*(obj + i) = *(obj + j);
				*(obj + j) = temp;
			}
		}
	}
}


void nameSort(person** one, person** two)
{
	if ((*one)->getName() > (*two)->getName())
	{
		person* temp = *one;
		*one = *two;
		*two = temp;
	}
}


void sort(person** obj, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			nameSort(obj + i, obj + j);
}


int main()
{
	person* persPtr[100];
	int n = 0;
	char next = 'y';

	while (next == 'y')
	{
		persPtr[n] = new person;
		persPtr[n]->setData();
		n++;
		cout << "Do you want to continue? y/n: "; cin >> next;
	}

	cout << endl;

	for (int i = 0; i < n; i++)
		persPtr[i]->printData();

	cout << endl;

	salarySort(persPtr, n);

	for (int i = 0; i < n; i++)
		persPtr[i]->printData();

	return 0;
}