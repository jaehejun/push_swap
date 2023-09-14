/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/14 21:24:18 by jaehejun         ###   ########.fr       */
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
	//print(all);
	if (all->stack_a->size <= 6)
		sort_six(all);
	else
		sort_stack(all);
	//print(all);


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