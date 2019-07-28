# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 16:19:10 by mdovhopo          #+#    #+#              #
#    Updated: 2019/07/28 17:19:08 by tryckylake       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#-Wall -Wextra -Werror
FLAGS = 

INC_DIR = -I ./inc

SRC_DIR = src
STRING_SRC_DIR	=	./$(SRC_DIR)/string
MATH_SRC_DIR	=	./$(SRC_DIR)/math
PRINT_SRC_DIR	=	./$(SRC_DIR)/print
FT_PRINTF_SRC_DIR = ./$(PRINT_SRC_DIR)/ft_printf
FT_MEMORY_SRC_DIR = ./$(SRC_DIR)/memory

SRC_C 			= $(wildcard $(STRING_SRC_DIR)/*.c)
SRC_C 		   += $(wildcard $(MATH_SRC_DIR)/*.c)
SRC_C 		   += $(wildcard $(PRINT_SRC_DIR)/*.c)
SRC_C		   += $(wildcard $(FT_PRINTF_SRC_DIR)/*.c)
SRC_C		   += $(wildcard $(FT_MEMORY_SRC_DIR)/*.c)

SRC_O = $(SRC_C:.c=.o)

CC = clang -g

.PHONY: all multi

multi:
	@$(MAKE) -s -j8 all

all: $(NAME)
	@echo "\033[92m[$(NAME) done]\033[0m"


$(NAME): $(SRC_O)
	@ar rc $(NAME) $(SRC_O)
	@echo "\033[92m[$(NAME) Has been created.]\033[0m"

%.o: %.c
	@echo "[Compiling] $(@:.o=.c)"
	@$(CC) $(FLAGS) $(INC_DIR) -o $@ -c $<

clean:
	@/bin/rm -f $(SRC_O)
	@echo "\033[92m[libft Has been cleaned.]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean multi
