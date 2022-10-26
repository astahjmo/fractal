/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/26 13:56:12 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"
#include <stdio.h>

static int	check_parms(char *re, char*im)
{
	int len;

	len = ft_strlen(re);
	if ((len == 1) && (ft_strchr("+-.", *re)))
		return (1);
	len = ft_strlen(im);
	if ((len == 1) && (ft_strchr("+-.", *im)))
		return (1);
	while (*re)
	{
		if (!ft_isdigit(*re) && !ft_strchr("+-.", *re))
			return (1);
		re++;
	}

	while (*im)
	{
		if (!ft_isdigit(*im) && !ft_strchr("+-.", *im))
			return (1);
		im++;
	}
	return (0);
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
