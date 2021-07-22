/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:59:12 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/04 16:59:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_is_letter(char c)
{
	return (ft_is_lowercase(c) || ft_is_uppercase(c));
}

static int	ft_is_alphanum(char c)
{
	return (ft_is_letter(c) || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize;

	i = 0;
	capitalize = 1;
	while (str[i] != '\0')
	{
		if (!ft_is_alphanum(str[i]))
			capitalize = 1;
		else
		{
			if (capitalize && ft_is_lowercase(str[i]))
				str[i] = str[i] - 32;
			else if (!capitalize && ft_is_uppercase(str[i]))
				str[i] = str[i] + 32;
			capitalize = 0;
		}
		i++;
	}
	return (str);
}
