#include <iostream>

using namespace std;

/*链表存储结构*/
typedef struct CLinkList
{
	int data;
	struct CLinkList *next;
}node;

/*************************************************/
/*操作                                           */
/*************************************************/

/*插入*/
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

/*遍历*/
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

/*初始化循环链表*/
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

	cout << "请输入插入链表节点值，输入0结束：" << endl;
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
		<< "循环有序链表练习。" << endl
		<< "---------------------------------------------" << endl<<endl;

	do{
		cout << "请输入要进行的操作，0退出：" << endl;
		cout << "1.初始化链表" << endl << endl
			<< "2.插入节点" << endl << endl
			<< "3.删除节点" << endl << endl
			<< "4.返回节点位置" << endl << endl
			<< "5.遍历链表" << endl << endl;
		cin >> in;
		fflush(stdin);
		switch (in)
		{
		case '1':
			ds_init(pLL);
			cout << "--------------------------------" << endl
				<< "链表值如下：" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '2':
			cout << "输入插入值：";
			cin >> data;
			fflush(stdin);
			ds_insert(pLL, data);
			cout << "--------------------------------" << endl
				<< "链表值如下：" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '3':
			cout << "输入删除值：";
			cin >> data;
			fflush(stdin);
			ds_delete(pLL, data);
			cout << "--------------------------------" << endl
				<< "链表值如下：" << endl;
			ds_traverse(pLL);
			cout << endl << "--------------------------------" << endl << endl;
			break;
		case '4':
			cout << "输入查找值：";
			cin >> data;
			fflush(stdin);
			data = ds_search(pLL, data);
			if(data)
				cout << "查找值" << "位置为：" << data << endl << endl;
			else
				cout<<"查找值" << "不存在。" << endl << endl;
			break;
		case '5':
			cout << "--------------------------------" << endl
				<< "链表值如下：" << endl;
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