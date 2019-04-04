#include "linkedTable.h"



linkedTable::linkedTable()
{
	linkedNode* p = new linkedNode();
	
	p->data = 0;
	p->next = nullptr;
	head = end = p;
}

int linkedTable::AddNode(int data)
{
	linkedNode* p = new linkedNode();
	if (p == nullptr)
		return -1;
	p->data = data;
	p->next = nullptr;
	end->next = p;
	end = p;

	return 1;
}

ostream& operator<<(ostream& out, linkedTable& obj)
{
	linkedNode* p = obj.head;
	while (p->next != nullptr)
	{
		p = p->next;
		out << p->data << ",";
	}

	return out;
}

linkedTable::~linkedTable()
{
	linkedNode* p;
	while (this->head->next != nullptr)
	{
		p = this->head;
		this->head = p->next;
		delete p;
	}
	delete this->head;
}
