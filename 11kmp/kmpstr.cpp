#include "kmpstr.h"


kmpstr::kmpstr(char *s, int size)
{
	this->str = s;
	this->size = size;
	this->next = new int[size];
}

void kmpstr::getNext()
{
	int i, j;
	i = -1;
	j = 0;
	this->next[0] = -1;

	while (j < this->size - 1)
	{
		if (-1 == i || this->str[i] == this->str[j])
		{
			i++;
			j++;
			//一般情况next数组值为i，若str[i]与str[j]相等，那么str[j]匹配不成功则str[i]也一定匹配不成功，所以增加判断若str[i]与str[j]相等，next数组值直接置为next[i]
			if (this->str[i] != this->str[j])
			{
				this->next[j] = i;
			}
			else
			{
				this->next[j] = this->next[i];
			}

			//this->next[j] = i;
		}
		else
		{
			//回溯，前缀i是相对的
			i = this->next[i];
		}
	}
}

int kmpstr::kmp(char *s, int size)
{
	if (this->size > size)
		return -1;

	int i = 0, j = 0, x;
	x = size - this->size;

	this->getNext();

	while (i < size)
	{
		if (-1 == j || s[i] == this->str[j])
		{
			i++;
			j++;
			if (j >= this->size)
				return i - this->size;
		}
		else
		{
			j = this->next[j];
		}
	}

	return -1;
}

kmpstr::~kmpstr()
{
	delete[]this->next;
}
