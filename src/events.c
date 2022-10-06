/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:55:14 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/04 15:56:52 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


int	handle_mouse(t_data *data)
{
	printf("Keypress: %p\n", &data->windows);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n on %p", keysym, data);
	return (0);
}
int	render(t_data *data)
{
	if (!data->fractal->img->addr)
		printf("Amem");
	return (0);
}

int	handle_no_event(void *data)
{
	printf("%p\n",data);
	return (0);
}
