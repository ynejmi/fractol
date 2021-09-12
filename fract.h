#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "key_macos.h"
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_mlx {
	void		*image;
	char		*data_addr;
	int			linesize;
	int			bitsperpixel;
	int			color;
	int			endian;
}				t_mlx;

typedef struct s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct s_color
{
	double		a;
	double		b;
}				t_color;

typedef struct s_fract
{
	t_mlx		*img;
	void		*window;
	void		*mlx;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	k;
	t_complex	factor;
	int			max_i;
}				t_fract;

void		options_print(void);
void		putpixel(t_mlx *img, int x, int y);
t_fract		*init_fract(void *mlx, char *set);
t_mlx		*init_img(void *mlx);
void		drawfract(t_fract *fract);
void		choose_color(t_fract *fract);
void		itoco(int i, t_fract *fract);
t_complex	init_complex(double a, double b);
double		interpolate(double end, double start, double interpolation);
int			scrollwheel(int keycode, int x, int y, t_fract *fract);
int			key_press(int keycode, t_fract *fract);
int			ft_exit(void);
int			ft_isset(char *str, int rec);
#endif
