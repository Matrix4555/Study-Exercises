#include <iostream>
#include <string>

using namespace std;

class Abstr
{
public:
	Abstr() : fname("none"), lname("none"), job("none") { }
	Abstr(const string& fn, const string& ln, const string& j) : fname(fn), lname(ln), job(j) { }
	virtual void showAll() const { cout << *this << " has job \"" << job << "\"" << endl; }
	virtual void setAll();
	friend ostream& operator<<(ostream& os, const Abstr& a);
	virtual ~Abstr() = 0 { }
protected:
	string fname;
	string lname;
	string job;
};

class Employee : public Abstr
{
public:
	Employee() : Abstr() { }
	Employee(const string& fn, const string& ln, const string& j) : Abstr(fn, ln, j) { }
	virtual void showAll() const { Abstr::showAll(); }
	virtual void setAll() { Abstr::setAll(); }
};

class Manager : virtual public Abstr
{
public:
	Manager() : Abstr(), inchargeof(0) { }
	Manager(const string& fn, const string& ln, const string& j, int ico = 0) : Abstr(fn, ln, j), inchargeof(ico) { }
	Manager(const Abstr& a, int ico) : Abstr(a), inchargeof(ico) { }
	Manager(const Manager& m) : Abstr(m.fname, m.lname, m.job), inchargeof(m.inchargeof) { }
	virtual void showAll() const { Abstr::showAll(); cout << "In Charge of: " << inchargeof << endl; }
	virtual void setAll() { Abstr::setAll(); cout << "In Charge of: "; cin >> inchargeof; }
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
private:
	int inchargeof;
};

class Fink : virtual public Abstr
{
public:
	Fink() : Abstr(), reportsto("none") { }
	Fink(const string& fn, const string& ln, const string& j, const string& rpo = "none") : Abstr(fn, ln, j), reportsto(rpo) { }
	Fink(const Abstr& a, const string& rpo) : Abstr(a), reportsto(rpo) { }
	Fink(const Fink& f) : Abstr(f.fname, f.lname, f.job), reportsto(f.reportsto) { }
	virtual void showAll() const { Abstr::showAll(); cout << "Reports to: " << reportsto << endl; }
	virtual void setAll() { Abstr::setAll(); cout << "Reports to: "; cin >> reportsto; }
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
private:
	string reportsto;
};

class Highfink : public Manager, public Fink
{
public:
	Highfink() : Abstr(), Manager(), Fink() { }
	Highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico) : Abstr(fn, ln, j), Fink(fn, ln, j, rpo), Manager(fn, ln, j, ico) { }
	Highfink(const Abstr& a, const string& rpo, int ico) : Abstr(a), Fink(a, rpo), Manager(a, ico) { }
	Highfink(const Fink& f, int ico) : Abstr(f), Fink(f), Manager(f, ico) { }
	Highfink(const Manager& m, const string& rpo) : Abstr(m), Fink(m, rpo), Manager(m) { }
	Highfink(const Highfink& h) : Abstr(h.fname, h.lname, h.job), Fink(h.fname, h.lname, h.job, h.ReportsTo()), Manager(h.fname, h.lname, h.job, InChargeOf()) { }
	virtual void showAll() const;
	virtual void setAll();
};

void Abstr::setAll()
{
	cout << "Name: "; cin >> fname;
	cout << "Last name: "; cin >> lname;
	cout << "Job: "; cin >> job;
}

ostream& operator<<(ostream& os, const Abstr& a)
{
	return os << a.fname << " " << a.lname;
}

void Highfink::showAll() const
{
	Abstr::showAll();
	cout << "In Charge of: " << Manager::InChargeOf() << endl;
	cout << "Reports to: " << Fink::ReportsTo() << endl;
}

void Highfink::setAll()
{
	Abstr::setAll();
	cout << "In Charge of: "; cin >> Manager::InChargeOf();
	cout << "Reports to: "; cin >> Fink::ReportsTo();
}

int main()
{
	Employee em("Trip", "Harris", "Thumber");
	cout << em << endl;
	em.showAll();

	Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.showAll();

	Fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.showAll();

	Highfink hf(ma, "Curly Kew");
	hf.showAll();

	cout << "Preass a key for next phase: ";
	cin.get();

	Highfink hf2;
	hf2.setAll();

	cout << "Using an Abstr* pointer:" << endl;
	Abstr* tri[4] = { &em,&fi, &hf,&hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->showAll();

	return 0;
}
