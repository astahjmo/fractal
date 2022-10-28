/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:45 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/28 03:58:27 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <mlx.h>
#include <stdlib.h>

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

void	print_wrong_usage(void)
{
	ft_putstr_fd("Wrong usage.\nExamples:\n", 1);
	ft_putstr_fd(EX_JULIA, 1);
	ft_putstr_fd(EX_MANDEL, 1);
	exit(0);
}

void	exit_with_error(char *err, int level, t_data *data)
{
	ft_putstr_fd(err, 1);
	if (level >= 5)
	{
		mlx_destroy_window(data->display, data->windows);
		mlx_destroy_image(data->display, data->fractal->img->mlx_image);
	}
	if (level >= 4)
		free(data->fractal->img);
	if (level >= 3)
		free(data->fractal);
	if (level >= 2)
		free(data->display);
	if (level >= 1)
		free(data);
	exit(0);
}
