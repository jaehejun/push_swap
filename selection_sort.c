#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selection_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[min] > arr[j])
				min = j;
			j++;
		}
		if (min != i)
			swap(&arr[min], &arr[i]);
		i++;
	}
}

int	main(void)
{
	int	arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	i;

	i = 0;
	selection_sort(arr, 10);
	while (i < 10)
		printf("%d ", arr[i++]);
}
