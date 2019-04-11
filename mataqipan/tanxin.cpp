//��̤�����㷨��
//�������������Ϊ8 * 8�ķ������̣��ֽ�������������ָ���ķ����У����ա�������Ĺ��򽫡��������ƶ���
//Ҫ��ÿ������ֻ�ܽ���һ�Σ�����ʹ�á����߱�����64������
//����˼·������ͼ�����������������ÿһ���������ܰ���������ת��ʽ��ȡ��һ������ݡ�
//ÿһ�ڵ�������8���ӽڵ㣬�ʸ��Ӷ�Ϊ8^64

//�㷨�Ľ������������̣���¼ÿ���ڵ㵱ǰ���е��ӽڵ㣬ÿ��ȡ��һ�ڵ���ӽڵ���ٵĿ�ʼȡ��̰�ķ���ÿ��ȡ�ӽڵ���٣���ʹ�����ձ����������٣�


#include <iostream>
#define MAX 255
using namespace std;

#define X2 8   //����x�����С
#define Y2 8   //����y�����С

int chess2[X2][Y2];
int nextconut[X2][Y2];  //̰�ķ��㷨�Ż�

int traverseChessTanxin(int x, int y, int tag);
void nextcUpdate();  //��ʼ������nextconut   ̰�ķ��㷨�Ż�
void initchess();

void initchess()
{
	for (int i = 0; i < X2; i++)
	{
		for (int j = 0; j < Y2; j++)
			chess2[i][j] = 0;
	}
}
int valid2(int x, int y)  //�жϽڵ��Ƿ���Ч
{
	if (x<0 || y<0 || x >= X2 || y >= Y2)
		return 0;
	if (chess2[x][y] != 0)
		return 0;

	return 1;
}
void nextcUpdate()  //��ʼ������nextconut   ̰�ķ��㷨�Ż�
{
	for (int i = 0; i < X2; i++)
	{
		for (int j = 0; j < Y2; j++)
		{
			nextconut[i][j] = 0;
			if (valid2(i + 1, j - 2))
				nextconut[i][j]++;
			if (valid2(i + 2, j - 1))
				nextconut[i][j]++;
			if (valid2(i + 2, j + 1))
				nextconut[i][j]++;
			if (valid2(i + 1, j + 2))
				nextconut[i][j]++;
			if (valid2(i - 1, j + 2))
				nextconut[i][j]++;
			if (valid2(i - 2, j + 1))
				nextconut[i][j]++;
			if (valid2(i - 2, j - 1))
				nextconut[i][j]++;
			if (valid2(i - 1, j - 2))
				nextconut[i][j]++;
		}
	}
}
int getNext(int x, int y, int next[][2])   //����count��ȡָ��λ����һ�ڵ�
{
	int c[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	int min = INT16_MAX;
	int min_x;  //���߽ڵ����ٵĽڵ�

	if (valid2(x + 1, y - 2))  //��1
		c[0] = nextconut[x + 1][y - 2];
	if (valid2(x + 2, y - 1))  //��2
		c[1] = nextconut[x + 2][y - 1];
	if (valid2(x + 2, y + 1))  //��3
		c[2] = nextconut[x + 2][y + 1];
	if (valid2(x + 1, y + 2))  //��4
		c[3] = nextconut[x + 1][y + 2];
	if (valid2(x - 1, y + 2))  //��5
		c[4] = nextconut[x - 1][y + 2];
	if (valid2(x - 2, y + 1))  //��6
		c[5] = nextconut[x - 2][y + 1];
	if (valid2(x - 2, y - 1))  //��7
		c[6] = nextconut[x - 2][y - 1];
	if (valid2(x - 1, y - 2))  //��8
		c[7] = nextconut[x - 1][y - 2];

	for (int i = 0; i < nextconut[x][y]; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (c[j] != -1)
			{
				if (c[j] < min)
				{
					min = c[j];
					min_x = j;
					c[j] = -1;
				}
			}
		}
		switch (min_x+1)
		{
		case 1:
			next[i][0] = x + 1;
			next[i][1] = y - 2;
			break;
		case 2:
			next[i][0] = x + 2;
			next[i][1] = y - 1;
			break;
		case 3:
			next[i][0] = x + 2;
			next[i][1] = y + 1;
			break;
		case 4:
			next[i][0] = x + 1;
			next[i][1] = y + 2;
			break;
		case 5:
			next[i][0] = x - 1;
			next[i][1] = y + 2;
			break;
		case 6:
			next[i][0] = x - 2;
			next[i][1] = y + 1;
			break;
		case 7:
			next[i][0] = x - 2;
			next[i][1] = y - 1;
			break;
		case 8:
			next[i][0] = x - 1;
			next[i][1] = y - 2;
			break;
		}
	}

	return 1;
}
int traverseChessTanxin(int x, int y, int tag)
{
	chess2[x][y] = tag;
	if (tag == X2*Y2)
	{
		cout << "����������" << endl;
		for (int i = 0; i < X2; i++)
		{
			for (int j = 0; j < Y2; j++)
			{
				cout << chess2[i][j] << '\t';
			}
			cout << endl;
		}
		return 1;
	}

	nextcUpdate();
	int next[8][2];    //�洢��һ�ڵ�,�����8��
	int cMax = nextconut[x][y];  //�洢��ǰ�ɷ�����һ�ڵ�����
	getNext(x, y, next);
	
	int count = 0;
	int result = 0;
	int xx, yy;
	while (result == 0 && count < cMax)
	{
		xx = next[count][0], yy = next[count][1];
		
		result = traverseChessTanxin(xx, yy, tag + 1);

		if (!result)
			count++;
	}
	if (count == cMax)
	{
		chess2[x][y] = 0;
		return 0;
	}

	return 1;
}
