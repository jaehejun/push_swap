/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/13 17:48:55 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	check_argc()
//	check_argv()
//	./push_swap 2 1 3 6 5 8
//	
//	./push_swap 0 one 2 3 -> ERROR
//
//	ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
//		6
//	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
//	OK

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc == 1)
		return (0);
	all = (t_all *)malloc(sizeof(t_all));
	init_stack(all);
	make_stack(argc, argv, all);
	indexing(all);
	if (all->stack_a->size <= 5)
		sort_five(all);
	else
		sort_stack(all);
	print(all);


}
void	print(t_all *all)
{
	printf("A_CNT : %d\n", all->stack_a->size);
	while (all->stack_a->top != NULL)
	{
		printf("%d\n", all->stack_a->top->num);
		all->stack_a->top = all->stack_a->top->next;
	}
	printf("-----------------aaaaaa-----------------\n");
	printf("B_CNT : %d\n", all->stack_b->size);
	while (all->stack_b->top != NULL)
	{
		printf("%d\n", all->stack_b->top->num);
		all->stack_b->top = all->stack_b->top->next;
	}
	printf("=================bbbbb=================\n");
}