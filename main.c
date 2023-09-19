/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/19 20:31:53 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc == 1)
		return (0);
	all = (t_all *)malloc(sizeof(t_all));
	init_deque(all);
	make_deque(argc, argv, all);
	indexing(all);
	if (is_sorted(all) == 1)
	{
		free_allocated(all);
		return (0);
	}
	else if (all->deque_a->size <= 6)
		sort_small(all);
	else
		sort_big(all);
	zero_to_top(all);
	free_allocated(all);
	return (0);
}
