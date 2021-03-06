#include <iostream>
#include <string.h>

using namespace std;

class Cd
{
public:
	Cd();
	Cd(const Cd& d);
	Cd(const char* s1, const char* s2, int n, double x);
	~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
protected:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
};

Cd::Cd() : performers(""), label(""), selections(0), playtime(0)
{ }

Cd::Cd(const Cd& d) : selections(d.selections), playtime(d.playtime)
{
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
}

Cd::Cd(const char* s1, const char* s2, int n, double x) : selections(n), playtime(x)
{ 
	strcpy_s(performers, strlen(s1)+1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
}

Cd::~Cd()
{ }

void Cd::Report() const
{
	cout << "== " << performers << " == " << label << " == " << selections << " == " << playtime << " ==" << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if(this == &d)
		return *this;
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

class Classic : public Cd
{
public:
	Classic();
	Classic(const Classic& d);
	Classic(const char* s1, const char* s2, int n, double x, const char* nm);
	void Report() const;
	Classic& operator=(const Classic& d);
private:
	char name[30];
};

Classic::Classic() : Cd(), name("")
{ }

Classic::Classic(const Classic& d) : Cd(d.performers, d.label, d.selections, d.playtime)
{
	strcpy_s(name, strlen(d.name) + 1, d.name);
}

Classic::Classic(const char* s1, const char* s2, int n, double x, const char* nm) : Cd(s1, s2, n, x)
{ 
	strcpy_s(name, strlen(nm) + 1, nm);
}

void Classic::Report() const
{
	Cd::Report();
	cout << "and == " << name << endl;
}

Classic& Classic::operator=(const Classic& d)
{
	if(this == &d)
		return *this;
	Cd::operator=(d);
	strcpy_s(name, strlen(d.name) + 1, d.name);
	return *this;
}

void bravo(const Cd& disk);

int main()
{
	Cd c1("Beatries", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", 2, 57.17, "Philips");
	Cd* pcd = &c1;

	cout << endl << "Using object directly: " << endl;
	c1.Report();
	c2.Report();

	cout << endl << "Using type cd* pointer to objects:" << endl;
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << endl << "Calling a function with a Cd reference argument:" << endl;
	bravo(c1);
	bravo(c2);

	cout << endl << "Testing assignment:" << endl;
	//Classic copy = c2;
	Classic copy;
	copy = c2;
	copy.Report();

	cout << endl;
	return 0;
}

void bravo(const Cd& disk)
{
	disk.Report();
}