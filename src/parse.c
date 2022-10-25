/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/25 11:14:40 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	parser(char *str, char *re, char *im)
{
	if (ft_strncmp(str, "mandelbrot", ft_strlen(str)) == 0
		&& re == NULL && im == NULL)
		program_init(MANDELBROT, 0, 0);
	else if (ft_strncmp(str, "julia", ft_strlen(str)) == 0
		&& re != NULL && im != NULL)
		program_init(JULIA, ft_atof(re), ft_atof(im));
	else
	{
		ft_putstr_fd("Wrong usage.\nExamples:\n", 1);
		ft_putstr_fd(EX_JULIA, 1);
		ft_putstr_fd(EX_MANDEL, 1);
	}
	return (0);
}
