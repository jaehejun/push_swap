/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opearation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:22:57 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:23 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_deque *deque_a)
{
	t_node	*temp;

	if (deque_a->size < 2)
		return ;
	temp = deque_a->top;
	deque_a->top = deque_a->top->next;
	deque_a->bottom->next = temp;
	deque_a->bottom = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_deque *deque_b)
{
	t_node	*temp;

	if (deque_b->size < 2)
		return ;
	temp = deque_b->top;
	deque_b->top = deque_b->top->next;
	deque_b->bottom->next = temp;
	deque_b->bottom = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*temp;

	if (deque_a->size < 2 || deque_b->size < 2)
		return ;
	temp = deque_a->top;
	deque_a->top = deque_a->top->next;
	deque_a->bottom->next = temp;
	deque_a->bottom = temp;
	temp->next = NULL;
	temp = deque_b->top;
	deque_b->top = deque_b->top->next;
	deque_b->bottom->next = temp;
	deque_b->bottom = temp;
	temp->next = NULL;
	write(1, "rr\n", 3);
}
