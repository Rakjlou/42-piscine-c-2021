/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:46 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	get_views_for_line(t_skyscraper *s, unsigned int line, int *l, int *r)
{
	*l = s->views[VIEW_LEFT_1 + line];
	*r = s->views[VIEW_RIGHT_1 + line];
}

void	get_views_for_col(t_skyscraper *s, unsigned int col, int *u, int *d)
{
	*u = s->views[VIEW_TOP_1 + col];
	*d = s->views[VIEW_DOWN_1 + col];
}
