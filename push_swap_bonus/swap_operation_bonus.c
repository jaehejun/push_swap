/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:23:05 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/18 21:07:27 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_deque *deque_a)
{
	t_node	*temp;

	if (deque_a->size < 2)
		return ;
	temp = deque_a->top;
	deque_a->top = deque_a->top->next;
	temp->next = deque_a->top->next;
	deque_a->top->next = temp;
}

void	sb(t_deque *deque_b)
{
	t_node	*temp;

	if (deque_b->size < 2)
		return ;
	temp = deque_b->top;
	deque_b->top = deque_b->top->next;
	temp->next = deque_b->top->next;
	deque_b->top->next = temp;
}

void	ss(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*temp;

	if (deque_a->size < 2 || deque_b->size < 2)
		return ;
	temp = deque_a->top;
	deque_a->top = deque_a->top->next;
	temp->next = deque_a->top->next;
	deque_a->top->next = temp;
	temp = deque_b->top;
	deque_b->top = deque_b->top->next;
	temp->next = deque_b->top->next;
	deque_b->top->next = temp;
}
