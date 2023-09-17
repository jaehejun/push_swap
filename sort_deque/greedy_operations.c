/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:33:47 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 16:34:19 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operate_greedy(t_all *all, long long a_count, long long b_count)
{
	if (a_count >= 0 && b_count >= 0)
		greedy_r(all, a_count, b_count);
	else if (a_count < 0 && b_count < 0)
		greedy_rr(all, a_count, b_count);
	else
		greedy_seperately(all, a_count, b_count);
	pa(all->deque_a, all->deque_b);
}

void	greedy_r(t_all *all, long long a_count, long long b_count)
{
	if (a_count > b_count)
	{
		while (b_count-- > 0)
		{
			rr(all->deque_a, all->deque_b);
			a_count--;
		}
		while (a_count-- > 0)
			ra(all->deque_a);
	}
	else
	{
		while (a_count-- > 0)
		{
			rr(all->deque_a, all->deque_b);
			b_count--;
		}
		while (b_count-- > 0)
			rb(all->deque_b);
	}
}

void	greedy_rr(t_all *all, long long a_count, long long b_count)
{
	if (a_count > b_count)
	{
		while (a_count++ < 0)
		{
			rrr(all->deque_a, all->deque_b);
			b_count++;
		}
		while (b_count++ < 0)
			rrb(all->deque_b);
	}
	else
	{
		while (b_count++ < 0)
		{
			rrr(all->deque_a, all->deque_b);
			a_count++;
		}
		while (a_count++ < 0)
			rra(all->deque_a);
	}
}

void	greedy_seperately(t_all *all, long long a_count, long long b_count)
{
	if (a_count >= 0)
		while (a_count-- > 0)
			ra(all->deque_a);
	else
		while (a_count++ < 0)
			rra(all->deque_a);
	if (b_count >= 0)
		while (b_count-- > 0)
			rb(all->deque_b);
	else
		while (b_count++ < 0)
			rrb(all->deque_b);
}
