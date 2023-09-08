/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:22:53 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/08 15:48:49 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// node에 *prev를 추가하면 더 쉽게 구현할 수 있음.
#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;
	int		i;

	i = 0;
	if (stack_a->size < 2)
		return ;
	last = stack_a->bottom;
	last->next = stack_a->top;
	stack_a->top = last;
	while (i++ < stack_a->size - 1)
		last = last->next;
	stack_a->bottom = last;
	last->next = NULL;
	printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	int		i;

	i = 0;
	if (stack_b->size < 2)
		return ;
	last = stack_b->bottom;
	last->next = stack_b->top;
	stack_b->top = last;
	while (i++ < stack_b->size - 1)
		last = last->next;
	stack_b->bottom = last;
	last->next = NULL;
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last;
	int		i;

	i = 0;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	last = stack_a->bottom;
	last->next = stack_a->top;
	stack_a->top = last;
	while (i++ < stack_a->size - 1)
		last = last->next;
	stack_a->bottom = last;
	last->next = NULL;
	i = 0;
	last = stack_b->bottom;
	last->next = stack_b->top;
	stack_b->top = last;
	while (i++ < stack_b->size - 1)
		last = last->next;
	stack_b->bottom = last;
	last->next = NULL;
	printf("rrr\n");
}
