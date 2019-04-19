//归并排序：将两组有序序列合并为1组有序序列，开始讲大小为n的序列分为n组有序序列，然后不断合并，至最终只有1个有序序列

void mSort(int *num,int n)
{
	if (1==n)  //区间左右节点相同，递归至仅有1节点
	{
		return;
	}
	else
	{
		int i, j, k;
		int l = n / 2;
		int r = n - l;
		int *numtemp;
		numtemp = new int[n];
		for (int i = 0; i < n; i++)
			numtemp[i] = num[i];
		mSort(numtemp, l);
		mSort(&(numtemp[l]), r);
		k = i = 0, j = l;
		while (i < l && j < n)
		{
			if (numtemp[i] < numtemp[j])
				num[k++] = numtemp[i++];
			else
				num[k++] = numtemp[j++];
		}
		while (i < l)
		{
			num[k++] = numtemp[i++];
		}
		while (j < n)
		{
			num[k++] = numtemp[j++];
		}
		delete[] numtemp;
	}
}

void mergeSort_1(int num[], int n)  //递归实现
{
	mSort(num, n);
}

void mergeSort_2(int num[], int n)  //迭代实现
{
	int gap = 1;
	int *numtemp = new int[n];
	int left, right, mid, max, k;
	
	do{
		gap *= 2;
		for (int i = 0; i < n-gap/2; i += gap)
		{
			left = i;
			mid = right = left + gap / 2;
			max = left + gap;
			if (max > n)max = n;
			k = 0;
			while (left < mid && right < max)
				if (num[left] < num[right])
					numtemp[k++] = num[left++];
				else
					numtemp[k++] = num[right++];
			while (left < mid)
				numtemp[k++] = num[left++];
			while (right < max)
				numtemp[k++] = num[right++];
			k = 0;
			for (left = i; left < max; left++)
				num[left] = numtemp[k++];
		}
	} while (gap <= n);
	delete[] numtemp;
}