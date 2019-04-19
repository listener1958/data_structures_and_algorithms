//插入排序：从首至尾依次遍历，每次遍历将当前位置数据插入已遍历数据部分，保证已遍历部分有序

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