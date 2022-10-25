/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:36 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/26 00:56:58 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		parser(argv[1], NULL, NULL);
	else if (argc == 4)
		parser(argv[1], argv[2], argv[3]);
	else
	{
		ft_putstr_fd("Wrong usage.\nExamples:\n", 1);
		ft_putstr_fd(EX_JULIA, 1);
		ft_putstr_fd(EX_MANDEL, 1);
	}
	return (0);
}
