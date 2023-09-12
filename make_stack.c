/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:25:41 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 20:16:45 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_all *all)
{
	all->stack_a = (t_stack *)malloc(sizeof(t_stack));
	all->stack_a->size = 0;
	all->stack_a->top = NULL;
	all->stack_a->bottom = NULL;
	all->stack_b = (t_stack *)malloc(sizeof(t_stack));
	all->stack_b->size = 0;
	all->stack_b->top = NULL;
	all->stack_b->bottom = NULL;
}

void	make_node(t_all *all, char *arr)
{
	t_node	*node;

	check_number(arr);
	check_dup(all, arr);
	node = (t_node *)malloc(sizeof(t_node));
	node->num = ft_atoi(arr);
	node->next = NULL;
	if (all->stack_a->top == NULL)
		all->stack_a->top = node;
	else
		all->stack_a->bottom->next = node;
	all->stack_a->bottom = node;
	all->stack_a->size++;
}

void	make_stack(int argc, char**argv, t_all *all)
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

	temp = all->stack_a->top;
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
