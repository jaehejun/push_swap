/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:23:03 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/16 22:16:23 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*temp;

	if (deque_b->size == 0)
		return ;
	temp = deque_b->top;
	deque_b->top = deque_b->top->next;
	if (deque_b->size == 1)
		deque_b->bottom = NULL;
	temp->next = deque_a->top;
	deque_a->top = temp;
	deque_a->size++;
	deque_b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*temp;

	if (deque_a->size == 0)
		return ;
	temp = deque_a->top;
	deque_a->top = deque_a->top->next;
	if (deque_b->top == NULL)
	{
		temp->next = NULL;
		deque_b->top = temp;
		deque_b->bottom = temp;
	}
	else
	{
		temp->next = deque_b->top;
		deque_b->top = temp;
	}
	deque_a->size--;
	deque_b->size++;
	write(1, "pb\n", 3);
}
