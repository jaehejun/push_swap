# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:50:13 by jaehejun          #+#    #+#              #
#    Updated: 2023/09/13 16:52:19 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

CC		= CC

CFLAGS	= -Wall -Wextra -Werror -g

SRCS	= main.c ft_split.c ft_atoi.c swap_operation.c push_operation.c\
rotate_opearation.c reverse_rotate_operation.c make_stack.c indexing.c\
sorting_five.c sorting_else.c

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
