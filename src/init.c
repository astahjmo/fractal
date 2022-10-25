/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:29:44 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 21:16:08 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <mlx.h>
#include <X11/X.h>

static t_fractal	*init_fractal(enum e_set set, double re, double im)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	fractal->img = (t_image *)malloc(sizeof(t_image));
	if (fractal == NULL || fractal->img == NULL)
		ft_printf(ERR_ALLOC);
	fractal->set = set;
	if (set == JULIA)
	{
		fractal->re = re;
		fractal->im = im;
	}
	fractal->img->width = WIDTH;
	fractal->img->height = HEIGHT;
	fractal->scale = (WIDTH / 2. + HEIGHT / 2.) / 4;
	fractal->x = WIDTH / 2. / fractal->scale * -1;
	fractal->y = HEIGHT / 2. / fractal->scale * -1;
	return (fractal);
}

int	program_init(enum e_set set, double re, double im)
{
	t_data	*client;

	client = malloc(sizeof(t_data));
	if (client == NULL)
		ft_printf(ERR_ALLOC);
	client->display = mlx_init();
	client->windows = mlx_new_window(client->display, WIDTH, HEIGHT, "Fractal");
	client->fractal = init_fractal(set, re, im);
	client->fractal->img->mlx_image = mlx_new_image(client->display,
			WIDTH, HEIGHT);
	client->fractal->img->addr = mlx_get_data_addr(
			client->fractal->img->mlx_image,
			&client->fractal->img->bpp,
			&client->fractal->img->line_len,
			&client->fractal->img->endian);
	select_set(client);
	mlx_hook(client->windows, KeyRelease, KeyReleaseMask,
		handle_keyrelease, client);
	mlx_mouse_hook(client->windows, mouse_handle, client);
	mlx_expose_hook(client->windows, expose_handler, client);
	mlx_loop(client->display);
	return (0);
}
