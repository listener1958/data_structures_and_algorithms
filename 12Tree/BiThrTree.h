#pragma once

//线索树

typedef char trnodetype;
#define       treeEnd     '\0'      //树输入结束标志
#define       nodeEnd     ' '       //树输入节点为空标志


enum trnotype { linked, thread };

class BiThrTree  //BinaryThreadTree
{
	struct trnode
	{
		trnodetype data;
		trnode *lchild, *rchild;
		trnodetype ltype, rtype;
	};
	trnode *head;  // 头结点
	trnode *root;  // 树根节点
	trnode *pre;   // 树线索生成中间变量
	trnodetype *str; //构造树时输入字符串
	void treeinit(trnode *&tr);
	void inorderTraThr(trnode *tr);
	void visit(trnode *tr);  //节点输出
	void getThread();
public:
	BiThrTree(trnodetype *);
	void inorderTraversal();
	~BiThrTree();
};

