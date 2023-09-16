/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/16 14:24:53 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_all *all)
{
	long long	total_count;
	long long	greedy_a;
	long long	a_count;
	long long	b_count;
	t_node		*temp_b;

	push_to_b(all);
	print(all);
	while (all->stack_b->size > 0)
	{
		temp_b = all->stack_b->top;
		put_index(all);
		total_count = NUM_MAX;
		while (temp_b != NULL)
		{
			greedy_a = find_a(all, temp_b->num);
			if (total_count > ft_abs(greedy_a) + ft_abs(greedy_index(all, temp_b->index)))
			{
				total_count = ft_abs(greedy_a) + ft_abs(greedy_index(all, temp_b->index));
				b_count = greedy_index(all, temp_b->index);
				a_count = greedy_a;
			}
			temp_b = temp_b->next;
		}
		printf("A_RESULT : %lld\n", a_count);
		printf("B_RESULT : %lld\n", b_count);

		if (a_count >= 0 && b_count >= 0)
		{
			if (a_count > b_count)
			{
				while (b_count-- > 0)
				{
					rr(all->stack_a, all->stack_b);
					a_count--;
				}
				while (a_count-- > 0)
					ra(all->stack_a);
			}
			else
			{
				while (a_count-- > 0)
				{
					rr(all->stack_a, all->stack_b);
					b_count--;
				}
				while (b_count-- > 0)
					rb(all->stack_b);
			}
		}
		else if (a_count < 0 && b_count < 0)
		{
			if (a_count > b_count)
			{
				while (a_count++ < 0)
				{
					rrr(all->stack_a, all->stack_b);
					b_count++;
				}
				while (b_count++ < 0)
					rrb(all->stack_b);
			}
		}
		else
		{
			if (a_count >= 0)
				while (a_count-- > 0)
					ra(all->stack_a);
			else
				while (a_count++ < 0)
					rra(all->stack_a);
			if (b_count >= 0)
				while (b_count-- > 0)
					rb(all->stack_b);
			else
				while (b_count++ < 0)
					rrb(all->stack_b);
		}

		
		pa(all->stack_a, all->stack_b);
		print(all);
	}
	while (all->stack_a->top->num != 0)
		ra(all->stack_a);
}
	

void	push_to_b(t_all *all)
{
	long long	pivot_small;
	long long	pivot_big;
	long long	count;

	pivot_small = all->stack_a->size / 3;
	pivot_big = pivot_small * 2;
	count = all->stack_a->size;
	while (count-- > 0)
	{
		if (all->stack_a->top->num < pivot_big)
		{
			pb(all->stack_a, all->stack_b);
			if (all->stack_b->top->num < pivot_small)
				rb(all->stack_b);
		}
		else
			ra(all->stack_a);
	}
	while (all->stack_a->size > 3)
		pb(all->stack_a, all->stack_b);
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
	temp_a = all->stack_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (min > ft_abs(diff))
		{
			min = diff;
			result_index = temp_a->index;
		}
		temp_a = temp_a->next;
	}
	if (min == NUM_MAX && is_sorted(all) == 0)
		result_index = find_a_with_biggest_b(all, b_num);
	result_index = greedy_index(all, result_index);
	return (result_index);
}

long long	find_a_with_biggest_b(t_all *all, long long b_num)
{
	long long	result_index;
	long long	min;
	long long	diff;
	t_node		*temp_a;

	result_index = 0;
	min = NUM_MAX;
	temp_a = all->stack_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (min > diff)
		{
			min = diff;
			result_index = temp_a->index;
		}
		temp_a = temp_a->next;
	}
	return (result_index);
}

int	is_sorted(t_all *all)
{
	t_node	*temp;

	temp = all->stack_a->top;
	while (temp->next != NULL)
	{
		if (temp->num < temp->next->num)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

long long	greedy_index(t_all *all, long long result_index)
{
	if (result_index > all->stack_a->size / 2)
		result_index = (all->stack_a->size - result_index) * -1;
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

	temp_a = all->stack_a->top;
	temp_b = all->stack_b->top;
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