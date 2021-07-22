# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:54:32 by nsierra-          #+#    #+#              #
#    Updated: 2015/01/04 16:41:19 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
LIBFT_DIR = src/libft/
DICT_DIR = src/dict/
SRC = $(wildcard $(SRC_DIR)*.c) \
		$(wildcard $(LIBFT_DIR)*.c) \
		$(wildcard $(DICT_DIR)*.c)
IFLAGS = -I inc/ -I inc/libft -I inc/dict
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
CC = cc
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
