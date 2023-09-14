/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/14 21:23:36 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_all *all)
{
	long long	b_count;
	long long	total_count;
	long long	a_index;
	long long	a_result;
	long long	b_index;
	t_node		*temp_b;

	push_to_b(all);
	//print(all);
	while (all->stack_b->size > 0)
	{
		temp_b = all->stack_b->top;
		b_count = 0;
		total_count = NUM_MAX;
		while (temp_b != NULL)
		{
			a_index = find_a(all, temp_b->num);
			if (total_count > a_index + b_count)
			{
				total_count = a_index + b_count;
				b_index = b_count;
				a_result = a_index;
			}
			temp_b = temp_b->next;
			b_count++;
		}
		while (b_index-- > 0)
			rb(all->stack_b);
		while (a_result-- > 0)
			ra(all->stack_a);
		pa(all->stack_a, all->stack_b);
		//print(all);
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
	long long	a_count;
	long long	a_index;
	long long	min;
	long long	max;
	long long	diff;
	t_node		*temp_a;

	a_count = 0;
	a_index = 0;
	min = NUM_MAX;
	max = 0;
	temp_a = all->stack_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (diff > 0 && min > diff)
		{
			min = diff;
			a_index = a_count;
		}
		temp_a = temp_a->next;
		a_count++;
	}
	if (min == NUM_MAX)
	{
		if (is_sorted(all) == 1)
			return (0);
		else
		{
			a_count = 0;
			temp_a = all->stack_a->top;
			while (temp_a != NULL)
			{
				diff = b_num - temp_a->num;
				if (max < diff)
				{
					max = diff;
					a_index = a_count;
				}
				temp_a = temp_a->next;
				a_count++;
			}
		}
	}
	return (a_index);
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
