/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:22:53 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/16 22:16:38 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *deque_a)
{
	t_node	*last;
	int		i;

	i = 0;
	if (deque_a->size < 2)
		return ;
	last = deque_a->bottom;
	last->next = deque_a->top;
	deque_a->top = last;
	while (i++ < deque_a->size - 1)
		last = last->next;
	deque_a->bottom = last;
	last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_deque *deque_b)
{
	t_node	*last;
	int		i;

	i = 0;
	if (deque_b->size < 2)
		return ;
	last = deque_b->bottom;
	last->next = deque_b->top;
	deque_b->top = last;
	while (i++ < deque_b->size - 1)
		last = last->next;
	deque_b->bottom = last;
	last->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*last;
	int		i;

	i = 0;
	if (deque_a->size < 2 || deque_b->size < 2)
		return ;
	last = deque_a->bottom;
	last->next = deque_a->top;
	deque_a->top = last;
	while (i++ < deque_a->size - 1)
		last = last->next;
	deque_a->bottom = last;
	last->next = NULL;
	i = 0;
	last = deque_b->bottom;
	last->next = deque_b->top;
	deque_b->top = last;
	while (i++ < deque_b->size - 1)
		last = last->next;
	deque_b->bottom = last;
	last->next = NULL;
	write(1, "rrr\n", 4);
}
