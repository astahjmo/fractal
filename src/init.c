/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:57 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/28 04:12:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static t_fractal	*init_fractal(enum e_set set, double re, double im)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	fractal->img = (t_image *)malloc(sizeof(t_image));
	if (fractal == NULL || fractal->img == NULL)
		return (fractal);
	fractal->set = set;
	if (set == JULIA)
	{
		fractal->re = re;
		fractal->im = im;
	}
	fractal->img->width = WIDTH;
	fractal->img->height = HEIGHT;
	fractal->scale = (WIDTH + HEIGHT) / 6.0;
	fractal->x = WIDTH / 2.0 / fractal->scale * -1;
	fractal->y = HEIGHT / 2.0 / fractal->scale * -1;
	return (fractal);
}

static t_data	*memory_init(enum e_set set, double re, double im)
{
	t_data	*client;

	client = malloc(sizeof(t_data));
	if (client == NULL)
		exit_with_error(ERR_ALLOC, 1, client);
	client->display = mlx_init();
	if (client->display == NULL)
		exit_with_error(ERR_X11, 2, client);
	client->windows = mlx_new_window(client->display, WIDTH, HEIGHT, "Fractal");
	client->fractal = init_fractal(set, re, im);
	client->fractal->img->mlx_image = mlx_new_image(client->display,
			WIDTH, HEIGHT);
	client->fractal->img->addr = mlx_get_data_addr(
			client->fractal->img->mlx_image,
			&client->fractal->img->bpp,
			&client->fractal->img->line_len,
			&client->fractal->img->endian);
	return (client);
}

int	program_init(enum e_set set, double re, double im)
{
	t_data	*client;

	client = memory_init(set, re, im);
	select_set(client);
	mlx_hook(client->windows, KeyRelease, KeyReleaseMask,
		handle_keyrelease, client);
	mlx_mouse_hook(client->windows, mouse_handle, client);
	mlx_expose_hook(client->windows, expose_handler, client);
	mlx_hook(client->windows, DestroyNotify, NoEventMask,
		exit_program, client);
	mlx_loop(client->display);
	return (0);
}
