#pragma once
class kmpstr
{
	char *str;
	int *next;
	int size;
	void getNext();
public:
	kmpstr(char *, int size);
	int kmp(char *, int size);
	~kmpstr();
};

