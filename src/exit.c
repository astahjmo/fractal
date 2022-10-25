/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:15:33 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 21:15:13 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	exit_program(t_data *data)
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
