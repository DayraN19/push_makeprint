# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 10:13:02 by bgranier          #+#    #+#              #
#    Updated: 2025/11/20 15:11:31 by bgranier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_print_hex.c \
	ft_print_ptr.c \
	ft_printf_utils.c \
	ft_printf.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re