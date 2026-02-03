# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 13:00:48 by bgranier          #+#    #+#              #
#    Updated: 2026/02/03 13:00:57 by bgranier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I . -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

SRC = push_swap.c \
	init_stack.c \
	disorder.c \
	operate.c \
	sort_simple.c \
	flag_utils.c \
	med_utils.c \
	sort_adaptive.c \
	seg_utils.c \
	sort_three.c \
	sort_five.c \
	sort_medium.c \
	dispatch_sort.c \
	sort_complex.c \
	rotate.c \
	third_utils.c \
	index_stack.c \
	new_node.c \
	stack_utils.c \
	new_stack.c \
	sorted.c \
	bench.c \
	ctrl_init.c \
	strategy.c \

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C	$(FT_PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR) 
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME) ./a.out gcc
	make fclean -C $(LIBFT_DIR) $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re