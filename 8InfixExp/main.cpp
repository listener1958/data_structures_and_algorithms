#include<iostream>
#include "stack_s.h"
//#include "stack_s.cpp"

#define NUMSIZE 10

using namespace std;

//const char operatorT[]={}

int priorityCal(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

int trypush(stack_c &st, char opera)
{
	char c;
	if (st.pop(c))
	{
		if (opera == ')')
		{
			if (c == '(')
				return 1;
			else
			{
				st.push(c);
				return 0;
			}	
		}
		if (opera == '(')
		{
			st.push(c);
			st.push(opera);
			return 1;
		}
		if (priorityCal(opera) <= priorityCal(c))
		{
			st.push(c);
			return 0;
		}
		else
		{
			st.push(c);
			st.push(opera);
			return 1;
		}
	}

	st.push(opera);
	return 1;
}

int expcal(double& d1, double& d2, char c)
{
	switch (c)
	{
	case '+':
		d1 = d1 + d2;
		break;
	case '-':
		d1 = d1 - d2;
		break;
	case '*':
		d1 = d1 * d2;
		break;
	case '/':
		d1 = d1 / d2;
		break;
	case '^':
		d1 = pow(d1, d2);
		break;
	default:
		return 0;
	}

	return 1;
}

int main()
{
	stack_d sNum;
	stack_c sOperator;
	

	cout << "��������׺���ʽ��֧�ּӼ��˳��˷����Ÿ��������㣬������������Կո���������ʽ��#������" << endl;

	char c, c1;  //c�����ַ����գ�c1�����������
	char str[NUMSIZE];
	int i = 0;
	double d1, d2; //�������м����
	d1 = d2 = 0;

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
				d1 = atof(str);
				sNum.push(d1);
				i = 0;
			}
		}
		else
		{
			while (!trypush(sOperator, c))
			{
				if (sOperator.pop(c1) && sNum.pop(d2) && sNum.pop(d1))
				{
					if (expcal(d1, d2, c1))
					{
						sNum.push(d1);
					}
				}
				else
				{
					cout << "�������" << endl;
					system("pause");
					return 0;
				}
			}
			/*switch (c)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case ')':

			default:
				cout << "�������" << endl;
				system("pause");
				return 0;
				break;

			}*/
		}
		cin.get(c);
	}

	while (sOperator.pop(c1) && sNum.pop(d2) && sNum.pop(d1))
	{
		if (expcal(d1, d2, c1))
		{
			sNum.push(d1);
		}
	}
	if (!sOperator.pop(c1) && sNum.pop(d1) && !sNum.pop(d2))
	{
		cout << "��������" << d1 << endl;
	}
	else
	{
		cout << "�������" << endl;
		system("pause");
		return 0;
	}

	/*if (sc_pop(st, d) && !sc_pop(st, d1))
	{
		cout << "��������" << d << endl;
	}
	else
	{
		cout << "�������" << endl;
	}*/

	system("pause");
	return 0;
}