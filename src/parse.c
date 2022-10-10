/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:07 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/10 15:44:03 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "libft.h"

static int	get_argss(char *str)
{
	if (!str)
		return (0);
	return (atoi(str));
}

int	parserr(char *str, ...)
{
	va_list	args;
	int		width;
	int		temp;
	int		heigth;

	va_start(args, str);
	temp = get_argss(va_arg(args, char *));
	if (!temp)
		heigth = get_argss(va_arg(args, char *));
	width = temp;
	if (ft_strncmp(str, "mandelbrot", sizeof(str)) == 0)
		program_init(width, heigth, MANDELBROT);
	if (ft_strncmp(str, "julia", sizeof(str)) == 0)
		program_init(width, heigth, JULIA);
	va_end(args);
	return (0);
}
