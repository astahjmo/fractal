/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:38:46 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 09:45:51 by astaroth         ###   ########.fr       */
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
