/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:39:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 19:47:03 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	quick_sort(int *array, int low, int high);

int	main(void)
{
	int	n;
	int	i;
	int	array[1000000];

	scanf("%d", &n);
	i = 0;
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    srand((unsigned int)time(NULL));
	quick_sort(array, 0, n - 1);
	for (i = 0; i < n; i++)
        printf("%d\n", array[i]);
	return (0);
}

void	quick_sort(int *array, int low, int high)
{
	int	left;
	int	pivot;
    int temp;

	if (low >= high)
		return ;
	pivot = rand() % (high - low + 1) + low;
    temp = array[pivot];
    array[pivot] = array[high];
    array[high] = temp;
	pivot = high;
	high--;
	while (low <= high)
	{
		while (array[low] < array[pivot])
			low++;
		while (high > left && array[high] > array[pivot])
			high--;
		if (low < high)
        {
            temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }
		else
			break;
	}
    temp = array[low];
    array[low] = array[pivot];
    array[pivot] = temp;
	quick_sort(array, left, high);
	quick_sort(array, low + 1, pivot);
}
