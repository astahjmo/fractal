/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:14:56 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/25 20:03:20 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	encoder_argb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_fractal(t_data *client)
{
	mlx_put_image_to_window(client->display, client->windows,
		client->fractal->img->mlx_image, 0, 0);
}

void	select_set(t_data *client)
{
	if (client->fractal->set == JULIA)
		start_julia(client);
	if (client->fractal->set == MANDELBROT)
		start_mandel(client);
}

t_color	get_color(int n)
{
	t_color	color;
	double	t;

	t = (double)n / (double) MAX_INTER;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}
