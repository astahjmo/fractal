/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:25:07 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/26 16:39:44 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	if (!(ft_isascii(c)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		if (src[i] == (char) c)
			return ((char *) &src[i]);
		i++;
	}
	if (src[i] == c)
		return ((char *) &src[i]);
	return (NULL);
}
