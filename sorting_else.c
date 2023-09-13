/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/13 22:32:01 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	sort_stack(t_all *all)
//{
//	long long	diff;
//	int	count;
//	t_node	*temp_b;
//	t_node	*temp_a;
	
//	temp_a = all->stack_a->top;
//	temp_b = all->stack_b->top;
//	push_to_b(all);
//	while (temp_a != NULL)
//	{
//		diff = temp_a->num - all->stack_b->top->num;
//	}
	
//}
void	push_to_b(t_all *all)
{
	int	pivot_small;
	int	pivot_big;
	int	count;

	pivot_small = all->stack_a->size / 3;
	pivot_big = pivot_small * 2;
	count = all->stack_a->size;
	while (count-- > 0)
	{
		if (all->stack_a->top->num < pivot_big)
		{
			pb(all->stack_a, all->stack_b);
			if (all->stack_b->top->num >= pivot_small)
				rb(all->stack_b);
		}
		else
			ra(all->stack_a);
	}
	pb(all->stack_a, all->stack_b);
	pb(all->stack_a, all->stack_b);
	sort_three(all);
}


