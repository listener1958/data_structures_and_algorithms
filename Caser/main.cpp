#include<iostream>

using namespace std;

struct node
{
	char c;
	node *next,*pre;
};

void creatDCLL(node* &p)
{
	node *temp,*p1;
	temp = new node;
	temp->c = 'a';
	temp->next = temp;
	temp->pre = temp;
	p = temp;
	p1 = temp;
	for (int i = 1; i < 26; i++)
	{
		temp = new node;
		temp->c = ('a'+i);
		temp->next = p;
		p->pre = temp;
		temp->pre = p1;
		p1->next = temp;
		p1 = temp;
	}

	return;
}

void hmove(node* &p,int i)
{
	if (i > 0)
		while (i--)
			p = p->next;
	else if(i<0)
		while (i++)
			p = p->pre;
}

void printLL(node *p)
{
	node *p1;
	p1 = p;
	while (p1->next != p)
	{
		cout << p1->c;
		p1 = p1->next;
	}
	cout << p1->c;
}

int main()
{
	node *pHead;
	int n;

	creatDCLL(pHead);
	cout << "ÇëÊäÈëÃÜÂë£º";
	cin >> n;
	hmove(pHead, n);
	cout << "ÃØÔ¿Îª£º" << endl;
	printLL(pHead);
	cout << endl;

	system("pause");
	return 0;
}