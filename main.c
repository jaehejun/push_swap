/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/16 14:13:33 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc == 1)
		return (0);
	all = (t_all *)malloc(sizeof(t_all));
	init_stack(all);
	make_stack(argc, argv, all);
	indexing(all);
	if (is_sorted(all) == 1)
		return (0);
	else if (all->stack_a->size <= 6)
		sort_six(all);
	else
		sort_stack(all);
	print(all);


}
void	print(t_all *all)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = all->stack_a->top;
	temp_b = all->stack_b->top;
	printf("A_CNT : %lld\n", all->stack_a->size);
	while (temp_a != NULL)
	{
		printf("%lld\n", temp_a->num);
		temp_a = temp_a->next;
	}
	printf("-----------------aaaaaa-----------------\n");
	printf("B_CNT : %lld\n", all->stack_b->size);
	while (temp_b != NULL)
	{
		printf("%lld\n", temp_b->num);
		temp_b = temp_b->next;
	}
	printf("=================bbbbb=================\n");
}