/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:33 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/14 20:42:36 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_six(t_all *all)
{
	int	minimum;

	minimum = -1;
	if (all->stack_a->size <= 2)
	{
		if (all->stack_a->top->num != 0)
			sa(all->stack_a);
	}
	else
	{
		while (all->stack_a->size > 3)
			push_min(all, ++minimum);
		sort_three(all);
		while (all->stack_b->size > 0)
			pa(all->stack_a, all->stack_b);
	}
}

void	push_min(t_all *all, int minimum)
{
	t_node	*temp;
	int		index;

	temp = all->stack_a->top;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->num == minimum)
			break ;
		index++;
		temp = temp->next;
	}
	if (index < 3)
		while (index-- > 0)
			ra(all->stack_a);
	else
		while (index++ < all->stack_a->size)
			rra(all->stack_a);
	pb(all->stack_a, all->stack_b);
}

void	sort_three(t_all *all)
{
	t_node	*temp;
	
	temp = all->stack_a->top;
	if (temp->num < temp->next->num && temp->next->num > temp->next->next->num)
		rra(all->stack_a);
	if (temp->num > temp->next->num && temp->num > temp->next->next->num)
		ra(all->stack_a);
	temp = all->stack_a->top;
	if (temp->num < temp->next->num && temp->next->num < temp->next->next->num)
		return ;
	sa(all->stack_a);
}
