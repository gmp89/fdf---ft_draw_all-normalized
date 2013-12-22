/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:33:53 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:35:13 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_calc_ay(float i, float j, float z)
{
	int		y;
	float	ay;
	float	d;
	float	e;

	i = (i + 1) * GRID_SIZE;
	z = (z + 1) * GRID_SIZE / 10;
	j = (j + 1) * GRID_SIZE / 2;
	d = sqrt1((my_pow(i) + my_pow(i))) / 2;
	e = sqrt1((my_pow(j) + my_pow(j))) / 2;
	ay = d + e;
	return ((y = (int)ay) - (int)z );
}

int		ft_calc_ax(float i, float j, float z)
{
	int		x;
	float	ax;
	float	d;
	float	e;

	i = (i + 1) * GRID_SIZE;
	z = (z + 1) * GRID_SIZE;
	j = (j + 1) * GRID_SIZE;
	d = sqrt1((my_pow(i) + my_pow(i))) / 2;
	e = sqrt1((my_pow(j) + my_pow(j))) / 2;
	ax = (sqrt1(my_pow(j) - my_pow(e))) - (sqrt1(my_pow(i) - my_pow(d)));
	return ((x = (int)ax) + OFFSET_X);
}

float		my_pow(float x)
{
	return (x * x);
}

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

float		sqrt1(const float x)
{
	int	i;
	float	d;
	float	p;
	float	a;

	i = 0;
	while ((i * i) <= x)
		i++;
	i--;
	d = x - i * i;
	p = d / (2 * i);
	a = i + p;
	return (a - (p * p) / ( 2 * a));
}
