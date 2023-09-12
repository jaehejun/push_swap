/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:33 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 22:22:21 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_stack(t_all *all)
{
	t_node	*temp;

	temp = all->stack_a->top;
	while (all->stack_a->size > 3)
	{
		pb(all->stack_a, all->stack_b);
	}
	sorting_three(all);
}

//void	sorting_three(t_all *all)
//{
//	t_node	*temp;

//	temp = all->stack_a->top;
//	if (temp->num > temp->next->num && temp->next->num < temp->next->next->num)
//	{
//		sa(all->stack_a);
//		rra(all->stack_a);
//	}
//	else if (temp->num > temp->next->num && temp->next->num > temp->next->next->num)
//		sa(all->stack_a);
//	else if (temp->num < temp->next->num && temp->next->num > temp->next->next->num)
//	{
//		sa(all->stack_a);
//		ra(all->stack_a);
//	}
//	else if (temp->num > temp->next->num && temp->next->num < temp->next->next->num)
//		rra(all->stack_a);
//	else if (temp->num < temp->next->num && temp->next->num > temp->next->next->num)
//		ra(all->stack_a);
//}
void	sorting_three(t_all *all)
{
	t_node	*temp;
	
	temp = all->stack_a->top;
	//021->102, 120->012
	if (temp->num < temp->next->num && temp->next->num > temp->next->next->num)
	{
		rra(all->stack_a);
	}
	//201->012, 210->102
	if (temp->num > temp->next->num && temp->num > temp->next->next->num)
	{
		ra(all->stack_a);
	}
	//012
	temp = all->stack_a->top;
	if (temp->num < temp->next->num && temp->next->num < temp->next->next->num)
	{
		return ;
	}
	//213->123
	//if (temp->num > temp->next->num && temp->num < temp->next->next->num)
	sa(all->stack_a);
	//231
	//else if (temp->num < temp->next->num && temp->num > temp->next->next->num)
	//	rra(all->stack_a);
	////312
	//else if (temp->num > temp->next->num && temp->num > temp->next->next->num)
	//	ra(all->stack_a);
	//123
}
