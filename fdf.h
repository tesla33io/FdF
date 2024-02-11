/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:54:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 19:22:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEF_SCRN_X 960
# define DEF_SCRN_Y 540
# define W_NAME "._."
# define D 100
# define VP1_X 100
# define VP1_Y 42
# define VP2_X 400
# define VP2_Y 420

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_line
{
	t_img	*img;
	int		x_s;
	int		y_s;
	int		x_e;
	int		y_e;
	int		sx;
	int		sy;
	int		color;
}	t_line;

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17,
	ON_WIN_LEAVE = 8,
	ON_WIN_ENTER = 7
}	t_events;

/* fdf.c */

int		terminate(t_fdf *fdf);

/* HOOKS */

int		key_up_hook(int k, t_fdf *fdf);

/* LINE */

int		draw_line(t_img *img, int coords[4], int color);

/* RECT */

int		draw_rect(t_img *img, int coords[4], int color);
int		draw_rect_p(t_img *img, int coords[6], int a, int color);

/* UTILS */

int		create_trgb(
			unsigned char t,
			unsigned char r,
			unsigned char g,
			unsigned char b
			);
int		abs(int num);
t_line	*line_init(int xs, int ys, int xe, int ye);

#endif
