/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:51:56 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/30 19:19:08 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	check_argc()
	check_argv()
	./push_swap 2 1 3 6 5 8
	
	./push_swap 0 one 2 3 -> ERROR

	ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
		6
	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
	OK
}