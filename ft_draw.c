/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:43:11 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/19 17:45:14 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_draw(t_env *e, int **tab)
{
	ft_draw_all(tab, e);
}

void		ft_draw_while(t_draw_all *draw, int **tab, t_point *point1, t_env *e)
{
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->j != 1)
		ft_trace(&*point1, e);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->j++;
}

void		ft_draw_while2(t_draw_all *draw, int **tab, t_point *point1, t_env *e)
{
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->i != 0)
		ft_trace(&*point1, e);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->i++;
}

void		ft_draw_all(int **tab, t_env *e)
{
	t_point	point1;
	t_draw_all	draw;

	draw.i = 0;
	draw.j = 1;
	point1.x = 300;
	point1.y = 20;
	while (tab[draw.i] != '\0')
	{
		while (draw.j <= tab[draw.i][0])
			ft_draw_while(&draw, tab, &point1, e);
		draw.j = 1;
		draw.i++;
	}
	draw.i = 0;
	draw.j = 1;
	while (draw.j <= tab[draw.i][0])
	{
		while (tab[draw.i] != '\0')
			ft_draw_while2(&draw, tab, &point1, e);
		draw.i = 0;
		draw.j++;
	}
}
