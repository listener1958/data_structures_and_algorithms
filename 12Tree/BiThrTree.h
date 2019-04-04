#pragma once

//������

typedef char trnodetype;
#define       treeEnd     '\0'      //�����������־
#define       nodeEnd     ' '       //������ڵ�Ϊ�ձ�־


enum trnotype { linked, thread };

class BiThrTree  //BinaryThreadTree
{
	struct trnode
	{
		trnodetype data;
		trnode *lchild, *rchild;
		trnodetype ltype, rtype;
	};
	trnode *head;  // ͷ���
	trnode *root;  // �����ڵ�
	trnode *pre;   // �����������м����
	trnodetype *str; //������ʱ�����ַ���
	void treeinit(trnode *&tr);
	void inorderTraThr(trnode *tr);
	void visit(trnode *tr);  //�ڵ����
	void getThread();
public:
	BiThrTree(trnodetype *);
	void inorderTraversal();
	~BiThrTree();
};

