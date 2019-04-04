#pragma once

#include "linkedNode.h"
#include<iostream>

using namespace std;

class linkedTable
{
	friend ostream& operator<<(ostream& out, linkedTable& obj);
	linkedNode *head;
	linkedNode *end;
public:
	linkedTable();

	int AddNode(int data);
	
	~linkedTable();
};

