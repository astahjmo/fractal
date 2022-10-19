/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:55:14 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/19 15:49:23 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "X11/keysym.h"
#include <mlx.h>
#include <stdlib.h>

void	move_direction(t_data *data, int direction, double value)
{
	t_fractal *fractal;

	fractal = data->fractal;
	if (direction == 1)
		fractal->y -= (value / fractal->scale * fractal->img->height / 4);
	if (direction == 2)
		fractal->x -= (value / fractal->scale * fractal->img->width / 4);
	if (direction == 3)
		fractal->y += (value / fractal->scale * fractal->img->height / 4);
	if (direction == 4)
		fractal->x += (value / fractal->scale * fractal->img->width / 4);
	start_mandel(data);
}

void	zoom(t_data *data, double scale, int x, int y)
{
	double	x_before_zoom;
	double	y_before_zoom;
	double	x_after_zoom;
	double	y_after_zoom;

	x_before_zoom = (double)x / data->fractal->scale + data->fractal->x;
	y_before_zoom = (double)y / data->fractal->scale + data->fractal->y;
	data->fractal->scale *= scale;
	x_after_zoom = (double)x / data->fractal->scale + data->fractal->x;
	y_after_zoom = (double)y / data->fractal->scale + data->fractal->y;
	data->fractal->x += x_before_zoom - x_after_zoom;
	data->fractal->y += y_before_zoom - y_after_zoom;
	start_mandel(data);
}

int	mouse_handle(int keysym, int x, int y, t_data*data)
{
	if (keysym == 5)
		zoom(data, .9, x, y);
	if (keysym == 4)
		zoom(data, 1.2, y, x);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		mlx_destroy_window(data->display, data->windows);
		mlx_loop_end(data->display);
		mlx_destroy_image(data->display, data->fractal->img->mlx_image);
		free(data->fractal->img);
		free(data->fractal);
		mlx_destroy_display(data->display);
		free(data->display);
		free(data);
		exit(0);
	}
	if (keysym == 65361)
		move_direction(data, 1, 1.2);
	if (keysym == 65362)
		move_direction(data, 2, 1.2);
	if (keysym == 65363)
		move_direction(data, 3,  1.2);
	if (keysym == 65364)
		move_direction(data, 4, 1.2);
	return (0);
}

int	expose_handler(t_data *data)
{
	draw_fractal(data);
	return (0);
}
