/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:19:26 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/19 20:31:09 by jaehejun         ###   ########.fr       */
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
	free_allocated(all);
	return (0);
}

void	check_line(char *line, t_all *all)
{
	if (ft_strcmp(line, "sa\n"))
		sa(all->deque_a);
	else if (ft_strcmp(line, "sb\n"))
		sb(all->deque_b);
	else if (ft_strcmp(line, "ss\n"))
		ss(all->deque_a, all->deque_b);
	else if (ft_strcmp(line, "pa\n"))
		pa(all->deque_a, all->deque_b);
	else if (ft_strcmp(line, "pb\n"))
		pb(all->deque_a, all->deque_b);
	else if (ft_strcmp(line, "ra\n"))
		ra(all->deque_a);
	else if (ft_strcmp(line, "rb\n"))
		rb(all->deque_b);
	else if (ft_strcmp(line, "rr\n"))
		rr(all->deque_a, all->deque_b);
	else if (ft_strcmp(line, "rra\n"))
		rra(all->deque_a);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(all->deque_b);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(all->deque_a, all->deque_b);
	else
		print_error();
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
