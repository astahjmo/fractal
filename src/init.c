/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:29:44 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/07 00:09:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <mlx.h>

int   program_init(int width, int height,enum e_set set)
{
	t_data client;
	client.fractal = (t_fractal *)malloc(sizeof(t_fractal));
	client.fractal->img = (t_image *)malloc(sizeof(t_image));
	client.fractal->cam = (t_cam *)malloc(sizeof(t_cam));
	if (!width || !height)
	{
		width = WINDOW_WIDTH;
		height = WINDOW_HEIGHT;
	}
	client.display = mlx_init();
	client.windows = mlx_new_window(client.display, width, height, "Fractal");
	client.fractal->img->mlx_image = mlx_new_image(client.display,
												width, height);
	client.fractal->img->addr = mlx_get_data_addr(
			client.fractal->img->mlx_image,	
			&client.fractal->img->bpp,
			&client.fractal->img->line_len,
			&client.fractal->img->endian);

	mlx_loop(client.display);

	return (0);
}
