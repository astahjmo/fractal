/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:45 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/26 16:52:28 by johmatos         ###   ########.fr       */
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

void	print_wrong_usage(void)
{
	ft_putstr_fd("Wrong usage.\nExamples:\n", 1);
	ft_putstr_fd(EX_JULIA, 1);
	ft_putstr_fd(EX_MANDEL, 1);
	exit(0);
}
