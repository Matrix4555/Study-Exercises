#include <iostream>
#include <string.h>

using namespace std;

class Abstract
{
public:
	virtual void view() =0;
protected:
	char* label;
	int rating;
};

class baseDMA : public Abstract
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const baseDMA& rs);
	void view();
};

class lacksDMA : public baseDMA
{
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	void view();
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
};

class hasDMA : public baseDMA
{
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend ostream& operator<<(ostream& os, const hasDMA& rs);
	void view();
private:
	char* style;
};

baseDMA::baseDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

ostream& operator<<(ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}

void baseDMA::view()
{
	cout << *this << endl;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l, r)
{
	strcpy_s(color, strlen(c) + 1, c);
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs)
{
	strcpy_s(color, strlen(c) + 1, c);
}

void lacksDMA::view()
{
	cout << *this << endl;
}

ostream& operator<<(ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color << endl;
	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);
	delete[] style;
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

void hasDMA::view()
{
	cout << *this << endl;
}

ostream& operator<<(ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << endl;
	return os;
}

int main()
{
	int kind;
	cout << "Select kind of object to create: ";

	while (cin >> kind && (kind != 1 && kind != 2 && kind != 3))
		cout << "Incorrect! Select kind of object to create: ";

	Abstract* abs;

	switch (kind)
	{
	case 1:
		{
			const char* a = "Label One";
			abs = new baseDMA(a, 1);
			abs->view();
			delete abs;
			break;
		}
	case 2:
		{
			const char* a = "Label Two";
			const char* b = "Color";
			abs = new lacksDMA(b, a, 2);
			abs->view();
			delete abs;
			break;
		}
	case 3:
		{
			const char* a = "Label Three";
			const char* b = "Style";
			abs = new hasDMA(b, a, 3);
			abs->view();
			delete abs;
			break;
		}
	}

	return 0;
}