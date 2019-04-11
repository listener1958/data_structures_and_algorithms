//��̤�����㷨��
//�������������Ϊ8 * 8�ķ������̣��ֽ�������������ָ���ķ����У����ա�������Ĺ��򽫡��������ƶ���
//Ҫ��ÿ������ֻ�ܽ���һ�Σ�����ʹ�á����߱�����64������
//����˼·������ͼ�����������������ÿһ���������ܰ���������ת��ʽ��ȡ��һ������ݡ�
//ÿһ�ڵ�������8���ӽڵ㣬�ʸ��Ӷ�Ϊ8^64

//�㷨�Ľ������������̣���¼ÿ���ڵ㵱ǰ���е��ӽڵ㣬ÿ��ȡ��һ�ڵ���ӽڵ���ٵĿ�ʼȡ��̰�ķ���ÿ��ȡ�ӽڵ���٣���ʹ�����ձ����������٣�
//���ļ�Ϊԭ�㷨���Ľ��㷨�� tanxin.cpp


#include <iostream>

using namespace std;

#define X 5   //����x�����С
#define Y 5   //����y�����С

int chess[X][Y];

int traverseChess(int x, int y, int tag);
int traverseChessTanxin(int x, int y, int tag);   //̰�ķ��㷨�Ż�
void nextcUpdate();  //��ʼ������nextconut   ̰�ķ��㷨�Ż�
void initchess();  //��ʼ������chess2   ̰�ķ��㷨�Ż�
int main()
{
	//��������
	//for (int i = 0; i < X; i++)
	//{
	//	for (int j = 0; j < Y; j++)
	//		chess[i][j] = 0;
	//}
	//if (!traverseChess(0, 0, 1))
	//{
	//	cout << "Traverse Failed!" << endl;
	//}

	//̰���㷨
	initchess();
	nextcUpdate();
	if (!traverseChessTanxin(1, 0, 1))
	{
		cout << "Traverse Failed!" << endl;
	}

	return 0;
}
int valid(int x, int y)  //�жϽڵ��Ƿ���Ч
{
	if ( x<0 || y<0 || x>=X || y>=Y )
		return 0;
	if ( chess[x][y] != 0 )
		return 0;

	return 1;
}
int getNext(int& x, int& y,int count)   //����count��ȡָ��λ����һ�ڵ�
{
	int xx = x;
	int yy = y;
	switch (count)
	{
	case 1:
		if (valid(xx + 1, yy - 2))
			x = xx + 1, y = yy - 2;
		break;
	case 2:
		if (valid(xx + 2, yy - 1))
			x = xx + 2, y = yy - 1;
		break;
	case 3:
		if (valid(xx + 2, yy + 1))
			x = xx + 2, y = yy + 1;
		break;
	case 4:
		if (valid(xx + 1, yy + 2))
			x = xx + 1, y = yy + 2;
		break;
	case 5:
		if (valid(xx - 1, yy + 2))
			x = xx - 1, y = yy + 2;
		break;
	case 6:
		if (valid(xx - 2, yy + 1))
			x = xx - 2, y = yy + 1;
		break;
	case 7:
		if (valid(xx - 2, yy - 1))
			x = xx - 2, y = yy - 1;
		break;
	case 8:
		if (valid(xx - 1, yy - 2))
			x = xx - 1, y = yy - 2;
		break;
	}

	if (x == xx || y == yy)
		return 0;

	return 1;
}
int traverseChess(int x, int y, int tag)
{
	chess[x][y] = tag;

	if (tag == X*Y)
	{
		cout << "����������" << endl;
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				cout << chess[i][j] << '\t';
			}
			cout << endl;
		}	
		return 1;
	}
	int count = 1;
	int result = 0;
	int xx = x, yy = y;
	while (result == 0 && count <= 8)
	{
		xx = x, yy = y;
		if (getNext(xx, yy, count))
		{
			result = traverseChess(xx, yy, tag + 1);
		}
		if (!result)
			count++;
	}
	if (count == 9)
	{
		chess[x][y] = 0;
		return 0;
	}
		
	return 1;
}
