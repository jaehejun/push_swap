/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/08 15:50:29 by jaehejun         ###   ########.fr       */
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
	if (argc == 1)
		return (0);
	int		i;
	int		j;
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

	i = 1;
	while (argc-- > 1)
	{
		j = 0;
		char **arr = ft_split(argv[i++], ' ');
		while (arr[j] != NULL)
		{
			//if (arr[j] == invalid number || out of range || duplicate number)
			//{
			//	free_all(arr, j);
			//	free(stack_a->top ~ bottom);
			//	free(stack_a);
			//	free(stack_b);
			//	printf("Error\n");
			//	return (0);
			//}
			node = (t_node *)malloc(sizeof(t_node));
			node->num = ft_atoi(arr[j++]);
			node->next = NULL;
			if (stack_a->top == NULL)
				stack_a->top = node;
			else
				stack_a->bottom->next = node;
			stack_a->bottom = node;
			stack_a->size++;
		}
		free_all(arr, j);
	}
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	//rra(stack_a);
	//rrb(stack_b);
	rra(stack_a);
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	//pa(stack_a, stack_b);
	//pa(stack_a, stack_b);
	//pa(stack_a, stack_b);
	//pa(stack_a, stack_b);
	//pa(stack_a, stack_b);
	
	//printf("B size : %d\n", stack_b->size);
	//printf("B top : %d\n", stack_b->top->num);
	//printf("B bottom : %d\n", stack_b->bottom->num);
	//printf("B top->next : %d\n", stack_b->top->next->num);
	//printf("B bottom->next : %p\n", stack_b->bottom->next);
	//ra(stack_a);


	//printf("A_CNT : %d\n", stack_a->size);
	//while (stack_a->top != NULL)
	//{
	//	printf("%d\n", stack_a->top->num);
	//	stack_a->top = stack_a->top->next;
	//}
	//printf("-----------------aaaaaa-----------------\n");
	//printf("B_CNT : %d\n", stack_b->size);
	//while (stack_b->top != NULL)
	//{
	//	printf("%d\n", stack_b->top->num);
	//	stack_b->top = stack_b->top->next;
	//}
	//printf("=================bbbbb=================\n");



//	char *arr = (char *)malloc(sizeof(char) * ft_strlen(argv[1] + 1));
//	while (i < ft_strlen(argv[1]))
//	{
//		arr[i] = argv[1][i];
//		i++;
//	}
//	arr[i] = ' ';
	
//	while (i < argc)
//	{
//		char *arr = ft_strjoin(arr, argv[i]);
//	}
//	i = 1;
//	while (i < argc)
//	{
//		char **str = ft_split(argv[i], ' ');
//		i++;
//		while (str++ != NULL)
//		{
//			char *arr++ = str[i++];
//		}
//		char *arr = 
//	}
//	char **str = ft_split(argv[1], ' ');




//	//put argv into stack_a in put_order
//	i = 1;
//	while (argc-- > 1)
//	{
//		node = (t_node *)malloc(sizeof(t_node));
//		node->num = ft_atoi(argv[i++]);
//		node->next = NULL;
//		if (stack_a->top == NULL)
//		{
//			stack_a->top = node;
//			stack_a->bottom = node;
//		}
//		else
//		{
//			stack_a->bottom = stack_a->bottom->next = node;
//		}
//		stack_a->size++;
//	}
//	while (stack_a->top != NULL)
//	{
//		printf("%d\n", stack_a->top->num);
//		stack_a->top = stack_a->top->next;
//	}
//	printf("STACK_A size : %d\n", stack_a->size);

}
