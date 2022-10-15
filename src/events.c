/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:55:14 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/15 14:18:21 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "X11/keysym.h"
#include <mlx.h>
#include <stdlib.h>


int	mouse_handle(int keysym, int x, int y, t_data*data)
{
	if (keysym == 5)
	{

		printf("up");
		data->fractal->scale /= 1.2;
		data->fractal->x = (x / data->fractal->scale + data->fractal->x) - (x / (data->fractal->scale / 1.2));
		data->fractal->y = (y / data->fractal->scale + data->fractal->y) - (y / (data->fractal->scale / 1.2));
		start_mandel(data);
	}
	if (keysym == 4)
	{

		printf("\n%f\n%f\n", data->fractal->x, data->fractal->y);
		printf("down");
		data->fractal->scale *= 1.2;
		data->fractal->x = (x / data->fractal->scale + data->fractal->x) - (x / (data->fractal->scale * 1.2));
		data->fractal->y = (y / data->fractal->scale + data->fractal->y) - (y / (data->fractal->scale * 1.2));
		start_mandel(data);
	}
	printf("mouse release:x %d\ny%d\n", x, y );
	return (0);
}
int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		mlx_loop_end(data->display);
		mlx_destroy_image(data->display, data->fractal->img->mlx_image);
		free(data->fractal->img);
		free(data->fractal);
		mlx_destroy_window(data->display, data->windows);
		mlx_destroy_display(data->display);
		free(data);
		exit(0);
	}
	printf("Key release: %d\n", keysym);
	return (0);
}
int	expose_handler(t_data *data)
{
	draw_fractal(data);
	return (0);
}
