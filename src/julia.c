/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:18 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/25 11:13:20 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static t_color	plot_julia(t_fractal *fractal, int x, int y)
{
	int				n;
	double			temp;
	double			z;
	double			c;

	z = ((double) x / fractal->scale + fractal->x);
	c = ((double) y / fractal->scale + fractal->y);
	n = 0;
	temp = 0;
	while (n < 180 && z * z + c * c < 4.)
	{
		temp = (2 * z * c) + fractal->im * (-1);
		z = (z * z - c * c) + fractal->re;
		c = temp;
		n++;
	}
	return (get_color(n));
}

int	start_julia(t_data *data)
{
	int				x;
	int				y;
	long int		row;
	t_color			color;
	t_fractal		*fractal;

	fractal = data->fractal;
	y = 0;
	while (y < fractal->img->height)
	{
		x = 0;
		while (x < fractal->img->width)
		{
			row = y * fractal->img->width;
			color = plot_julia(fractal, x, y);
			((unsigned int *)fractal->img->addr)[x + row] = encoder_argb(
					color.r,
					color.g,
					color.b);
			x++;
		}
		y++;
	}
	draw_fractal(data);
	return (0);
}
