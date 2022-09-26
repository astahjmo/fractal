/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:55:14 by astaroth          #+#    #+#             */
/*   Updated: 2022/09/26 17:43:38 by astaroth         ###   ########.fr       */
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

	start_mandel(&data->img, WINDOW_WIDTH,WINDOW_HEIGHT);
	mlx_put_image_to_window(data->display, data->windows, data->img.mlx_image, 0, 0);
	return (0);
}


int	handle_no_event(void *data)
{
	printf("%p\n",data);
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}
