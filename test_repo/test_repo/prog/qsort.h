int arr[40];
void qsort(int a, int b)
{
	int l = a, r = b;
	int mid = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < mid)
			l++;
		while (arr[r] > mid)
			r--;
		if (l <= r)
			swap(arr[l++], arr[r--]);
	}

	if (a < r)
		qsort(a, r);
	if (b > l)
		qsort(l, b);
}