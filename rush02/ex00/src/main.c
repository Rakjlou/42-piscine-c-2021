/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:49:09 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/17 13:49:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

int	print_error(char *error, int ret)
{
	write(2, error, ft_strlen(error));
	return (ret);
}

int	number_is_valid(char *str)
{
	int	i;

	i = 0;
	while (ft_char_is_space(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	load_args(int ac, char **av, char **number, t_dict **dict)
{
	*dict = NULL;
	if (ac == 2)
	{
		*number = av[1];
		*dict = get_dictionary(DICTIONARY_DEFAULT);
	}
	else if (ac == 3)
	{
		*dict = get_dictionary(av[1]);
		*number = av[2];
	}
	else
		return (0);
	if (!number_is_valid(*number))
	{
		if (dict != NULL)
			ft_dict_destroy(*dict);
		return (0);
	}
	*number = ft_sanitize_number(*number);
	return (1);
}

int	main(int ac, char **av)
{
	t_dict	*dict;
	char	*number;

	if (!load_args(ac, av, &number, &dict))
		return (print_error(ERROR_MSG, 0));
	if (dict == NULL || !dict_has_mandatory_keys(dict))
		print_error(DICT_ERROR_MSG, 0);
	else if (number[0] == '\0' || !solve(dict, number))
		print_error(ERROR_MSG, 0);
	else
		write(1, "\n", 1);
	ft_dict_destroy(dict);
}
