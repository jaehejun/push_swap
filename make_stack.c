/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:25:41 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/12 16:25:45 by jaehejun         ###   ########.fr       */
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
void	make_stack(int	argc, char**argv, t_all *all)
{
	char	**arr;
	int	i;
	int	j;
	t_node	*node;
	i = 1;
	while (argc-- > 1)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		int	idx = -1;
		while (arr[++idx] != NULL)
			printf("arr %d: %s\n", idx, arr[idx]);
		while (arr[j] != NULL)
		{
			node = (t_node *)malloc(sizeof(t_node));
			if (ft_atoi(arr[j]) == NOT_NUM || ft_atoi(arr[j]) == OUT_OF_RANGE)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			node->num = ft_atoi(arr[j++]);
			node->next = NULL;
			if (all->stack_a->top == NULL)
				all->stack_a->top = node;
			else
				all->stack_a->bottom->next = node;
			all->stack_a->bottom = node;
			all->stack_a->size++;
		}
		free_all(arr, j);
	}
}
