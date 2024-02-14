/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:19:04 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/14 21:49:50 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define NAME "4O4. name not found"
# define WIDTH 720
# define HEIGHT 720

# define STEP 75
# define START_X 200
# define START_Y 500

// # inlcude <stddef.h>
# include "mlx.h"

typedef struct s_dot{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_dot;

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	int		rows;
	int		cols;
	int		angle;
	int		x_start;
	int		y_start;
	int		step;
	char	**map;
	t_dot	**matrix;
	t_dot	**trm;
	void	*mlx;
	void	*win;
	t_img	img;
}				t_fdf;

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17,
	ON_WIN_LEAVE = 8,
	ON_WIN_ENTER = 7
};

enum e_colors
{
	WHITE = 0x00FFFFFF,
	BLACK = 0x00000000,
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
	YELLOW = 0x00FFFF00,
	CYAN = 0x0000FFFF,
	MAGENTA = 0x00FF00FF
};

/* ERROR HANDLING */

void		input_check(int argc, char **argv);
void		check_file(char **argv);
void		error_exit(char *msg, int code);
void		print_usage(void);

/* PARSING */

void		parse_file(t_fdf *fdf, char **argv);
t_dot		**get_matrix(t_fdf *fdf);

/* MLX STUFF */

void		start_mlx(t_fdf *fdf);
void		hook_init(t_fdf *fdf);
int			terminate(t_fdf *fdf);
int			key_up_hook(int k, t_fdf *fdf);

/* LINE UTILS */

void		ft_put_pixel(t_img *data, int x, int y, int color);
int			draw_line(t_img *img, int coords[4], int color);

/* DRAW UTILS */

void		place_points(t_fdf *fdf);
void		connect_points(t_fdf *fdf);

/* UTILS */

int			count_lines(char *fn);
int			count_cols(char *line, char c);

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define KEY_A			97
# define KEY_S			115
# define KEY_W			119
# define KEY_D			100

# define KEY_SPACE		32
# define KEY_ESCAPE		65307

# define KEY_R			114
# define KEY_M			109

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	3

# define LEFT_SHIFT		65505

#endif