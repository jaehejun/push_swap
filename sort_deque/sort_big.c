/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 16:57:43 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big(t_all *all)
{
	long long	sum;
	long long	a_idx;
	long long	a_count;
	long long	b_count;
	t_node		*temp;

	push_to_b(all);
	while (all->deque_b->size > 0)
	{
		temp = all->deque_b->top;
		put_index(all);
		sum = NUM_MAX;
		while (temp != NULL)
		{
			a_idx = find_a(all, temp->num);
			if (sum > ft_abs(a_idx) + ft_abs(tr_idx(all->deque_b, temp->idx)))
			{
				sum = ft_abs(a_idx) + ft_abs(tr_idx(all->deque_b, temp->idx));
				b_count = tr_idx(all->deque_b, temp->idx);
				a_count = a_idx;
			}
			temp = temp->next;
		}
		operate_greedy(all, a_count, b_count);
	}
}

void	push_to_b(t_all *all)
{
	long long	pivot_small;
	long long	pivot_big;
	long long	count;

	pivot_small = all->deque_a->size / 3;
	pivot_big = pivot_small * 2;
	count = all->deque_a->size;
	while (count-- > 0)
	{
		if (all->deque_a->top->num < pivot_big)
		{
			pb(all->deque_a, all->deque_b);
			if (all->deque_b->top->num < pivot_small)
				rb(all->deque_b);
		}
		else
			ra(all->deque_a);
	}
	while (all->deque_a->size > 3)
		pb(all->deque_a, all->deque_b);
	sort_three(all);
}

void	put_index(t_all *all)
{
	t_node		*temp_a;
	t_node		*temp_b;
	long long	index;

	temp_a = all->deque_a->top;
	temp_b = all->deque_b->top;
	index = 0;
	while (temp_a != NULL)
	{
		temp_a->idx = index++;
		temp_a = temp_a->next;
	}
	index = 0;
	while (temp_b != NULL)
	{
		temp_b->idx = index++;
		temp_b = temp_b->next;
	}
}

long long	find_a(t_all *all, long long b_num)
{
	long long	result_index;
	long long	min;
	long long	diff;
	t_node		*temp_a;

	result_index = 0;
	min = NUM_MAX;
	temp_a = all->deque_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (min > ft_abs(diff))
		{
			min = ft_abs(diff);
			if (diff < 0)
				result_index = temp_a->idx + 1;
			else
				result_index = temp_a->idx;
		}
		temp_a = temp_a->next;
	}
	result_index = tr_idx(all->deque_a, result_index);
	return (result_index);
}

void	zero_to_top(t_all *all)
{
	t_node		*temp;
	long long	index;

	temp = all->deque_a->top;
	index = 0;
	while (temp->num != 0)
	{
		temp = temp->next;
		index++;
	}
	index = tr_idx(all->deque_a, index);
	if (index > 0)
		while (index-- > 0)
			ra(all->deque_a);
	else
		while (index++ < 0)
			rra(all->deque_a);
}
