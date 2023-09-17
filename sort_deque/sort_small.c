/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:33 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 12:41:16 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small(t_all *all)
{
	int	minimum;

	minimum = -1;
	if (all->deque_a->size <= 2)
	{
		if (all->deque_a->top->num != 0)
			sa(all->deque_a);
	}
	else
	{
		while (all->deque_a->size > 3)
			push_min(all, ++minimum);
		sort_three(all);
		while (all->deque_b->size > 0)
			pa(all->deque_a, all->deque_b);
	}
}

void	push_min(t_all *all, int minimum)
{
	t_node	*temp;
	int		index;

	temp = all->deque_a->top;
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
			ra(all->deque_a);
	else
		while (index++ < all->deque_a->size)
			rra(all->deque_a);
	pb(all->deque_a, all->deque_b);
}

void	sort_three(t_all *all)
{
	t_node	*temp;

	temp = all->deque_a->top;
	if (temp->num < temp->next->num && temp->next->num > temp->next->next->num)
		rra(all->deque_a);
	if (temp->num > temp->next->num && temp->num > temp->next->next->num)
		ra(all->deque_a);
	temp = all->deque_a->top;
	if (temp->num < temp->next->num && temp->next->num < temp->next->next->num)
		return ;
	sa(all->deque_a);
}
