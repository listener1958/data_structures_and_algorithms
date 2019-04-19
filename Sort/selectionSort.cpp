//选择排序：依次从所有数据中选择最小数，倒第2小数。。。，并放在首位，下一位。。。

void selecSort(int num[], int n)
{
	int temp, k;
	for (int i = 0; i < n; i++)
	{
		k = i;
		for (int j = i; j < n; j++)
			if (num[k] > num[j])
				k = j;
		temp = num[k];
		num[k] = num[i];
		num[i] = temp;
	}
		
}