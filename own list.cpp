#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(const T data);
	void push_front(const T data);
	void pop_back();
	void pop_front();
	const T first() const { return head->data; }
	const T last() const;
	T& operator[](const int index);
	void insert(const T data, const int index);
	void removeAt(const int index);
	void clear();
	const int getSize() const { return size; }
private:
	template<typename T>
	struct Node
	{
		T data;
		Node* pNext;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* head;
	int size;
};

template<typename T>
List<T>::List()
{
	head = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(const T data)
{
	size++;
	if (head == nullptr)
	{
		head = new Node<T>(data);
		return;
	}
	Node<T>* current = head;
	while (current->pNext != nullptr)
		current = current->pNext;
	current->pNext = new Node<T>(data);
}

template<typename T>
void List<T>::push_front(const T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::pop_back()
{
	size--;
	if (head->pNext == nullptr)
	{
		delete head;
		return;
	}
	Node<T>* current = head;
	while (current->pNext->pNext != nullptr)
		current = current->pNext;
	delete current->pNext;
	current->pNext = nullptr;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* del = head;
	head = head->pNext;
	delete del;
	size--;
}

template<typename T>
const T List<T>::last() const
{
	Node<T>* current = head;
	while (current->pNext != nullptr)
		current = current->pNext;
	return current->data;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = head;
	for (int i = 0; i != index; i++)
		current = current->pNext;
	return current->data;
}

template<typename T>
void List<T>::insert(const T data, const int index)
{
	if (index == 0)
	{
		push_front(data);
		return;
	}
	Node<T>* current = head;
	for (int i = 1; i != index; i++)
		current = current->pNext;
	Node<T>* add = new Node<T>(data, current->pNext);
	current->pNext = add;
	size++;
}

template<typename T>
void List<T>::removeAt(const int index)
{
	if (index == 0)
	{
		pop_front();
		return;
	}
	Node<T>* current = head;
	for (int i = 1; i != index; i++)
		current = current->pNext;
	Node<T>* del = current->pNext;
	current->pNext = del->pNext;
	delete del;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		cout << last() << "\t\t" << size << " element deleted" << endl;
		pop_back();
	}
}

int main()
{
	List<int> l;
	l.push_back(4);
	l.push_back(15);
	l.removeAt(1);
	l.push_front(0);
	l.insert(111, 0);
	l.push_back(342);
	l.push_back(90);
	l[2] = 666;
	l.push_back(344);
	l.push_front(14);
	l.insert(77, 1);
	l.removeAt(0);
	l.pop_back();
	l.pop_back();
	l.pop_front();

	for (int i = 0; i < l.getSize(); i++)
		cout << l[i] << endl;

	cout << endl;

	return 0;
}
