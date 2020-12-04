#include <iostream>
#include <string.h>

using namespace std;

class Port
{
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port();
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const;
	virtual void show() const;
	friend ostream& operator<<(ostream& os, const Port& p);
protected:
	char* brand;
	char style[20];
	int bottles;
};

class VintagePort : public Port
{
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort();
	VintagePort& operator=(const VintagePort& vp);
	void show() const;
	friend ostream& operator<<(ostream& os, const VintagePort& vp);
private:
	char* nickname;
	int year;
};

Port::Port(const char* br, const char* st, int b) : bottles(b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, strlen(st) + 1, st);
}

Port::Port(const Port& p) : bottles(p.bottles)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
}

Port::~Port()
{
	delete[] brand;
}

Port& Port::operator=(const Port& p)
{
	if(this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

int Port::BottleCount() const
{
	return bottles;
}

void Port::show() const
{
	cout << *this;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << "Brand is " << p.brand << endl;
	os << "Style is " << p.style << endl;
	os << "Bottles: " << p.bottles << endl;
	return os;
}

VintagePort::VintagePort() : Port(), nickname(nullptr), year(0)
{ }

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "none", b), year(y)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
}

VintagePort::VintagePort(const VintagePort& vp)
{
	brand = new char[strlen(vp.brand) + 1];
	strcpy_s(brand, strlen(vp.brand) + 1, vp.brand);
	strcpy_s(style, strlen(vp.style) + 1, vp.style);
	bottles = vp.bottles;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

VintagePort::~VintagePort()
{
	delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if(this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::show() const
{
	Port::show();
	cout << *this;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << "Nickname is " << vp.nickname << endl;
	os << "Year: " << vp.year << endl;
	return os;
}

int main()
{
	cout << "Creation:" << endl << endl;

	Port parent("Grape", "Wine", 3);
	VintagePort child("Honey", 7, "Beer", 29);
	parent.show(); cout << endl;
	child.show(); cout << endl;

	cout << "Copy Constructor:" << endl << endl;

	Port a(parent);
	VintagePort b(child);
	a.show(); cout << endl;
	b.show(); cout << endl;

	cout << "Assignment:" << endl << endl;

	Port c("Apple", "Tequila", 5);
	VintagePort d("Tax", 2, "Whiskey", 14);
	c = parent;
	d = child;
	c.show(); cout << endl;
	d.show(); cout << endl;

	cout << "Operations Check:" << endl << endl;

	a += 6;
	b += c.BottleCount();
	a.show(); cout << endl;
	b.show(); cout << endl;
	c -= a.BottleCount();
	d -= 1;
	c.show(); cout << endl;
	d.show(); cout << endl;

	return 0;
}