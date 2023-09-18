/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deques_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:54:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 17:19:54 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_allocated(t_all *all)
{
	t_node	*temp;

	while (all->deque_a->size > 0)
	{
		temp = all->deque_a->top;
		while (temp->next != all->deque_a->bottom && temp->next != NULL)
			temp = temp->next;
		free(all->deque_a->bottom);
		all->deque_a->bottom = temp;
		temp->next = NULL;
		all->deque_a->size--;
	}
	free(all->deque_a);
	free(all->deque_b);
	free(all);
}
