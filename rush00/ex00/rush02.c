/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:55:52 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/04 19:55:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define S_LEFT_CHAR 'A'
#define S_REG_CHAR 'B'
#define S_RIGHT_CHAR 'A'
#define M_LEFT_CHAR 'B'
#define M_REG_CHAR ' '
#define M_RIGHT_CHAR 'B'
#define L_LEFT_CHAR 'C'
#define L_REG_CHAR 'B'
#define L_RIGHT_CHAR 'C'

void	ft_putchar(char c);

static void	ft_generic_line(int x, char l_char, char reg_char, char right_char)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(l_char);
		else if (i == x - 1)
			ft_putchar(right_char);
		else
			ft_putchar(reg_char);
		i++;
	}
}

void	rush02(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_generic_line(x, S_LEFT_CHAR, S_REG_CHAR, S_RIGHT_CHAR);
		else if (i == y - 1)
			ft_generic_line(x, L_LEFT_CHAR, L_REG_CHAR, L_RIGHT_CHAR);
		else
			ft_generic_line(x, M_LEFT_CHAR, M_REG_CHAR, M_RIGHT_CHAR);
		ft_putchar('\n');
		i++;
	}
}
