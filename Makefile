# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 17:23:11 by jmigoya-          #+#    #+#              #
#    Updated: 2024/05/26 20:39:29 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_printf.c printfutils.c print_hex.c print_ptr.c

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -pthread -g

LIBFT_DIR = ./include/libft/
LIBFT_PATH = $(LIBFT_DIR)libft.a

# COMPILATION
NAME = libftprintf.a
CC = gcc
RM = rm -f

# COLORS
BLACK := \033[1;30m
RED := \033[1;31m
GREEN := \033[1;32m
PURPLE := \033[1;35m
CYAN := \033[1;36m
WHITE := \033[1;37m
EOC := \033[0;0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo -e "$(CYAN) Compiling $@...🛠️ $(EOC)"
	@make -C $(LIBFT_DIR) -s
	@cp include/libft/libft.a .
	@echo -e "$(CYAN) Compiling libft$@...🛠️ $(EOC)"
	@mv libft.a $(NAME)
	@echo -e "$(GREEN) LIBFT OK COMPILED $(EOC)"
	@ar rcs  $(NAME) $(OBJ_FILES)
	@echo -e "$(GREEN) OK COMPILED $(EOC)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(RED) Cleaning $(NAME)... $(EOC)"
	@make clean -C $(LIBFT_DIR) -s
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo -e "$(PURPLE) Full Cleaning...🧹 $(EOC)"
	@make fclean -C $(LIBFT_DIR) -s
	@$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean re
