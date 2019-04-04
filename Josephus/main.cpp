#include<iostream>

using namespace std;

typedef struct node
{
	int num,sc;
	node *next;
}node;

void josephus()
{
	//��˵������̫��ʷѧ�� Josephus�й����µĹ��£���������ռ���������غ�39����̫����Josephus���������Ѷ㵽һ�����У�
	//39����̫�˾�����Ը��Ҳ��Ҫ������ץ�������Ǿ�����һ����ɱ��ʽ��41�����ų�һ��ԲȦ���ɵ�1���˿�ʼ������ÿ��������3
	//�˸��˾ͱ�����ɱ��Ȼ��������һ�����±�����ֱ�������˶���ɱ����Ϊֹ��Ȼ��Josephus���������Ѳ�������ӣ�JosephusҪ
	//���������ȼ�װ��ӣ������������Լ������ڵ�16�����31��λ�ã������ӹ����ⳡ������Ϸ��
	//���⣺��ѭ������ģ��Լɪ�����⣬��41������ɱ��˳���������

	node *pHead, *temp, *p;
	int i;
	pHead = new node();
	pHead->num = 1;
	p = pHead;
	for (i = 1; i < 41; i++)
	{
		temp = new node();
		temp->num = i + 1;
		p->next = temp;
		p = temp;
	}
	p->next = pHead;

	//p = pHead;
	//temp = pHead;
	//i = 0;
	//do {
	//	i++;
	//	if (i == 3)
	//	{
	//		temp->next = p->next;
	//		cout << p->num << '\t';
	//		delete p;
	//		p = temp->next;
	//		pHead = p;
	//		i = 1;
	//		//continue;
	//	}
	//	temp = p;
	//	p = p->next;
	//} while (p != pHead);
	p = pHead;
	temp = pHead;
	i = 0;
	while (true)
	{
		i++;
		if (i == 3)
		{
			temp->next = p->next;
			cout << p->num << '\t';
			if (temp == p)
			{
				delete p;
				break;
			}
			delete p;

			p = temp->next;
			pHead = p;
			i = 1;
		}
		temp = p;
		p = p->next;
	}

	return;
}

void josephus2()
{
	//���Ϊ1��N��N���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ�����루�������������������룩����ʼ��ѡһ����������Ϊ����
	//����ֵM���ӵ�һ���˰�˳ʱ�뷽����1��ʼ˳����������Mʱֹͣ��������M���˳��У�������������Ϊ�µ�Mֵ������˳
	//ʱ�뷽���ϵ���һ���˿�ʼ��1�����������ȥ��ֱ��������ȫ������Ϊֹ��

	node *pHead, *temp, *p;
	int i,n,m;

	cout << "����������N��";
	cin >> n;

	cout << "�������1�˵����룺";
	cin >> m;
	pHead = new node();
	pHead->num = 1;
	pHead->sc = m;
	p = pHead;
	for (i = 1; i < n; i++)
	{
		cout << "�������"<<i+1<<"�˵����룺";
		cin >> m;
		temp = new node();
		temp->num = i + 1;
		temp->sc = m;
		p->next = temp;
		p = temp;
	}
	p->next = pHead;

	p = pHead;
	temp = pHead;
	i = 0;
	while (true)
	{
		i++;
		if (i == pHead->sc)
		{
			temp->next = p->next;
			cout << p->num << '\t';
			if (temp == p)
			{
				delete p;
				break;
			}
			delete p;

			p = temp->next;
			pHead = p;
			i = 1;
		}
		temp = p;
		p = p->next;
	}

	return;

}

int main()
{
	//cout << "����������Ϊ��" << endl;
	//josephus();
	//cout << endl;

	josephus2();

	system("pause");
	return 0;
}

