/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:26:01 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/24 22:26:33 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *nptr)
{
	int		is_neg;
	double	result;
	double	power;

	while (*nptr == ' ' || *nptr == '\e' || *nptr == '\t')
		nptr++;
	is_neg = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_neg = -1;
	result = 0.0;
	while (ft_isdigit(*nptr))
		result = (result * 10.0) + (*nptr++ - '0');
	if (*nptr++ != '.')
		return (is_neg * result);
	power = 1.0;
	while (ft_isdigit(*nptr))
	{
		result = (result * 10.0) + (*nptr++ - '0');
		power *= 10.0;
	}
	return (is_neg * result / power);
}
