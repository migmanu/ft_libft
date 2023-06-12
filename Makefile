# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 17:23:11 by jmigoya-          #+#    #+#              #
#    Updated: 2023/06/12 15:54:14 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
LIBFT = include/libft
CC = gcc
CFLAGS = -Werror -Wall -Wextra 
HEADER = ft_printf.h

FILES = ft_printf.c printfutils.c

FILES_PATH = ./srcs/

SRCS = $(addprefix $(FILES_PATH), $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ar rcs $(NAME) $(OBJS)

clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a

re : fclean all

.PHONY : clean fclean re
