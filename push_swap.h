/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:11:47 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/14 22:55:08 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define VALID 1
# define INVALID 0
# define NOT_NUM 2147483648
# define OUT_OF_RANGE -2147483649
# define NUM_MAX 4294967295

typedef struct s_node
{
	long long		num;
	long long		index;
	int				r_count;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	long long	size;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

typedef struct s_all
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_all;

void	print(t_all *all);


int			is_number(char *str);
long long	ft_atoi(char *str);

long long	count_single(const char *s, char c);
char		*single(const char *s, char c);
void		free_all(char **str, long long index);
char		**ft_split(char const *s, char c);

void		sa(t_stack *stack_a);
void		sb(t_stack *stack_a);
void		ss(t_stack *stack_a, t_stack *stack_b);

void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

void		init_stack(t_all *all);
void		make_stack(int argc, char**argv, t_all *all);
void		make_node(t_all *all, char *arr);
void		check_number(char *arr);
void		check_dup(t_all *all, char *arr);

void		indexing(t_all *all);
void		quick_sort(long long *array, long long low, long long high);
void		swap(long long *a, long long *b);
void		numbering(long long *index, t_all *all);

void		sort_six(t_all *all);
void		push_min(t_all *all, int minimum);
void		sort_three(t_all *all);

void		sort_stack(t_all *all);
void		push_to_b(t_all *all);
long long	find_a(t_all *all, long long b_num);
long long	find_a_with_biggest_b(t_all *all, long long b_num);
int			is_sorted(t_all *all);



#endif
