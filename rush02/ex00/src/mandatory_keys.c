/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:38 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stddef.h>

void	load_mandatory_keys2(char **mandatory_keys)
{
	mandatory_keys[0] = "0";
	mandatory_keys[1] = "1";
	mandatory_keys[2] = "2";
	mandatory_keys[3] = "3";
	mandatory_keys[4] = "4";
	mandatory_keys[5] = "5";
	mandatory_keys[6] = "6";
	mandatory_keys[7] = "7";
	mandatory_keys[8] = "8";
	mandatory_keys[9] = "9";
	mandatory_keys[10] = "10";
	mandatory_keys[11] = "11";
	mandatory_keys[12] = "12";
	mandatory_keys[13] = "13";
	mandatory_keys[14] = "14";
	mandatory_keys[15] = "15";
	mandatory_keys[16] = "16";
	mandatory_keys[17] = "17";
	mandatory_keys[18] = "18";
	mandatory_keys[19] = "19";
	mandatory_keys[20] = "20";
	mandatory_keys[21] = "30";
	mandatory_keys[22] = "40";
	mandatory_keys[23] = "50";
	mandatory_keys[24] = "60";
}

void	load_mandatory_keys3(char **mandatory_keys)
{
	mandatory_keys[25] = "70";
	mandatory_keys[26] = "80";
	mandatory_keys[27] = "90";
	mandatory_keys[28] = "100";
	mandatory_keys[29] = "1000";
	mandatory_keys[30] = "1000000";
	mandatory_keys[31] = "1000000000";
	mandatory_keys[32] = "1000000000000";
	mandatory_keys[33] = "1000000000000000";
	mandatory_keys[34] = "1000000000000000000";
	mandatory_keys[35] = "1000000000000000000000";
	mandatory_keys[36] = "1000000000000000000000000";
	mandatory_keys[37] = "1000000000000000000000000000";
	mandatory_keys[38] = "1000000000000000000000000000000";
	mandatory_keys[39] = "1000000000000000000000000000000000";
	mandatory_keys[40] = "1000000000000000000000000000000000000";
	mandatory_keys[41] = NULL;
}

void	load_mandatory_keys(char **mandatory_keys)
{
	load_mandatory_keys2(mandatory_keys);
	load_mandatory_keys3(mandatory_keys);
}

int	dict_has_mandatory_keys(t_dict *dict)
{
	char	*mandatory_keys[42];
	int		i;

	i = 0;
	load_mandatory_keys(mandatory_keys);
	while (mandatory_keys[i])
	{
		if (ft_find_key(dict, mandatory_keys[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
