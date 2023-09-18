/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:19:26 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/18 21:12:03 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_all	*all;

	if (argc == 1)
		return (0);
	all = (t_all *)malloc(sizeof(t_all));
	init_deque(all);
	make_deque(argc, argv, all);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		check_line(line, all);
		free(line);
	}
	if (is_sorted(all) == 1 && all->deque_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

void	check_line(char *line, t_all *all)
{
		if (ft_strcmp(line, "sa"))
			sa(all->deque_a);
		else if (ft_strcmp(line, "sb"))
			sb(all->deque_b);
		else if (ft_strcmp(line, "pa"))
			pa(all->deque_a, all->deque_b);
		else if (ft_strcmp(line, "pb"))
			pb(all->deque_a, all->deque_b);
		else if (ft_strcmp(line, "ra"))
			ra(all->deque_a);
		else if (ft_strcmp(line, "rb"))
			rb(all->deque_b);
		else if (ft_strcmp(line, "rr"))
			rr(all->deque_a, all->deque_b);
		else if (ft_strcmp(line, "rra"))
			rra(all->deque_a);
		else if (ft_strcmp(line, "rrb"))
			rrb(all->deque_b);
		else if (ft_strcmp(line, "rrr"))
			rrr(all->deque_a, all->deque_b);
		else
		{
			write(2, "Error\n", 6);
			exit (1);
		}
}
