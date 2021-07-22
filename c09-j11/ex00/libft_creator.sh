gcc -c ft_putchar.c &&
gcc -c ft_putstr.c &&
gcc -c ft_strcmp.c &&
gcc -c ft_strlen.c &&
gcc -c ft_swap.c &&
ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o &&
ranlib libft.a
