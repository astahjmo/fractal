/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:37:43 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/10 16:21:00 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

#include <X11/keysym.h>
#include <X11/X.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "./libft.h"
#include <stdarg.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MLX_ERROR 1

enum e_set{MANDELBROT, JULIA};

typedef struct s_image
{
  void *mlx_image;
  char *addr;
  int bpp;
  int line_len;
  int endian;
  int width;
  int height;
} t_image;

typedef struct s_cam
{
	int depht;
	double re;
	double im;
} t_cam;

typedef struct s_fractal
{
	enum e_set set;
	double	x;
	double	y;
	t_cam *cam;
	t_image *img;

} t_fractal;

typedef struct s_data
{
  void *display;
  void *windows;
  t_fractal *fractal;
} t_data;

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

int		ft_isascii(int n);
int		ft_toupper(int c);
char	*ft_itoa(int n);
char	*ft_ithex(unsigned int n);
char	*ft_ubase(unsigned long n, unsigned long base);
char	*ft_strchr(const char *str, int find);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *str, ...);
int		parser(const char *s, va_list ap);
int		fmt_to_decimal(int nbr);
int		fmt_to_udecimal(unsigned int nbr);
int		fmt_to_char(char s);
int		fmt_to_string(char *s);
int		fmt_to_hex(unsigned int nb, int is_upper);
int		fmt_to_pointer(void *pointer);
int	encoder_argb(int r, int g, int b);
int	render_mandelbrot(t_image *img);
void	img_pix_put(t_image *img, int x, int y, int color);
int start_mandel(t_image *img, int win_wid, int win_hei);
int	handle_keyrelease(int keysym, void *data);
int	handle_keypress(int keysym, t_data *data);
int	render(t_data *data);
int	handle_no_event(void *data);
int	handle_mouse(t_data *data);
int	parserr(char *str, ...);
int	program_init(int width, int height, enum e_set set);

#endif
