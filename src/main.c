/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:36 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/27 18:54:01 by johmatos         ###   ########.fr       */
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
		print_wrong_usage();
	return (0);
}
