#include "BiThrTree.h"
#include <iostream>


BiThrTree::BiThrTree(trnodetype *s)
{
	str = s;
	treeinit(root);
	str = s;
	
	getThread();
}

void BiThrTree::treeinit(trnode *& tr)
{
	if (*str == treeEnd)
	{
		return;  //输入字符串有问题
	}
	if (*str == nodeEnd)
	{
		tr = nullptr;
	}
	else
	{
		tr = new trnode();
		tr->data = *str;
		tr->ltype = linked;
		tr->rtype = linked;
		str++;
		treeinit(tr->lchild);
		str++;
		treeinit(tr->rchild);
	}
}

void BiThrTree::inorderTraThr(trnode * tr)
{
	if (tr)
	{
		inorderTraThr(tr->lchild);
		if (tr->lchild == nullptr)
		{
			tr->ltype = thread;
			tr->lchild = pre;
		}
		if (pre->rchild == nullptr)
		{
			pre->rtype = thread;
			pre->rchild = tr;
		}
		pre = tr;
		inorderTraThr(tr->rchild);
	}
}

void BiThrTree::getThread()
{
	head = new trnode;
	head->data = treeEnd;
	head->lchild = root;
	head->ltype = linked;
	pre = head;

	inorderTraThr(root);

	pre->rtype = thread;
	pre->rchild = head;
	head->rchild = pre;
	head->rtype = thread;  
}

void BiThrTree::visit(trnode * tr)
{
	std::cout << tr->data;
}

void BiThrTree::inorderTraversal()
{
	trnode *tr = root;
	while (tr != head&&tr != nullptr)
	{
		while (tr->ltype == linked)
		{
			tr = tr->lchild;
		}
		//输出该节点tr
		visit(tr);
		while (tr->rtype == thread&&tr->rchild != head)
		{
			tr = tr->rchild;
			//输出该节点tr
			visit(tr);
		}

		tr = tr->rchild;
	}
	//std::cout << std::endl;
}


BiThrTree::~BiThrTree()
{

}
