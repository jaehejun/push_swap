/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:31:51 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/18 20:58:46 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_allocated(t_all *all)
{
	t_node	*temp;

	while (all->deque_a->size > 0)
	{
		temp = all->deque_a->top;
		while (temp->next != all->deque_a->bottom && temp->next != NULL)
			temp = temp->next;
		free(all->deque_a->bottom);
		all->deque_a->bottom = temp;
		temp->next = NULL;
		all->deque_a->size--;
	}
	free(all->deque_a);
	free(all->deque_b);
	free(all);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\n')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
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

