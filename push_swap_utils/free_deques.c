/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deques.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:54:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/19 14:29:01 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_allocated(t_all *all)
{
	t_node	*temp;

	while (all->deque_a->size > 0)
	{
		temp = all->deque_a->top;
		while (temp->next != NULL)
			temp = temp->next;
		free(temp->next);
		temp->next = NULL;
		all->deque_a->size--;
	}
	free(all->deque_a);
	free(all->deque_b);
	free(all);
}
