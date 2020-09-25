#include <iostream>

using namespace std;

const int LEN = 80;
const int MAX = 40;

class Token
{
public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};


class Operator : public Token
{
public:
	Operator(char a)
	{
		oper = a;
	}

	char getOperator()
	{
		return oper;
	}

	virtual float getNumber() 
	{ 
		return 0.f; 
	}

private:
	char oper;
};


class Number : public Token
{
public:
	Number()
	{
		fnum = 0;
	}

	Number(float a)
	{
		fnum = a;
	}

	float getNumber()
	{
		return fnum;
	}
	
	virtual char getOperator() 
	{ 
		return '\0'; 
	}

private:
	float fnum;
};


class Stack
{
public:
	Stack()
	{
		top = 0;
	}

	void push(Token* a)		//it inserts from inputted string by one symbol
	{
		atoken[top++] = a;
	}

	Token* pop()
	{
		return atoken[--top];
	}

	int gettop()
	{
		return top;
	}

private:
	Token* atoken[100];		//it contains types Operator* and Number*
	int top;
};


class express
{
public:
	express(char* ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}

	void parse();
	float solve();
private:
	Stack s;
	char* pStr;
	int len;
};


void express::parse()
{
	char ch;
	Token* lastval;
	Token* lastop;
	float answer = 0;
	bool decimal = false;
	int shift = 10;
	float transformed;

	for (int j = 0; j <= len; j++)
	{
		ch = pStr[j];
		if ((ch >= '0' && ch <= '9') || ch == '.')
		{
			if (ch == '.')
			{
				decimal = true;
			}
			else
			{
				transformed = ch - '0';
				if (decimal)
				{
					transformed /= shift;
					shift *= 10;
					answer += transformed;
				}
				else
				{
					transformed /= shift;
					answer = (answer + transformed) * 10;
				}
			}
		}
		else
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				s.push(new Number(answer));
				answer = 0;
				decimal = false;
				shift = 10;
				if (s.gettop() == 1)
				{
					s.push(new Operator(ch));
				}
				else
				{
					lastval = s.pop();
					lastop = s.pop();
					if ((ch == '*' || ch == '/') && (lastop->getOperator() == '+' || lastop->getOperator() == '-'))
					{
						s.push(lastop);
						s.push(lastval);
					}
					else
					{
						switch (lastop->getOperator())
						{
						case '+':
							s.push(new Number(s.pop()->getNumber() + lastval->getNumber()));
							break;
						case '-':
							s.push(new Number(s.pop()->getNumber() - lastval->getNumber()));
							break;
						case '*':
							s.push(new Number(s.pop()->getNumber() * lastval->getNumber()));
							break;
						case '/':
							s.push(new Number(s.pop()->getNumber() / lastval->getNumber()));
							break;
						default:
							cout << "Неизвестный оператор" << endl; exit(1);
						}
					}
					s.push(new Operator(ch));
				}
			}
			else if (ch == '\0')
			{
				s.push(new Number(answer));
			}
			else
			{
				cout << "Неизвестный символ" << endl; exit(1);
			}
		}
	}
}


float express::solve()
{
	float lastval;
	while (s.gettop() > 1)
	{
		lastval = s.pop()->getNumber();										
		switch (s.pop()->getOperator())										
		{
		case '+':
			s.push(new Number(s.pop()->getNumber() - lastval));				
			break;															
		case '-':															
			s.push(new Number(s.pop()->getNumber() + lastval));
			break;
		case '*':
			s.push(new Number(s.pop()->getNumber() * lastval));				
			break;														
		case '/':
			s.push(new Number(s.pop()->getNumber() / lastval));
			break;
		default:
			cout << "Неизвестный оператор" << endl; exit(1);
		}
	}
	return s.pop()->getNumber();
}


int main()
{
	setlocale(LC_ALL, "Rus");
	char ans;
	char exa[LEN];

	cout << "Введите арифметическое выражение в виде 2+3*4/3-2"
		"\nЧисла должны быть из одной цифры"
		"\nНе используйте пробелы и скобки";

	do {
		cout << "\nВыражение: ";
		cin >> exa;
		express* eptr = new express(exa);
		eptr->parse();
		cout << "\nРезультат: " << eptr->solve();
		delete eptr;
		cout << endl << "Еще одно выражение (д/н)? ";
		cin >> ans;
	} while (ans == 'y');

	return 0;
}