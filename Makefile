# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/24 14:44:20 by yomafama          #+#    #+#              #
#    Updated: 2026/11/26 22:41:01 by yomafama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I. -g

RM		=	rm -f

HEADER	=	push_swap.h

SRCS	=	stack/ft_ar.c stack/ft_atoi.c stack/ft_split.c stack/ft_strcmp.c \
			stack/ft_strjoin.c stack/ft_strlen.c stack/ft_free_ar.c \
			stack/ft_free_stack.c \
			make_stack.c \
			rules/swap.c rules/push.c rules/rotate.c rules/r_rotate.c \
			algo_tools/rot_n.c algo_tools/rrot_n.c \
			simple.c \
			medium.c \
			main.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
