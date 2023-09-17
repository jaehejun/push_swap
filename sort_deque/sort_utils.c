/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:36:33 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 16:53:28 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	tr_idx(t_deque *deque, long long result_index)
{
	if (result_index > deque->size / 2)
		result_index = (deque->size - result_index) * -1;
	return (result_index);
}

long long	ft_abs(long long num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	is_sorted(t_all *all)
{
	t_node	*temp;

	temp = all->deque_a->top;
	while (temp->next != NULL)
	{
		if (temp->num < temp->next->num)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
