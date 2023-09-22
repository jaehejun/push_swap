/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:25:41 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/21 18:44:30 by jaehejun         ###   ########.fr       */
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

void	make_node(t_all *all, char *arr)
{
	t_node			*node;
	long long		number;

	number = check_number(arr);
	check_dup(all, number);
	node = (t_node *)malloc(sizeof(t_node));
	node->num = number;
	node->next = NULL;
	if (all->deque_a->top == NULL)
		all->deque_a->top = node;
	else
		all->deque_a->bottom->next = node;
	all->deque_a->bottom = node;
	all->deque_a->size++;
}

long long	check_number(char *arr)
{
	long long	result;

	result = ft_atoi(arr);
	if (result == NOT_NUM || result == OUT_OF_RANGE)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (result);
}

void	check_dup(t_all *all, long long number)
{
	t_node	*temp;

	temp = all->deque_a->top;
	while (temp != NULL)
	{
		if (temp->num == number)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		temp = temp->next;
	}
}
