//ð������ÿ�α�����������������С���������������û���ÿ�α�����С/������޸�������ͷ/β��

void bubbSort(int num[], int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1; j >i; j--)
		{
			if (num[j - 1] > num[j])
			{
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
		}
	}
}