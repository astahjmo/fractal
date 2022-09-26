/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:29:44 by astaroth          #+#    #+#             */
/*   Updated: 2022/09/26 17:40:03 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int   program_init(int width, int height)
{
	t_data client;

	if (!width || !height)
	{
		width = WINDOW_WIDTH;
		height = WINDOW_HEIGHT;
	}
	client.display = mlx_init();
	client.windows = mlx_new_window(client.display, width, height, "fractal");
	client.img.mlx_image = mlx_new_image(client.display, width, height);
	client.img.addr = mlx_get_data_addr(client.img.mlx_image, &client.img.bpp, &client.img.line_len, &client.img.endian);

	mlx_loop_hook(client.display, &render, &client);
	mlx_mouse_hook(client.windows, &handle_mouse, &client);
	mlx_loop(client.display);
	return (0);
}
