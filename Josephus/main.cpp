#include<iostream>

using namespace std;

typedef struct node
{
	int num,sc;
	node *next;
}node;

void josephus()
{
	//据说著名犹太历史学家 Josephus有过以下的故事：在罗马人占领乔塔帕特后，39个犹太人与Josephus及他的朋友躲到一个洞中，
	//39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，由第1个人开始报数，每报数到第3
	//人该人就必须自杀，然后再由下一个重新报数，直到所有人都自杀身亡为止。然而Josephus和他的朋友并不想遵从，Josephus要
	//他的朋友先假装遵从，他将朋友与自己安排在第16个与第31个位置，于是逃过了这场死亡游戏。
	//问题：用循环链表模拟约瑟夫问题，把41个人自杀的顺序编号输出。

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
	//编号为1～N的N个人按顺时针方向围坐一圈，每人持有一个密码（正整数，可以自由输入），开始人选一个正整数作为报数
	//上限值M，从第一个人按顺时针方向自1开始顺序报数，报道M时停止报数。报M的人出列，将他的密码作为新的M值，从他顺
	//时针方向上的下一个人开始从1报数，如此下去，直至所有人全部出列为止。

	node *pHead, *temp, *p;
	int i,n,m;

	cout << "请输入人数N：";
	cin >> n;

	cout << "请输入第1人的密码：";
	cin >> m;
	pHead = new node();
	pHead->num = 1;
	pHead->sc = m;
	p = pHead;
	for (i = 1; i < n; i++)
	{
		cout << "请输入第"<<i+1<<"人的密码：";
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
	//cout << "出列数依次为：" << endl;
	//josephus();
	//cout << endl;

	josephus2();

	system("pause");
	return 0;
}

