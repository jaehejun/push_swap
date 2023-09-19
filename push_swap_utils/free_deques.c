/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deques.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:54:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/19 20:26:27 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_allocated(t_all *all)
{
	t_node	*top;
	t_node	*temp;

	top = all->deque_a->top;
	while (top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
	free(all->deque_a);
	free(all->deque_b);
	free(all);
}
