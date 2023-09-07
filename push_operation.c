/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:23:03 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/07 22:11:23 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->size == 0)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	stack_b->size--;
	printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->size == 0)
		return ;

	temp = stack_a->top;

	if (stack_b->top == NULL)
	{
		stack_a->top = stack_a->top->next;
		temp->next = NULL;
		stack_b->top = temp;
		stack_b->bottom = temp;
		stack_a->size--;
		stack_b->size++;
	}
	else
	{
		stack_a->top = stack_a->top->next;
		stack_b->top->next = stack_b->top;
		stack_b->top = temp;
		stack_a->size--;
		stack_b->size++;
	}
	printf("pb\n");
}

