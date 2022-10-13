/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:38:46 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/13 19:19:22 by astaroth         ###   ########.fr       */
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
