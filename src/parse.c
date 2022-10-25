/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/25 20:05:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <stdio.h>

static int	check_parms(char *re, char*im)
{
	int	len;

	len = ft_strlen(re);
	while (len != 0)
	{
		if (!ft_isdigit(*re) | !ft_strnstr("+-.", re, len))
			break ;
		re++;
		len--;
	}
	len = ft_strlen(im);
	while (len != 0)
	{
		if (ft_isdigit(*re) || ft_strnstr("+-.", re, len))
			return (0);
		re++;
		len--;
	}
	return (1);
}

int	parser(char *str, char *re, char *im)
{
	if (ft_strncmp("mandelbrot", str, ft_strlen("mandelbrot")) == 0
		&& re == NULL && im == NULL)
		program_init(MANDELBROT, 0, 0);
	else if (ft_strncmp("julia", str, ft_strlen("julia")) == 0
		&& re != NULL && im != NULL && check_parms(re, im) == 0)
		program_init(JULIA, ft_atof(re), ft_atof(im));
	else
	{
		ft_putstr_fd("Wrong usage.\nExamples:\n", 1);
		ft_putstr_fd(EX_JULIA, 1);
		ft_putstr_fd(EX_MANDEL, 1);
	}
	return (0);
}
