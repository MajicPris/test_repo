int binarySearch(int *array, int left, int right, int key)
{
	int mid = 0;
	while (1) {
		mid = (left + right) / 2;
		if (key > array[mid])
			left = mid + 1;
		else if (key < array[mid])
			right = mid - 1;
		else
			return mid;

		if (right > left)
			return -1;
	}
}