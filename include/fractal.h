/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:37:43 by astaroth          #+#    #+#             */
/*   Updated: 2022/09/26 15:37:34 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

#include <X11/keysym.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "../lib/libft.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MLX_ERROR 1

typedef struct s_image
{
  void *mlx_image;
  char *addr;
  int bpp;
  int line_len;
  int endian;
} t_image;

typedef struct s_data
{
  void *display;
  void *windows;
  t_image img;
} t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_mandel
{
	double	x;
	double	y;
	double	depht;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;

} t_mandel;

int	program_init(int width, int height);
int	encoder_argb(int r, int g, int b);
int	render_mandelbrot(t_image *img);
void	img_pix_put(t_image *img, int x, int y, int color);
int start_mandel(t_image *img, int win_wid, int win_hei);
#endif
