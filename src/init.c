/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:29:44 by astaroth          #+#    #+#             */
/*   Updated: 2022/09/26 15:46:37 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int	render(t_data *data)
{

	start_mandel(&data->img, WINDOW_WIDTH,WINDOW_HEIGHT);
	mlx_put_image_to_window(data->display, data->windows, data->img.mlx_image, 0, 0);
	return (0);
}

int   program_init(int width, int height)
{
	t_data client;

	if (!width || !height)
	{
		width = WINDOW_WIDTH;
		height = WINDOW_HEIGHT;
	}
	printf("%s", "aaaa");
	client.display = mlx_init();
	client.windows = mlx_new_window(client.display, width, height, "fractal");
	client.img.mlx_image = mlx_new_image(client.display, width, height);
	client.img.addr = mlx_get_data_addr(client.img.mlx_image, &client.img.bpp, &client.img.line_len, &client.img.endian);
	mlx_loop_hook(client.display, &render, &client);
	mlx_loop(client.display);
	return (0);
}
