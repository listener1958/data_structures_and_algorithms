//希尔排序：分组插入排序

void shellSort(int num[], int n)
{
	int temp, j;
	int gap = n;   //增量序列也可采用序列表如{...,9,5,3,2,1}
	do{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			temp = num[i];
			if (num[i] < num[i - gap])
			{
				for (j = i-gap; j>=0 && num[j]>temp; j -= gap)
				{
					num[j+gap] = num[j];
				}
				num[j + gap] = temp;
			}	
		}
	} while (gap > 1);
	
}