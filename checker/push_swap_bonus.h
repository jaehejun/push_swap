/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:20:36 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/17 17:22:19 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define VALID 1
# define INVALID 0
# define NOT_NUM 2147483648
# define OUT_OF_RANGE -2147483649
# define NUM_MAX 4294967295

typedef struct s_node
{
	long long		num;
	long long		idx;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	long long	size;
	t_node		*top;
	t_node		*bottom;
}	t_deque;

typedef struct s_all
{
	struct s_deque	*deque_a;
	struct s_deque	*deque_b;
}	t_all;

int			is_number(char *str);
long long	ft_atoi(char *str);

long long	count_single(const char *s, char c);
char		*single(const char *s, char c);
void		free_all(char **str, long long index);
char		**ft_split(char const *s, char c);

void		free_allocated(t_all *all);

void		sa(t_deque *deque_a);
void		sb(t_deque *deque_a);
void		ss(t_deque *deque_a, t_deque *deque_b);

void		pa(t_deque *deque_a, t_deque *deque_b);
void		pb(t_deque *deque_a, t_deque *deque_b);

void		ra(t_deque *deque_a);
void		rb(t_deque *deque_b);
void		rr(t_deque *deque_a, t_deque *deque_b);

void		rra(t_deque *deque_a);
void		rrb(t_deque *deque_b);
void		rrr(t_deque *deque_a, t_deque *deque_b);

void		init_deque(t_all *all);
void		make_deque(int argc, char**argv, t_all *all);
void		make_node(t_all *all, char *arr);
void		check_number(char *arr);
void		check_dup(t_all *all, char *arr);

//void		indexing(t_all *all);
//void		quick_sort(long long *array, long long low, long long high);
//void		swap(long long *a, long long *b);
//void		numbering(long long *index, t_all *all);

//void		sort_small(t_all *all);
//void		push_min(t_all *all, int minimum);
//void		sort_three(t_all *all);

//void		sort_big(t_all *all);
//void		push_to_b(t_all *all);
//void		put_index(t_all *all);
//long long	find_a(t_all *all, long long b_num);
//void		zero_to_top(t_all *all);

//long long	tr_idx(t_deque *deque, long long result_index);
//long long	ft_abs(long long num);
int			is_sorted(t_all *all);

//void		operate_greedy(t_all *all, long long a_count, long long b_count);
//void		greedy_r(t_all *all, long long a_count, long long b_count);
//void		greedy_rr(t_all *all, long long a_count, long long b_count);
//void		greedy_seperately(t_all *all, long long a_count, long long b_count);

#endif

