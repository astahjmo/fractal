/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:15 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/25 06:59:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	exit_program(t_data *data)
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
