/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:39:12 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/17 11:51:38 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		parserr(argv[1], WINDOW_WIDTH, WINDOW_HEIGHT);
	else if (argc == 4)
		parserr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_printf("Wrong usage");
}
