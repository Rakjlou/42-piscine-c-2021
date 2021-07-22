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

SRC_FILES = print.c display.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strdup.c \
			print2.c ft_itoa_base.c files.c ft_memcmp.c main.c
SRC_DIR = src/
IFLAGS = -I inc/
CFLAGS = -Wall -Wextra -Werror
NAME = ft_hexdump
CC = gcc
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
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
