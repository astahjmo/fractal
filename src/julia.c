/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:27 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/24 22:25:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_color	get_color(int n)
{
	t_color	color;
	double	t;

	t = (double)n / (double)180;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}

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
