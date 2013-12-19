/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/19 17:09:37 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void		ft_draw(t_env e, int **tab)
{
	ft_draw_all(tab, e);
}
int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	ft_trace(t_point *pt1, t_env new)
{
	t_delta	delta;

	delta.dx = ft_abs(pt1->x2 - pt1->x);
	delta.x = (pt1->x < pt1->x2) ? 1 : -1;
	delta.dy = ft_abs(pt1->y2 - pt1->y);
	delta.y = (pt1->y < pt1->y2) ? 1 : -1; 
	delta.deltaE = (delta.dx > delta.dy) ? delta.dx : -delta.dy;
	delta.deltaE = delta.deltaE / 2;
	while (1)
	{
		mlx_pixel_put(new.mlx, new.win, pt1->x, pt1->y, 0xFF00FF);
		if (pt1->x == pt1->x2 && pt1->y == pt1->y2)
			break ;
		delta.deltaNE = delta.deltaE;
		if (delta.deltaNE > -delta.dx)
		{
			delta.deltaE -= delta.dy;
			pt1->x += delta.x;
		}
		if (delta.deltaNE < delta.dy)
		{
			delta.deltaE += delta.dx;
			pt1->y += delta.y;
		}
	}
}

int		key_hook(int keycode, t_env *e)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putstr("mouse: ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

int		expose_hook(t_env e, int **tab)
{
	ft_draw(e, tab);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		new;
	int		**tab;

	tab = ft_get_data(argc, argv);
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 720, 720, "42");
	mlx_key_hook(new.win, key_hook, &new);
	mlx_expose_hook(new.win, expose_hook, &new);
	mlx_mouse_hook(new.win, mouse_hook, &new);
	/* ft_draw(new.mlx, new.win, tab); */
	ft_draw(new, tab);
	mlx_loop(new.mlx);
	return (0);
}

float	sqrt1(const float x)
{
	t_union	u;

	u.x = x;
	u.i = (1<<29) + (u.i >> 1) - (1<<22); 
	u.x =       u.x + x/u.x;
	u.x = 0.25f*u.x + x/u.x;

  return u.x;
}

void	ft_draw_while(t_draw_all *draw, int **tab, t_point *point1, t_env e)
{
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->j != 1)
		ft_trace(&*point1, e);
	usleep(10000);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->j++;
}

void	ft_draw_while2(t_draw_all *draw, int **tab, t_point *point1, t_env e)
{
	draw->fi = draw->i;
	draw->fj = draw->j;
	draw->fz = tab[draw->i][draw->j];
	point1->x2 = ft_calc_ax(draw->fi, draw->fj, draw->fz);
	point1->y2 = ft_calc_ay(draw->fi, draw->fj, draw->fz);
	if (draw->i != 0)
		ft_trace(&*point1, e);
	usleep(10000);
	point1->x = point1->x2;
	point1->y = point1->y2;
	draw->i++;
}

void	ft_draw_all(int **tab, t_env e)
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
