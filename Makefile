# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 10:01:06 by pdeguing          #+#    #+#              #
#    Updated: 2018/10/06 10:15:54 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= ft_select

SRCS	= srcs/ft_select.c \
		  srcs/display_usage.c

LIB		= -lft -L./libft/
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) cmp

$(LIBFT):
	@ cd libft/ && make

cmp:
	@ gcc -o $(NAME) $(CFLAGS) $(SRCS) -Iincludes $(LIB)

clean:
	@ /bin/rm -f *.o
	@ cd libft/ && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re
