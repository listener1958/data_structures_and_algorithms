//���8�ʺ����⡣8X8�������ϣ��ڷ�8�����ӣ�ʹ��ÿһ�С�ÿһ�С�ÿ��б���Ͼ�ֻ��һ�����ӣ��ж����ְڷ���

#include <iostream>

using namespace std;

int queencount = 0;

int qsafe(int row, int col, int ch[][8])
{
	int i, j;
	//����
	i = 0;
	while (i < 8)
		if (ch[i++][col] == 1)
			return 0;
	//����
	i = row, j = col;
	while (i >= 0 && j >= 0)if (ch[i--][j--] == 1)return 0;
	//����
	i = row, j = col;
	while (i < 8 && j >= 0)if (ch[i++][j--] == 1)return 0;
	//����
	i = row, j = col;
	while (i >= 0 && j < 8)if (ch[i--][j++] == 1)return 0;
	//����
	i = row, j = col;
	while (i < 8 && j < 8)if (ch[i++][j++] == 1)return 0;

	return 1;
}

void eightqueen(int row, int col, int ch[][8])
{
	int chessb2[8][8];

	//ch[row][col] = 1;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			chessb2[i][j] = ch[i][j];

	if (row == 8)
	{
		queencount++;
		cout << "��" << queencount << "�ֽⷨ��" << endl;
		//chessb2[row][col] = 1;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << ch[i][j] << ' ';
			cout << endl;
		}	
	}
	else
	{
		//chessb2[row][col] = 1;
		for (int col1 = 0; col1 < 8; col1++)
		{
			if (qsafe(row, col1, chessb2))
			{
				for (int i = 0; i < 8; i++)
					chessb2[row][i] = 0;  //��ո��У�����ǰһ�α����Ὣ����һλ��1
				chessb2[row][col1] = 1;
				eightqueen(row + 1, col1, chessb2);
			}
		}
	}


}

int main()
{
	int chessboard[8][8];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			chessboard[i][j] = 0;

	//for (int i = 0; i < 8; i++)
	//{
	//	for (int j = 0; j < 8; j++)
	//		chessboard[0][j] = 0;  //��ո��У�����ǰһ�α����Ὣ����һλ��1
	//	eightqueen(0, i, chessboard);
	//}
	eightqueen(0, 8, chessboard);



	system("pause");
	return 0;
}