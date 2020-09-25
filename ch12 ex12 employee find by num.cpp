#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

const int LEN = 32;
const int MAXEM = 100;

enum employee_type { tmanager, tscientist, tlaborer };

class employee
{
public:
	virtual void setData()
	{
		cin.ignore(10, '\n');
		cout << "input the name: "; cin >> name;
		cout << "input the number: "; cin >> number;
	}

	virtual void getData()
	{
		cout << "Name is " << name;
		cout << "Number is " << number;
	}
	
	virtual employee_type get_type();
	static void add();
	static void display();
	static void read();
	static void write();
	static void find();

private:
	char name[LEN];
	unsigned long number;
	static int n;
	static employee* arrap[];
};
int employee::n;
employee* employee::arrap[MAXEM];


class manager :public employee
{
public:
	void setData()
	{
		employee::setData();
		cout << "  ¬ведите титул: ";
		cin >> title;
		cout << "  ¬ведите налоги: ";
		cin >> dues;
	}
	
	void getData()
	{
		employee::getData();
		cout << "\n  “итул: " << title;
		cout << "\n  Ќалоги гольф-клуба: " << dues;
	}

private:
	char title[LEN];
	double dues;
};


class scientist : public employee
{
private:
	int pubs;

	void setData()
	{
		employee::setData();
		cout << "  ¬ведите число публикаций: ";
		cin >> pubs;
	}

	void getData()
	{
		employee::getData();
		cout << "\n  „исло публикаций: " << pubs;
	}
};


class laborer : public employee { };


void employee::add()
{
	char ch;
	cout << "m - add a manager\ns - add a scientist\nl - add a laaborer\nyour choose - ";
	cin >> ch;
	switch (ch)
	{
	case 'm': arrap[n] = new manager; break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer; break;
	default: cout << "unknown worker" << endl; return;
	}
	arrap[n++]->setData();
}


void employee::display()
{
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1);
		switch (arrap[i]->get_type())
		{
		case tmanager: cout << ". type is manager "; break;
		case tscientist: cout << ". type is scientist "; break;
		case tlaborer: cout << ". type is laborer "; break;
		}
		arrap[i]->getData();
		cout << endl;
	}
}


employee_type employee::get_type()
{
	if (typeid(*this) == typeid(manager))
		return tmanager;
	else if (typeid(*this) == typeid(scientist))
		return tscientist;
	else if (typeid(*this) == typeid(laborer))
		return tlaborer;
	else
	{
		cerr << "improper type of worker" << endl; exit(1);
	}
	return tmanager;
}


void employee::write()
{
	int size;
	cout << "it's recording " << n << " workers" << endl;
	ofstream ouf;
	employee_type etype;
	ouf.open("employ.txt", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "open a file is impossible" << endl;
		return;
	}
	for (int j = 0; j < n; j++)
	{
		etype = arrap[j]->get_type();
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)
		{
		case tmanager:		size = sizeof(manager);		break;
		case tscientist:	size = sizeof(scientist);	break;
		case tlaborer:		size = sizeof(laborer);		break;
		}
		ouf.write((char*)(arrap[j]), size);
		if (!ouf)
		{
			cout << "recording to file is impossible" << endl;
			return;
		}
	}
}


void employee::read()
{
	int size;
	employee_type etype;
	ifstream inf;
	inf.open("employ.txt", ios::binary);
	if (!inf)
	{
		cout << "open a file is impossible";
		return;
	}
	n = 0;
	while (true)
	{
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())								// when file is end cycle is end
			break;
		if (!inf)
		{
			cout << "reading of type is impossible" << endl;
			return;
		}
		switch (etype)
		{
		case tmanager:
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default:
			cout << "unknown type in file" << endl;
			return;
		}
		inf.read((char*)arrap[n], size);
		if (!inf)
		{
			cout << "reading a data from file is impossible" << endl;
			return;
		}
		n++;
	}
	cout << "Reading... " << n << " workers" << endl;
}


void employee::find()
{
	int size;
	employee_type etype;
	ifstream inf;
	inf.open("employ.txt", ios::binary);
	if (!inf)
	{
		cout << "open a file is impossible";
		return;
	}
	n = 0;

	//-------------------------------------------------------------------------REVERSE

	int see;
	cout << "what's number to find? "; cin >> see;		
	for (n = see - 1; n >= 0; n--)						
	{
		inf.read((char*)&etype, sizeof(etype));

		switch (etype)
		{
		case tmanager:
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default:
			cout << "unknown type in file" << endl;
			return;
		}

		inf.read((char*)arrap[n], size);
	}

	cout << "Reading... " << see << " worker" << endl;
	n = --see;
	for (; n > 0; n--)
	{
		delete arrap[n];								
	}
	n++;											
}


int main()
{
	setlocale(LC_ALL, "ru");
	char ch;

	while (true)
	{
		cout << "'a' Ц добавление сведений о работнике"
			"\n'd' - вывести сведени€ обо всех работниках"
			"\n'w' Ц записать все данные в файл"
			"\n'r' Ц прочитать все данные из файла"
			"\n'x' - выход"
			"\n¬аш выбор: ";
		cin >> ch;
		switch (ch)
		{
		case 'a':
			employee::add(); break;
		case 'd':
			employee::display(); break;
		case 'w':
			employee::write(); break;
		case 'r':
			employee::read(); break;
		case 'x':
			exit(0);
		case 'f':
			employee::find(); break;
		default:
			cout << "\nЌеизвестна€ команда";
		}
	}

	return 0;
}