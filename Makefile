# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:50:13 by jaehejun          #+#    #+#              #
#    Updated: 2023/09/17 16:57:08 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

CC		= CC

CFLAGS	= -Wall -Wextra -Werror -g

SRCS	= main.c\
./push_swap_utils/ft_split.c\
./push_swap_utils/ft_atoi.c\
./push_swap_utils/free_deques.c\
./operations/swap_operation.c\
./operations/push_operation.c\
./operations/rotate_opearation.c\
./operations/reverse_rotate_operation.c\
./make_deque/make_deque.c\
./make_deque/indexing.c\
./sort_deque/sort_utils.c\
./sort_deque/sort_small.c\
./sort_deque/sort_big.c\
./sort_deque/greedy_operations.c\

OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
