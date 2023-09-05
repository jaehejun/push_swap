/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/05 22:05:31 by jaehejun         ###   ########.fr       */
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
	int	i;
	char	**str;

	i = 1;
	printf("ARGC : %d\n", argc);
	if (argc == 2)
	{
		while (argc-- > 1)
		{
			str = ft_split(argv[i++], ' ');
		}
		i = 0;
		while (str[i] != NULL)
			printf("%s\n", str[i++]);
	}
	else
	{
		i = 1;
		while (argc-- > 1)
			printf("%s\n", argv[i++]);
	}
}

//int	main(void)
//{
//	printf("sa\nsa\n");
//}