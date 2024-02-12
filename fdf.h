/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:19:04 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/12 16:25:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1280
# define HEIGHT 720

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

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17,
	ON_WIN_LEAVE = 8,
	ON_WIN_ENTER = 7
}

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
}

#endif