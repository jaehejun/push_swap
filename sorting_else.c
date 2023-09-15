/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:32 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/15 20:41:56 by jaehejun         ###   ########.fr       */
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
			if (b_index > all->stack_b->size / 2)
				b_index = (all->stack_b->size - b_index) * -1;
			if (total_count > change_to_abs(a_mininum) + change_to_abs(b_index))
			{
				total_count = change_to_abs(a_mininum) + change_to_abs(b_index);
				b_result_index = b_index;
				a_result_index = a_mininum;
			}
			temp_b = temp_b->next;
			b_index++;
		}
		printf("A_RESULT : %lld\n", a_result_index);
		printf("B_RESULT : %lld\n", b_result_index);

		if (a_result_index >= 0 && b_result_index >= 0)
		{
			if (a_result_index > b_result_index)
			{
				while (b_result_index-- > 0)
				{
					rr(all->stack_a, all->stack_b);
					a_result_index--;
				}
				while (a_result_index-- > 0)
					ra(all->stack_a);
			}
			else
			{
				while (a_result_index-- > 0)
				{
					rr(all->stack_a, all->stack_b);
					b_result_index--;
				}
				while (b_result_index-- > 0)
					rb(all->stack_b);
			}
		}
		else if (a_result_index < 0 && b_result_index < 0)
		{
			if (a_result_index > b_result_index)
			{
				while (a_result_index++ < 0)
				{
					rrr(all->stack_a, all->stack_b);
					b_result_index++;
				}
				while (b_result_index++ < 0)
					rrb(all->stack_b);
			}
		}
		else
		{
			if (a_result_index >= 0)
				while (a_result_index-- > 0)
					ra(all->stack_a);
			else
				while (a_result_index++ < 0)
					rra(all->stack_a);
			if (b_result_index >= 0)
				while (b_result_index-- > 0)
					rb(all->stack_b);
			else
				while (b_result_index++ < 0)
					rrb(all->stack_b);
		}

		
		//while (b_result_index-- > 0)
		//	rb(all->stack_b);
		//while (a_result_index-- > 0)
		//	ra(all->stack_a);
		pa(all->stack_a, all->stack_b);
		print(all);
		
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
	result_index = reverse_index(all, result_index);
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

long long	reverse_index(t_all *all, long long result_index)
{
	if (result_index > all->stack_a->size / 2)
		result_index = (all->stack_a->size - result_index) * -1;
	return (result_index);
}

long long	change_to_abs(long long num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}