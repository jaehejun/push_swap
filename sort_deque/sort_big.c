/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 12:54:46 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big(t_all *all)
{
	long long	sum;
	long long	greedy_a;
	long long	a_count;
	long long	b_count;
	t_node		*temp_b;

	push_to_b(all);
	while (all->deque_b->size > 0)
	{
		temp_b = all->deque_b->top;
		put_index(all);
		sum = NUM_MAX;
		while (temp_b != NULL)
		{
			greedy_a = find_a(all, temp_b->num);
			if (sum > ft_abs(greedy_a) + ft_abs(greedy_index(all->deque_b->size, temp_b->index)))
			{
				sum = ft_abs(greedy_a) + ft_abs(greedy_index(all->deque_b->size, temp_b->index));
				b_count = greedy_index(all->deque_b->size, temp_b->index);
				a_count = greedy_a;
			}
			temp_b = temp_b->next;
		}
		if (a_count >= 0 && b_count >= 0)
			greedy_r(all, a_count, b_count);
		else if (a_count < 0 && b_count < 0)
			greedy_rr(all, a_count, b_count);
		else
			greedy_seperately(all, a_count, b_count);
		pa(all->deque_a, all->deque_b);
	}
	zero_to_top(all);
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
				result_index = temp_a->index + 1;
			else
				result_index = temp_a->index;
		}
		temp_a = temp_a->next;
	}
	result_index = greedy_index(all->deque_a->size, result_index);
	return (result_index);
}

long long	greedy_index(long long size, long long result_index)
{
	if (result_index > size / 2)
		result_index = (size - result_index) * -1;
	return (result_index);
}

long long	ft_abs(long long num)
{
	if (num < 0)
		return (num * -1);
	return (num);
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
		temp_a->index = index++;
		temp_a = temp_a->next;
	}
	index = 0;
	while (temp_b != NULL)
	{
		temp_b->index = index++;
		temp_b = temp_b->next;
	}
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
	index = greedy_index(all->deque_a->size, index);
	if (index > 0)
		while (index-- > 0)
			ra(all->deque_a);
	else
		while (index++ < 0)
			rra(all->deque_a);
}
