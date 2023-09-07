/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opearation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:22:57 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/07 21:55:17 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bottom->next = temp;
	stack_a->bottom = temp;
	temp->next = NULL;
	printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;
	
	if (stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->bottom->next = temp;
	stack_b->bottom = temp;
	temp->next = NULL;
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	printf("A in\n");
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bottom->next = temp;
	stack_a->bottom = temp;
	temp->next = NULL;

	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->bottom->next = temp;
	stack_b->bottom = temp;
	temp->next = NULL;
	printf("rr\n");
}
