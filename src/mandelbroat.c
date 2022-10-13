/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:50 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/13 19:25:44 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_color	get_color(int n)
{
	t_color	color;
	double	t;

	t = (double)n / (double)180;
	color.r = (int)(3 * (1 - t) * t * t * t * 255);
	color.g = (int)(20 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}

static t_color	plot_mandel(t_fractal *fractal, int x, int y)
{
	int		n;
	double	z;
	double	c;
	double	temp;
	double	re;
	double	im;

	z = 0;
	c = 0;
	n = 0;
	re = ((float)x) / fractal->scale + fractal->x;
	im = ((float)y) / fractal->scale + fractal->y;
	while (n < 180 && pow(z, 2) + pow(c, 2) < 4)
	{
		temp = z;
		z = (pow(z, 2) - pow(c, 2) + im);
		c = (2 * temp * c) + re;
		n++;
	}
	return (get_color(n));
}

int	start_mandel(t_data *data)
{
	int				i;
	int				j;
	long int		row;
	t_color			color;
	t_fractal		*fractal;

	fractal = data->fractal;
	i = 0;
	while (i < fractal->img->height)
	{
		j = 0;
		while (j < fractal->img->width)
		{
			row = i * fractal->img->width;
			color = plot_mandel(fractal, i, j);
			((unsigned int *)fractal->img->addr)[j + row] = encoder_argb(
					color.r,
					color.g,
					color.b);
			j++;
		}
		i++;
	}
	draw_fractal(data);
	return (0);
}
