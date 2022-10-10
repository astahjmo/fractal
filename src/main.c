/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:39:12 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/10 15:36:07 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		parserr(argv[1]);
	else if (argc == 4)
		parserr(argv[1], argv[2], argv[3]);
	else
		ft_printf("Wrong usage");
}
