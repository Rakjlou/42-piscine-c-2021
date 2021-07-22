/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:02:19 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/14 00:02:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	char	*tmp;
	int		sorted;
	int		i;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (tab[i] != 0 && tab[i + 1] != 0)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				sorted = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}
