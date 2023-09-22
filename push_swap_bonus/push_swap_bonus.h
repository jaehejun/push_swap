/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:20:36 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/20 19:57:23 by jaehejun         ###   ########.fr       */
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
# define BUFFER_SIZE 100

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

char		*free_memory(char *allocated1, char *allocated2);
char		*make_line(char *temp_read);
char		*make_remain(char *temp_read);
char		*read_line(int fd, char *remain);
char		*get_next_line(int fd);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);

void		free_allocated(t_all *all);
int			ft_strcmp(char *s1, char *s2);

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
long long	check_number(char *arr);
void		check_dup(t_all *all, long long number);

int			is_sorted(t_all *all);
void		check_line(char *line, t_all *all);
void		print_error(void);

#endif
