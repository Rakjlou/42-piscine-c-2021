/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:40:43 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/22 15:40:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*res;

	if (root == NULL)
		return (NULL);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (res != NULL)
		return (res);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
