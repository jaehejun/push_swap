/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/06 22:44:45 by jaehejun         ###   ########.fr       */
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
//int	main(int argc, char **argv)
//{
//	int	i;
//	char	**str;

//	i = 1;
//	printf("ARGC : %d\n", argc);
//	if (argc == 2)
//	{
//		while (argc-- > 1)
//		{
//			str = ft_split(argv[i++], ' ');
//		}
//		i = 0;
//		while (str[i] != NULL)
//			printf("%s\n", str[i++]);
//	}
//	else
//	{
//		i = 1;
//		while (argc-- > 1)
//			printf("%s\n", argv[i++]);
//	}
//}

//int	main(void)
//{
//	printf("sa\nsa\n");
//}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_a->size = 0;
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;

	if (argc == 2)
	{}
	argv[1] = "0 1 2 3 4"
	argv[2] = 5
	argv[3] = "6 7 8"
	argv[4] = 9

	char *arr = (char *)malloc(sizeof(char) * ft_strlen(argv[1] + 1));
	while (i < ft_strlen(argv[1]))
	{
		arr[i] = argv[1][i];
		i++;
	}
	arr[i] = ' ';
	
	while (i < argc)
	{
		char *arr = ft_strjoin(arr, argv[i]);
	}
	i = 1;
	while (i < argc)
	{
		char **str = ft_split(argv[i], ' ');
		i++;
		while (str++ != NULL)
		{
			char *arr++ = str[i++];
		}
		char *arr = 
	}
	char **str = ft_split(argv[1], ' ');




	//put argv into stack_a in put_order
	i = 1;
	while (argc-- > 1)
	{
		node = (t_node *)malloc(sizeof(t_node));
		node->num = ft_atoi(argv[i++]);
		node->next = NULL;
		if (stack_a->top == NULL)
		{
			stack_a->top = node;
			stack_a->bottom = node;
		}
		else
		{
			stack_a->bottom = stack_a->bottom->next = node;
		}
		stack_a->size++;
	}
	while (stack_a->top != NULL)
	{
		printf("%d\n", stack_a->top->num);
		stack_a->top = stack_a->top->next;
	}
	printf("STACK_A size : %d\n", stack_a->size);
}
