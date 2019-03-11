# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 16:19:10 by mdovhopo          #+#    #+#              #
#    Updated: 2019/03/08 12:23:25 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BIN_DIR = bin

FLAGS = -Wall -Wextra -Werror

INC_DIR = -I ./inc

SRC_DIR = src

STRING_SRC_DIR = string

MATH_SRC_DIR = math

SRC_C = $(addprefix ./$(SRC_DIR)/, $(addprefix $(STRING_SRC_DIR)/, ft_isalpha.c \
																   ft_isdigit.c \
																   ft_isalnum.c \
																   ft_isascii.c \
																   ft_isprint.c \
																   ft_toupper.c \
																   ft_tolower.c \
																   ft_itoa.c \
																   ft_atoi16.c \
								   								   ft_bzero.c \
																   ft_count_words.c \
																   ft_atoi.c \
																   ft_memset.c \
								   								   ft_memalloc.c \
								   								   ft_memdel.c \
								   								   ft_memcpy.c \
																   ft_memccpy.c \
																   ft_memmove.c \
																   ft_memchr.c \
																   ft_memcmp.c \
								   								   ft_strnew.c \
																   ft_strdel.c \
																   ft_strclr.c \
																   ft_striter.c \
																   ft_striteri.c \
																   ft_strmap.c \
																   ft_strmapi.c \
																   ft_strequ.c \
																   ft_strnequ.c \
																   ft_strsub.c \
																   ft_strjoin.c \
																   ft_strtrim.c \
																   ft_strsplit.c \
																   ft_strlen.c \
																   ft_strdup.c \
																   ft_strcpy.c \
																   ft_strncpy.c \
																   ft_strcat.c \
																   ft_strncat.c \
																   ft_strlcat.c \
																   ft_strchr.c \
																   ft_strrchr.c \
																   ft_strstr.c \
																   ft_strnstr.c \
																   ft_strcmp.c \
																   ft_strncmp.c \
																   get_next_line.c \
																   ft_putchar_fd.c \
																   ft_make_coffee.c \
								   								   ft_putchar.c \
								   								   ft_putstr.c \
																   ft_putendl.c \
																   ft_putnbr.c \
																   ft_putstr_fd.c \
																   ft_putendl_fd.c \
																   ft_putnbr_fd.c ) \
									$(addprefix $(MATH_SRC_DIR)/,  ft_show_binary.c \
																   ft_map.c \
																   ft_rgb.c \
																   ft_vectors_part_1.c \
																   ft_vectors_part_2.c \
																   ft_vectors_part_3.c \
																   ft_math_small_fnc.c \
																   ft_solve_quadric.c ) )

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(SRC_O)
	@ar rc $(BIN_DIR)/$(NAME) $(SRC_O)
	@echo "\033[92m[$(NAME) Has been created.]\033[0m"

%.o: %.c
	@echo "[Compiling] $(@:.o=.c)"
	@$(CC) $(FLAGS) $(INC_DIR) -o $@ -c $<

clean:
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(BIN_DIR)/$(NAME)

re:	fclean all
