/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:25:41 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:02 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_deque(t_all *all)
{
	all->deque_a = (t_deque *)malloc(sizeof(t_deque));
	all->deque_a->size = 0;
	all->deque_a->top = NULL;
	all->deque_a->bottom = NULL;
	all->deque_b = (t_deque *)malloc(sizeof(t_deque));
	all->deque_b->size = 0;
	all->deque_b->top = NULL;
	all->deque_b->bottom = NULL;
}

void	make_node(t_all *all, char *arr)
{
	t_node	*node;

	check_number(arr);
	check_dup(all, arr);
	node = (t_node *)malloc(sizeof(t_node));
	node->num = ft_atoi(arr);
	node->next = NULL;
	if (all->deque_a->top == NULL)
		all->deque_a->top = node;
	else
		all->deque_a->bottom->next = node;
	all->deque_a->bottom = node;
	all->deque_a->size++;
}

void	make_deque(int argc, char**argv, t_all *all)
{
	char	**arr;
	int		i;
	int		j;

	i = 1;
	while (argc-- > 1)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr[0] == NULL)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (arr[j] != NULL)
		{
			make_node(all, arr[j++]);
		}
		free_all(arr, j);
	}
}

void	check_number(char *arr)
{
	if (ft_atoi(arr) == NOT_NUM || ft_atoi(arr) == OUT_OF_RANGE)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_dup(t_all *all, char *arr)
{
	t_node	*temp;

	temp = all->deque_a->top;
	while (temp != NULL)
	{
		if (temp->num == ft_atoi(arr))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		temp = temp->next;
	}
}
