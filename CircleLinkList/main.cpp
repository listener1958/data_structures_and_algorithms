#include <iostream>

using namespace std;

/*����洢�ṹ*/
typedef struct CLinkList
{
	int data;
	struct CLinkList *next;
}node;

/*************************************************/
/*����                                           */
/*************************************************/

/*����*/
void ds_insert(node* pNode, int data)
{
	node* p, *p1, *temp;
	if (pNode == nullptr)
		return;

	p = pNode;
	p1 = pNode->next;

	while (data > p1->data)
	{
		p = p1;
		p1 = p1->next;
	}

	temp = new node();
	if (!temp)
		exit(0);

	temp->data = data;
	p->next = temp;
	temp->next = p1;
}

/*����*/
void ds_traverse(node *pNode)
{
	node *p;
	if (pNode == nullptr)
		return;
	p = pNode->next;

	while (p->data<INT_MAX)
	{
		cout << p->data << '\t';
		p = p->next;
	}
}

/*��ʼ��ѭ������*/
void ds_init(node* &pNode)
{
	int datain;
	node *temp;

	if (!pNode)
	{
		temp = new node();
		if (!temp)
			exit(0);

		temp->data = INT_MAX;
		temp->next = temp;
		pNode = temp;
	}

	cout << "�������������ڵ�ֵ������0������" << endl;
	cin >> datain;
	while (datain)
	{
		fflush(stdin);
		ds_insert(pNode, datain);
		cin >> datain;
	} 
}

void ds_delete(node *pNode, int data)
{
	node* p, *p1, *temp;
	if (pNode == nullptr)
		return;

	p = pNode;
	p1 = pNode->next;

	while (data > p1->data)
	{
		p = p1;
		p1 = p1->next;
	}
	if (data == p1->data)
	{
		p->next = p1->next;
		delete p1;
	}
}

int ds_search(node *pNode, int data)
{
	node* p, *p1, *temp;
	int i=1;
	if (pNode == nullptr)
		return 0;

	p = pNode;
	p1 = pNode->next;

	while (data > p1->data)
	{
		p = p1;
		p1 = p1->next;
		i++;
	}
	if (data == p1->data)
	{
		return i;
	}
	return 0;
}

int main()
{
	char in=1;
	int data;
	node *pLL;
	pLL = nullptr;

	cout << "---------------------------------------------"<<endl
		<< "ѭ������������ϰ��" << endl
		<< "---------------------------------------------" << endl<<endl;

	do{
		cout << "������Ҫ���еĲ�����0�˳���" << endl;
		cout << "1.��ʼ������" << endl << endl
			<< "2.����ڵ�" << endl << endl
			<< "3.ɾ���ڵ�" << endl << endl
			<< "4.���ؽڵ�λ��" << endl << endl
			<< "5.��������" << endl << endl;
		cin >> in;
		fflush(stdin);
		switch (in)
		{
		case '1':
			ds_init(pLL);
			cout << "--------------------------------" << endl
				<< "����ֵ���£�" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '2':
			cout << "�������ֵ��";
			cin >> data;
			fflush(stdin);
			ds_insert(pLL, data);
			cout << "--------------------------------" << endl
				<< "����ֵ���£�" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '3':
			cout << "����ɾ��ֵ��";
			cin >> data;
			fflush(stdin);
			ds_delete(pLL, data);
			cout << "--------------------------------" << endl
				<< "����ֵ���£�" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '4':
			cout << "�������ֵ��";
			cin >> data;
			fflush(stdin);
			data = ds_search(pLL, data);
			if(data)
				cout << "����ֵ" << "λ��Ϊ��" << data << endl << endl;
			else
				cout<<"����ֵ" << "�����ڡ�" << endl << endl;
			break;
		case '5':
			cout << "--------------------------------" << endl
				<< "����ֵ���£�" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		default:
			break;
		}
	} while (in != '0');

	system("pause");
	return 0;
}