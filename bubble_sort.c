#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int arr[], int n)
{
	int	i;

	while (n > 1)
	{
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
			i++;
		}
		n--;
	}
}

int	main(void)
{
	int	arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	i;

	i = 0;
	bubble_sort(arr, 10);
	while (i < 10)
		printf("%d ", arr[i++]);
	return (0);
}
