# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:50:13 by jaehejun          #+#    #+#              #
#    Updated: 2023/09/06 15:47:29 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

CC		= CC

CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c ft_split.c ft_atoi.c

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