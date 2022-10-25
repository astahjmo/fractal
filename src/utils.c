/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:53 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/24 22:25:55 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <mlx.h>

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
