#include <stdio.h>

void insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		i++;
	}
}

int	main(void)
{
	int	arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	i;

	i = 0;
	insertion_sort(arr, 10);
	while (i < 10)
		printf("%d ", arr[i++]);
}