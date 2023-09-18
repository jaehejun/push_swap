# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:50:13 by jaehejun          #+#    #+#              #
#    Updated: 2023/09/18 20:46:28 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

NAME_BONUS	= checker

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

SRCS_BONUS	= ./push_swap_bonus/main_bonus.c\
./push_swap_bonus/get_next_line_bonus.c\
./push_swap_bonus/get_next_line_utils_bonus.c\
./push_swap_bonus/ft_split_bonus.c\
./push_swap_bonus/ft_atoi_bonus.c\
./push_swap_bonus/swap_operation_bonus.c\
./push_swap_bonus/push_operation_bonus.c\
./push_swap_bonus/rotate_opearation_bonus.c\
./push_swap_bonus/reverse_rotate_operation_bonus.c\
./push_swap_bonus/make_deque_bonus.c\
./push_swap_bonus/checker_utils_bonus.c\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS)	: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re:
	make fclean
	make all
