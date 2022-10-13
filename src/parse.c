/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:07 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/13 15:24:19 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "libft.h"

int	parserr(char *str, int wid, int hei)
{
	if (ft_strncmp(str, "mandelbrot", sizeof(str)) == 0)
		program_init(wid, hei, MANDELBROT);
	if (ft_strncmp(str, "julia", sizeof(str)) == 0)
		program_init(wid, hei, JULIA);
	return (0);
}
