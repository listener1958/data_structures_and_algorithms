//�������򣺴�����β���α�����ÿ�α�������ǰλ�����ݲ����ѱ������ݲ��֣���֤�ѱ�����������

void insertSort(int num[], int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		if (num[i] < num[i - 1])
		{
			temp = num[i];
			for (j = i-1; j >= 0 && num[j]>temp; j--)
			{
				num[j + 1] = num[j];
			}
			num[j + 1] = temp;
		}
	}
}