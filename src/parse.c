/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:07 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 21:14:58 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "libft.h"

int	parserr(char *str, char *re, char *im)
{
	if (ft_strncmp(str, "mandelbrot", ft_strlen(str)) == 0
		&& re == NULL && im == NULL)
		program_init(MANDELBROT, 0, 0);
	if (ft_strncmp(str, "julia", ft_strlen(str)) == 0
		&& re != NULL && im != NULL)
		program_init(JULIA, ft_atof(re), ft_atof(im));
	else
		ft_printf("Wrong usage.\nExampels:\n%s\n%s\n", EX_JULIA, EX_MANDEL);
	return (0);
}
