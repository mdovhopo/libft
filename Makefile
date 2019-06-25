# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 16:19:10 by mdovhopo          #+#    #+#              #
#    Updated: 2019/05/31 16:09:17 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INC_DIR = -I ./inc

SRC_DIR = src
STRING_SRC_DIR	=	./$(SRC_DIR)/string
MATH_SRC_DIR	=	./$(SRC_DIR)/math
PRINT_SRC_DIR	=	./$(SRC_DIR)/print
FT_PRINTF_SRC_DIR = ./$(PRINT_SRC_DIR)/ft_printf

SRC_C = $(addprefix $(MATH_SRC_DIR)/,	ft_map.c ft_vectors.c ft_math_small_fnc.c ft_solve_quadric.c ft_rand.c) \
		$(addprefix $(STRING_SRC_DIR)/,	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
										ft_is_wspace.c ft_toupper.c ft_tolower.c ft_itoa.c ft_atoi16.c \
										ft_bzero.c ft_count_words.c ft_atoi.c ft_memset.c ft_memalloc.c \
										ft_memdel.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
										ft_memcmp.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
										ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
										ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strlen.c \
										ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
										ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
										ft_strcmp.c ft_strncmp.c get_next_line.c ) \
		$(addprefix $(PRINT_SRC_DIR)/,	ft_putchar_fd.c ft_show_binary.c ft_make_coffee.c ft_putchar.c \
										ft_putstr.c ft_putendl.c ft_putnbr.c ft_putstr_fd.c \
										ft_putendl_fd.c ft_putnbr_fd.c ) \
		$(addprefix $(FT_PRINTF_SRC_DIR)/, ft_printf.c print_format.c parse_format.c handle_token.c \
										utils.c print_sc_type.c print_d_type.c print_o_type.c \
										print_u_type.c print_x_type.c print_p_type.c print_f_type.c \
										ft_putfloat.c )


SRC_O = $(SRC_C:.c=.o)

CC = clang

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
