#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Person
{
public:
	Person() : name("unknown name"), lastName("unknown surname") { }
	Person(const string& n, const string& ln) : name(n), lastName(ln) { }
	Person(const Person& p) : name(p.name), lastName(p.lastName) { }
	virtual ~Person() { }
	virtual void show() const;
protected:
	string name;
	string lastName;
};

class Gunslinger : virtual public Person
{
public:
	Gunslinger() : Person(), time(0), ammo(0) { }
	Gunslinger(const string& n, const string& ln, const double t, const int a) : Person(n, ln), time(t), ammo(a) { }
	Gunslinger(const Person& p, const double t, const int a) : Person(p), time(t), ammo(a) { }
	Gunslinger(const Gunslinger& g) : Person(g.name, g.lastName), time(g.time), ammo(g.ammo) { }
	const double draw() const { return time; }
	const int drawAmmo() const { return ammo; }
	virtual void show() const;
private:
	double time;
	int ammo;
};

class Card		// additional class for poker player
{
public:
	Card() : suit("unknown"), num(0) { }
	Card(const string& s, const int n) : suit(s), num(n) { }
	Card(const Card& c) : suit(c.suit), num(c.num) { }
	void getData() const
	{
		cout << "Card is: Suit = " << suit << ", " << "Number = " << num << endl;
	}
private:
	string suit;
	int num;
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer() : Person() { card = new Card(); }
	PokerPlayer(const string& n, const string& ln, const Card& c) : Person(n, ln) { card = new Card(c); }
	PokerPlayer(const Person& p, const string& s, const int n) : Person(p) { card = new Card(s, n); }
	PokerPlayer(const Person& p, const Card& c) : Person(p) { card = new Card(c); }
	PokerPlayer(const PokerPlayer& pp) : Person(pp.name, pp.lastName), card(pp.card) { }
	virtual ~PokerPlayer() { delete card; }
	const Card draw() const { return *card; }
	virtual void show() const;
protected:
	Card* card;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude() : Person(), Gunslinger(), PokerPlayer() { }
	BadDude(const string& n, const string& ln, const double t, const int a, const string& c1, const int c2) : Person(n, ln), Gunslinger(n, ln, t, a), PokerPlayer(n, ln, Card(c1, c2)) { }
	BadDude(const string& n, const string& ln, const double t, const int a, const Card& c) : Person(n, ln), Gunslinger(n, ln, t, a), PokerPlayer(n, ln, c) { }
	const double gDraw() const { Gunslinger::draw(); }
	const Card cDraw() const { PokerPlayer::draw(); }
	void show() const;
};

void Person::show() const
{
	if (name == "unknown name" && lastName == "unknown surname")
	{
		cout << "person has not name" << endl;
		return;
	}
	cout << "Name is " << name << " " << lastName << endl;
}

void Gunslinger::show() const
{
	Person::show();
	cout << "Time = " << time << endl << "Ammo = " << ammo << endl;
}

void PokerPlayer::show() const
{
	Person::show();
	card->getData();
}

void BadDude::show() const
{
	Person::show();
	cout << "Time = " << Gunslinger::draw() << endl << "Ammo = " << Gunslinger::drawAmmo() << endl;
	card->getData();
}

int main()
{
	const int SIZE = 5;
	Person* human[SIZE];

	int i = 0;
	for (; i < SIZE; i++)
	{
		char choice;
		cout << "Enter the person category:" << endl
			<< "h - person" << endl << "g - gunslinger" << endl
			<< "p - pokerplayer" << endl << "b - baddude" << endl
			<< "q - quit" << endl;
		cout << "Your choice: ";  cin >> choice;
		while (choice != 'h' && choice != 'g' && choice != 'p' && choice != 'b' && choice != 'q')
		{
			cout << "Incorrect input! Please repeat. ";
			cout << "Your choice: ";  cin >> choice;
		}

		if (choice == 'q') break;

		switch (choice)
		{
		case 'h': human[i] = new Person("Martin", "Freeman"); break;
		case 'g': human[i] = new Gunslinger("Sherlock", "Holmes", 3, 13); break;
		case 'p': human[i] = new PokerPlayer("Rick", "Tyler", Card("Spades", 8)); break;
		case 'b': human[i] = new BadDude("Angry", "Someone", 4, 33, Card("Hearts", 9)); break;
		}
		cout << "Human created successfully" << endl;
	}

	if (i != 0)
		cout << endl << "All of information:" << endl << endl;

	for (int k = 0; k < i; k++)
	{
		string type = typeid(*human[k]).name();
		type.erase(0, 6);
		cout << k + 1 << ": " << type << " >>" << endl;
		human[k]->show();
		cout << endl;
		delete human[k];
	}

	return 0;
}
