/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:29:44 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/19 13:23:50 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <mlx.h>
#include <X11/X.h>

static t_fractal	*init_fractal(enum e_set set, int width, int height)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	fractal->img = (t_image *)malloc(sizeof(t_image));
	fractal->set = set;
	fractal->img->width = width;
	fractal->img->height = height;
	fractal->scale = (width / 2. + height / 2.) / 2;
	fractal->x = width / 2. / fractal->scale * -0.8;
	fractal->y = height / 2. / fractal->scale * -1.9;
	return (fractal);
}

int	program_init(int width, int height, enum e_set set)
{
	t_data	*client;

	if (!width || !height)
	{
		width = WINDOW_WIDTH;
		height = WINDOW_HEIGHT;
	}
	client = malloc(sizeof(t_data));
	client->display = mlx_init();
	client->windows = mlx_new_window(client->display, width, height, "Fractal");
	client->fractal = init_fractal(set, width, height);
	client->fractal->img->mlx_image = mlx_new_image(client->display,
			width, height);
	client->fractal->img->addr = mlx_get_data_addr(
			client->fractal->img->mlx_image,
			&client->fractal->img->bpp,
			&client->fractal->img->line_len,
			&client->fractal->img->endian);
	start_mandel(client);
	mlx_hook(client->windows, KeyRelease, KeyReleaseMask,
		handle_keyrelease, client);
	mlx_mouse_hook(client->windows, mouse_handle, client);
	mlx_expose_hook(client->windows, expose_handler, client);
	mlx_loop(client->display);
	return (0);
}
