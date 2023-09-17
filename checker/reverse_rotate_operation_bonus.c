/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:22:53 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 17:20:18 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_deque *deque_a)
{
	t_node	*temp;
	int		i;

	i = 0;
	if (deque_a->size < 2)
		return ;
	temp = deque_a->bottom;
	temp->next = deque_a->top;
	deque_a->top = temp;
	while (i++ < deque_a->size - 1)
		temp = temp->next;
	deque_a->bottom = temp;
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_deque *deque_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	if (deque_b->size < 2)
		return ;
	temp = deque_b->bottom;
	temp->next = deque_b->top;
	deque_b->top = temp;
	while (i++ < deque_b->size - 1)
		temp = temp->next;
	deque_b->bottom = temp;
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	if (deque_a->size < 2 || deque_b->size < 2)
		return ;
	temp = deque_a->bottom;
	temp->next = deque_a->top;
	deque_a->top = temp;
	while (i++ < deque_a->size - 1)
		temp = temp->next;
	deque_a->bottom = temp;
	temp->next = NULL;
	i = 0;
	temp = deque_b->bottom;
	temp->next = deque_b->top;
	deque_b->top = temp;
	while (i++ < deque_b->size - 1)
		temp = temp->next;
	deque_b->bottom = temp;
	temp->next = NULL;
	write(1, "rrr\n", 4);
}
