# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:50:13 by jaehejun          #+#    #+#              #
#    Updated: 2023/09/17 17:30:47 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

NAME_B	= checker

CC		= CC

CFLAGS	= -Wall -Wextra -Werror

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

SRCS_B	= ./checker/main_bonus.c\
./checker/get_next_line_bonus.c\
./checker/get_next_line_utils_bonus.c\
./checker/ft_split_bonus.c\
./checker/ft_atoi_bonus.c\
./checker/swap_operation_bonus.c\
./checker/push_operation_bonus.c\
./checker/rotate_opearation_bonus.c\
./checker/reverse_rotate_operation_bonus.c\
./checker/make_deque_bonus.c\
./checker/checker_utils_bonus.c\
./checker/free_deques_bonus.c\


OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_B)	: $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: all $(NAME_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re:
	make fclean
	make all
