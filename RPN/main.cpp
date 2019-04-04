/*ʹ�ú�׺���ʽ����*/


#include<iostream>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define NUMSIZE 10

using namespace std;

typedef double stacktype;

struct stack
{
	stacktype *top, *base;
	int size;
};

void sc_init(stack *p)
{
	p->base = p->top = new stacktype[STACK_INIT_SIZE];
	p->size = STACK_INIT_SIZE;
}

void sc_push(stack *p, stacktype c)
{
	if (p->top - p->base == p->size - 1)
	{
		stacktype *p1, *p2, *p3;
		p2 = p1 = new stacktype[p->size + STACKINCREMENT];
		p3 = p->base;
		while (p3 <= p->top)
		{
			*p2 = *p3;
			p3++;
			p2++;
		}
		delete p->base;
		p->top = --p2;
		p->base = p1;
		p->size += STACKINCREMENT;
	}

	*(++p->top) = c;
}

int sc_pop(stack *p, stacktype &c)
{
	if (p->top == p->base)
		return 0;

	c = *p->top;
	p->top--;
	return 1;
}

int main()
{
	char c;
	char str[NUMSIZE];
	int i = 0;
	double d,d1;
	d = d1 = 0;
	stack *st = new stack;

	sc_init(st);
	cout << "�������׺���ʽ������֮���Լ�������������ÿո��������#������" << endl;
	cin >> c;
	while (c != '#')
	{
		if (isdigit(c))
		{
			if (i >= NUMSIZE - 1)
			{
				cout << "����λ�����࣡" << endl;
				system("pause");
				return 0;
			}
			str[i++] = c;
			str[i] = '\0';

		}
		else if (c == '.')
		{
			if (i >= NUMSIZE - 1)
			{
				cout << "����λ�����࣡" << endl;
				system("pause");
				return 0;
			}
			if (i == 0)
			{
				cout << "������������" << endl;
				system("pause");
				return 0;
			}
			str[i++] = c;
			str[i] = '\0';
		}
		else if (c == ' ')
		{
			if (i != 0)
			{
				d = atof(str);
				sc_push(st, d);
				i = 0;
			}
		}
		else
		{
			switch (c)
			{
			case '+':
				if (sc_pop(st, d) && sc_pop(st, d1))
				{
					d = d + d1;
					sc_push(st, d);
				}
				else
				{
					cout << "�������" << endl;
					system("pause");
					return 0;
				}
				break;
			case '-':
				if (sc_pop(st, d) && sc_pop(st, d1))
				{
					d = d1 - d;
					sc_push(st, d);
				}
				else
				{
					cout << "�������" << endl;
					system("pause");
					return 0;
				}
				break;
			case '*':
				if (sc_pop(st, d) && sc_pop(st, d1))
				{
					d = d * d1;
					sc_push(st, d);
				}
				else
				{
					cout << "�������" << endl;
					system("pause");
					return 0;
				}
				break;
			case '/':
				if (sc_pop(st, d) && sc_pop(st, d1))
				{
					d = d1 / d;
					sc_push(st, d);
				}
				else
				{
					cout << "�������" << endl;
					system("pause");
					return 0;
				}
				break;
			default:
				cout << "�������" << endl;
				system("pause");
				return 0;
				break;

			}
		}
		cin.get(c);
	}
	if (sc_pop(st, d) && !sc_pop(st, d1))
	{
		cout << "��������" << d << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	

	system("pause");
	return 0;
}