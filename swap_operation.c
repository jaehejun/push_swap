/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:23:05 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/07 20:39:03 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first 2 elements at the top of stack
void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size < 2)
		return ;
	temp = (t_node *)malloc(sizeof(t_node));
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_a->top->next;
	stack_a->top->next = temp;
	free(temp);
	
	//int	temp;

	//if (stack_a->size < 2)
	//	return ;
	//temp = stack_a->top->num;
	//stack_a->top->num = stack_a->top->next->num;
	//stack_a->top->next->num = temp;
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_b->top->next;
	stack_b->top->next = temp;

	//int	temp;

	//if (stack_b->size < 2)
	//	return ;
	//temp = stack_b->top->num;
	//stack_b->top->num = stack_b->top->next->num;
	//stack_b->top->next->num = temp;
	printf("sb\n");
}

//swap the first 2 elements at the top of stack a and b
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
//sa()
//sb()
//ss() : sa + sb