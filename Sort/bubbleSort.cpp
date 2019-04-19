//冒泡排序：每次遍历，若相邻两数大小不符合条件，则置换，每次遍历最小/最大数修改至数组头/尾。

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