/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/19 18:00:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void		ft_trace(t_point *pt1, t_env *new)
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
		mlx_pixel_put(new->mlx, new->win, pt1->x, pt1->y, 0xFF00FF);
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

int		expose_hook(t_param *t)
{
	ft_draw(t->e, t->tab);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		new;
	t_param		t;

	t.tab = ft_get_data(argc, argv);
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 720, 720, "42");
	t.e = &new;
	mlx_key_hook(new.win, key_hook, &new);
	mlx_expose_hook(new.win, expose_hook, &t);
	mlx_mouse_hook(new.win, mouse_hook, &new);
	mlx_loop(new.mlx);
	return (0);
}

