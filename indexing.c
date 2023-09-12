/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:22 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 20:24:07 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_all *all)
{
	int		*indexing;
	int		i;
	t_node	*temp;

	i = 0;
	temp = all->stack_a->top;
	indexing = (int *)malloc(sizeof(int) * all->stack_a->size);
	while (temp != NULL)
	{
		indexing[i++] = temp->num;
		temp = temp->next;
	}
	quick_sort(indexing, 0, all->stack_a->size - 1);
	numbering(indexing, all);
	free(indexing);
}

void	numbering(int *indexing, t_all *all)
{
	t_node	*temp;
	int		i;

	temp = all->stack_a->top;
	while (temp != NULL)
	{
		i = 0;
		while (i < all->stack_a->size)
		{
			if (temp->num == indexing[i])
			{
				temp->num = i;
				temp = temp->next;
				break ;
			}
			i++;
		}
	}
}

void	quick_sort(int *array, int low, int high)
{
	int	left;
	int	pivot;

	left = 0;
	if (low >= high)
		return ;
	pivot = high;
	high--;
	while (low <= high)
	{
		while (array[low] < array[pivot])
			low++;
		while (high > left && array[high] > array[pivot])
			high--;
		if (low < high)
			swap(&array[low], &array[high]);
		else
			break ;
	}
	swap(&array[low], &array[pivot]);
	quick_sort(array, left, high);
	quick_sort(array, low + 1, pivot);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
