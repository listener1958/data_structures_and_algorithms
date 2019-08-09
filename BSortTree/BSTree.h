#pragma once

struct Point {
	int data;
	Point *left;
	Point *right;
};

class BSTree
{
	Point *head;
public:
	BSTree();
	void insert(int k);
	int search(int k);
	~BSTree();
};

