/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/14 23:34:24 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_all *all)
{
	long long	b_index;
	long long	total_count;
	long long	a_mininum;
	long long	a_result_index;
	long long	b_result_index;
	t_node		*temp_b;

	push_to_b(all);
	while (all->stack_b->size > 0)
	{
		temp_b = all->stack_b->top;
		b_index = 0;
		total_count = NUM_MAX;
		while (temp_b != NULL)
		{
			a_mininum = find_a(all, temp_b->num);
			if (total_count > a_mininum + b_index)
			{
				total_count = a_mininum + b_index;
				b_result_index = b_index;
				a_result_index = a_mininum;
			}
			temp_b = temp_b->next;
			b_index++;
		}
		while (b_result_index-- > 0)
			rb(all->stack_b);
		while (a_result_index-- > 0)
			ra(all->stack_a);
		pa(all->stack_a, all->stack_b);
		
		//// ra -> rra
		//if (b_result_index > all->stack_b->size / 2)
		//	b_result_index = b_result_index - all->stack_b->size;

		//if (a_result_index > all->stack_a->size / 2)
		//	a_result_index = a_result_index - all->stack_a->size;

		//if (a_result_index < 0 && b_result_index < 0)
		//{
		//	if (a_result_index > b_result_index)
		//	{
		//		while (b_result_index++ - a_result_index > 0)
		//			rrb(all->stack_b);
		//		while (a_result_index++ < 0)
		//			rrr(all->stack_a, all->stack_b);
		//	}
		//	else
		//	{
		//		while (a_result_index++ - b_result_index > 0)
		//			rra(all->stack_a);
		//		while (b_result_index++ < 0)
		//			rrr(all->stack_a, all->stack_b);
		//	}
		//}
		//else if (a_result_index > 0 && b_result_index > 0)
		//{
		//	if (a_result_index > b_result_index)
		//	{
		//		while (a_result_index-- - b_result_index > 0)
		//			rra(all->stack_a);
		//		while (b_result_index-- > 0)
		//			rrr(all->stack_a, all->stack_b);
		//	}
		//}
		//else
		//{
		//	if (a_result_index < 0)
		//		while (a_result_index++ < 0)
		//			rra(all->stack_a);
		//	else
		//		while (a_result_index-- > 0)
		//			ra(all->stack_a);
		//	if (b_result_index < 0)
		//		while (b_result_index++ < 0)
		//			rrb(all->stack_b);
		//	else
		//		while (b_result_index-- > 0)
		//			rb(all->stack_b);
		//}
	
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
	long long	a_index;
	long long	result_index;
	long long	min;
	long long	diff;
	t_node		*temp_a;

	a_index = 0;
	result_index = 0;
	min = NUM_MAX;
	temp_a = all->stack_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (diff > 0 && min > diff)
		{
			min = diff;
			result_index = a_index;
		}
		temp_a = temp_a->next;
		a_index++;
	}
	if (min == NUM_MAX && is_sorted(all) == 0)
		result_index = find_a_with_biggest_b(all, b_num);
	return (result_index);
}

long long	find_a_with_biggest_b(t_all *all, long long b_num)
{
	long long	a_index;
	long long	result_index;
	long long	min;
	long long	diff;
	t_node		*temp_a;

	a_index = 0;
	result_index = 0;
	min = NUM_MAX;
	temp_a = all->stack_a->top;
	while (temp_a != NULL)
	{
		diff = temp_a->num - b_num;
		if (min > diff)
		{
			min = diff;
			result_index = a_index;
		}
		temp_a = temp_a->next;
		a_index++;
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
