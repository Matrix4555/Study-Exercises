#include <iostream>
#include <fstream>

using namespace std;

class Distance
{
public:
	Distance() : feet(0), inches(0.0) { }
	Distance(int ft, float in) : feet(ft), inches(in) { }

	void getdist()
	{
		cout << "Input feets: "; cin >> feet;
		cout << "Input inches: "; cin >> inches;
	}

	void showdist()
	{
		cout << feet << "\'-" << inches << '\"' << endl;
	}

	void add_dist(Distance, Distance);

private:
	int feet;
	float inches;
};


void Distance::add_dist(Distance dd1, Distance dd2)
{
	inches = dd1.inches + dd2.inches;
	feet = 0;
	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}
	feet += dd1.feet + dd2.feet;
}


int main()
{
	char next;
	Distance obj;
	Distance secObj(3, 5.8);
	fstream filee;
	filee.open("EXER.TXT", ios::app | ios::out | ios::in | ios::binary);

	do
	{
		cout << "Input a data about distance:" << endl;
		obj.getdist();
		filee.write(reinterpret_cast<char*>(&obj), sizeof(obj));
		cout << "Do you want to continue? y/n " << endl; cin >> next;
	} while (next == 'y');

	filee.seekg(0);
	filee.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	while (!filee.eof())
	{
		cout << "Getting a data:" << endl;
		obj.showdist();
		filee.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	}

	return 0;
}