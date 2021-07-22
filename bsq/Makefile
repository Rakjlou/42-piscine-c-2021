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

SRC_FILES = libft/ft_putstr_fd.c \
			libft/ft_strlen.c \
			libft/ft_str_merge_buffer.c \
			libft/ft_strdup.c \
			libft/ft_strstr.c \
			libft/ft_get_last_char.c \
			libft/ft_split.c \
			libft/ft_strjoin_old.c \
			libft/ft_free_tab.c \
			libft/ft_char_is_printable.c \
			libft/ft_strcpy.c \
			libft/ft_get_fd_contents.c \
			libft/ft_strnew.c \
			libft/ft_bzero.c \
			libft/ft_print_error.c \
			libft/ft_strchr.c \
			libft/ft_strlcat.c \
			libft/ft_memset.c \
			libft/ft_putendl.c \
			libft/ft_magic_free.c \
			gnl.c \
			load_map.c \
			bsq.c \
			solve.c \
			main.c
SRC_DIR = src/
IFLAGS = -I inc/
CFLAGS = -O3 -Wall -Wextra -Werror
NAME = bsq
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
