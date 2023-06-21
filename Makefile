# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 17:23:11 by jmigoya-          #+#    #+#              #
#    Updated: 2023/06/21 16:57:42 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra 
HEADER = ./include/ft_printf.h
LIBFT = ./include/libft

FILES = ft_printf.c printfutils.c print_hex.c print_ptr.c

FILES_PATH = ./srcs/

SRCS = $(addprefix $(FILES_PATH), $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp include/libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : clean fclean re
