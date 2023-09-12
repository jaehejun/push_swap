/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:22 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 18:54:34 by jaehejun         ###   ########.fr       */
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
	int	j = -1;
	while (++j < all->stack_a->size)
		printf("index[%d]: %d\n", j, indexing[j]);
}