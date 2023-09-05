/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:11:47 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/05 21:58:06 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int	num;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
} t_stack;

//static int	is_space(char c);
int			ft_atoi(const char *str);

int			count_single(const char *s, char c);
char		*single(const char *s, char c);
void		free_all(char **str, int index);
char		**ft_split(char const *s, char c);

#endif
