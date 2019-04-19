//堆排序：构造完全二叉树，大顶堆、小顶堆

void treeSort(int num[], int k, int n)
{
	int temp = num[k - 1];
	int c = k;
	for (int i = 2 * k; i <= n; i *= 2)
	{
		if (i + 1 <= n && num[i - 1] < num[i])
			i++;
		if (num[i - 1] > temp)
		{
			num[c - 1] = num[i - 1];
			c = i;
		}
	}
	num[c - 1] = temp;
}

void heapSort(int num[], int n)
{
	for (int i = n / 2; i > 0; i--)
	{
		treeSort(num, i, n);  //因为树的构造节点从1开始，而数组从0开始,此处输入按照树的编号
	}

	for (int i = n - 1; i > 0; i--)
	{
		int temp = num[i];
		num[i] = num[0];
		num[0] = temp;

		treeSort(num, 1, i);
	}
}