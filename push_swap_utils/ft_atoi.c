/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:42:02 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:33 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	if (*str == '\0')
		return (INVALID);
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
			str++;
		else
			return (INVALID);
	}
	return (VALID);
}

long long	ft_atoi(char *str)
{
	int			sign;
	long long	number;
	long long	result;

	sign = 1;
	number = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (is_number(str) == INVALID)
		return (NOT_NUM);
	while ('0' <= *str && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	result = number * sign;
	if (result > 2147483647 || result < -2147483648)
		return (OUT_OF_RANGE);
	return (result);
}
