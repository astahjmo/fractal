/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/26 17:50:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int	check_args(char *re, char *im)
{
	int	len;

	len = ft_strlen(re);
	if ((*re == '\0') || (len == 1 && ft_strchr("+-.", *re)))
		return (1);
	len = ft_strlen(im);
	if ((*im == '\0') || (len == 1 && ft_strchr("+-.", *im)))
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
	double	cre;
	double	cim;

	if (ft_strncmp("mandelbrot", str, ft_strlen("mandelbrot")) == 0
		&& re == NULL && im == NULL)
		program_init(MANDELBROT, 0, 0);
	else if (ft_strncmp("julia", str, ft_strlen("julia")) == 0
		&& re != NULL && im != NULL && check_args(re, im) == 0)
	{
		cre = ft_atof(re);
		cim = ft_atof(im);
		if ((cre > 2.0 || cre < -2.0) || (cim > 2.0 || cim < -2.0))
			print_wrong_usage();
		program_init(JULIA, ft_atof(re), ft_atof(im));
	}
	else
		print_wrong_usage();
	return (0);
}
