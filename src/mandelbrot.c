/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:11:41 by astaroth          #+#    #+#             */
/*   Updated: 2022/09/29 18:28:14 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_color get_color(int n, t_color color)
{

	double t;

	t = (double)n / (double)180;
	color.r = (int)(9*(1-t)*t*t*t*255);
	color.g = (int)(15*(1-t)*(1-t)*t*t*255);
	color.b =  (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);
	return (color);
}

int plot_mandel(int loopx, int loopy, double re, double im, t_image *img)
{
	int n;
	double z;
	double c;
	double temp;
	t_color color;

	z = 0;
	c = 0;
	n = 0;
	while (n < 180)
	{
		temp = z;
		z = (pow(z, 2) - pow(c, 2) + re);
		c = (2 * temp * c) + im;
		if (pow(z, 2) + pow(c,2) > 2)
		{
			color = get_color(n, color);
			img_pix_put(img,
			   loopx,
			   loopy,
			   encoder_argb(color.r, color.g, color.b));
		}
		n++;
	}
	return (0);
}

int start_mandel(t_image *img, int win_wid, int win_hei)
{
	int x;
	int y;
	double re;
	double im;

	x = 0;
	y = 0;
	while (y < win_hei)
	{
		while (x < win_wid)
		{
			re = set.re_min + ((x * (set.re_max - set.re_min )) / 800);
			im = set.im_max - ((y * (set.im_max - set.im_min )) / 600);
			plot_mandel(x,y,re,im,img);
			x++;
		}
		x= 0;
		y++;
	}
	return (0);
}
