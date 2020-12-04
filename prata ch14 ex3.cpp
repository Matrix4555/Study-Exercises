#include <iostream>
#include <string>
#include <string.h>

using namespace std;

template<typename T>
class QueueTP
{
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isEmpty() const { return items == 0; }
	bool isFull() const { return items == qsize; }
	int queueCount() const { return items; }
	bool enqueue(const T& item);
	bool dequeue(T& item);
	T& operator[](const int index);
private:
	enum { Q_SIZE = 10 };
	struct Node
	{
		T item;
		Node* next;
		Node(const T& i) : item(i), next(nullptr) { }
	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP& q) : qsize(0) { }
	QueueTP& operator=(const QueueTP& q) { return *this; }
};

class Worker
{
public:
	Worker() : fullname("no one"), id(0L) { }
	Worker(const string& s, long n) : fullname(s), id(n) { }
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
protected:
	virtual void Data() const;
	virtual void Get();
private:
	string fullname;
	long id;
};

class Waiter : virtual public Worker
{
public:
	Waiter() : Worker(), panache(0) { }
	Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(p) { }
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) { }
	void Set();
	void Show() const;
protected:
	void Data() const;
	void Get();
private:
	int panache;
};

class Singer : virtual public Worker
{
public:
	Singer() : Worker(), voice(other) { }
	Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v) { }
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) { }
	void Set();
	void Show() const;
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static const char* pv[Vtypes];
	int voice;
};

class SingingWaiter : public Singer, public Waiter
{
public:
	SingingWaiter() {}
	SingingWaiter(const string& s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) { }
	SingingWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) { }
	SingingWaiter(const Waiter& wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) { }
	SingingWaiter(const Singer& wt, int p = 0) : Worker(wt), Waiter(wt, p), Singer(wt) { }
	void Set();
	void Show() const;
protected:
	void Data() const;
	void Get();
};

template<typename T>
QueueTP<T>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template<typename T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool QueueTP<T>::enqueue(const T& item)
{
	if (isFull())
		return false;
	Node* add = new Node(item);
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename T>
bool QueueTP<T>::dequeue(T& item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

template<typename T>
T& QueueTP<T>::operator[](const int index)
{
	Node* current = front;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->item;
}

Worker::~Worker() { }

void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter" << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

const char* Singer::pv[Singer::Vtypes] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer" << endl;
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range: " << endl;
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: singing waiter" << endl;
	Worker::Data();
	Data();
}

const int SIZE = 5;

int main()
{
	QueueTP<Worker*> a;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category: " << endl << "w: waiter s: singer t: singing waiter q: quit" << endl;
		cin >> choice;
		while (strchr("wstq", choice) == nullptr)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			a.enqueue(new Waiter);
			break;
		case 's':
			a.enqueue(new Singer);
			break;
		case 't':
			a.enqueue(new SingingWaiter);
			break;
		}
		cin.get();
		a[ct]->Set();
	}
	cout << endl << endl << "Here is your staff: " << endl;
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		a[i]->Show();
	}
	for (i = 0; i < ct; i++)
		a[i]->~Worker();

	return 0;
}
