/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/27 17:20:54 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int	string_loop(char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (!ft_isdigit(*str) && *str != '\0')
		return (1);
	return (0);
}

static int	check_start(char c)
{
	return (c == '-' || c == '+' || ft_isdigit(c));
}

static int	check_args(char *re, char *im)
{
	if (!re || !im)
		return (1);
	if (!check_start(*re) || !check_start(*im))
		return (1);
	if (string_loop(++re) == 1 || string_loop(++im) == 1)
		return (1);
	return (0);
}

int	parser(char *str, char *re, char *im)
{
	if (ft_strncmp("mandelbrot", str, ft_strlen("mandelbrot")) == 0
		&& re == NULL && im == NULL)
		program_init(MANDELBROT, 0, 0);
	else if (ft_strncmp("julia", str, ft_strlen("julia")) == 0
		&& re != NULL && im != NULL && check_args(re, im) == 0)
		program_init(JULIA, ft_atof(re), ft_atof(im));
	else
		print_wrong_usage();
	return (0);
}
