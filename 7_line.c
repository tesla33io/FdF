/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:54:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/13 21:01:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

void	ft_put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	update_pos(int *err, int dx, int dy, int *coords)
{
	int	e2;
	int	sx;
	int	sy;

	if (coords[0] < coords[2])
		sx = 1;
	else
		sx = -1;
	if (coords[1] < coords[3])
		sy = 1;
	else
		sy = -1;
	e2 = 2 * *err;
	if (e2 >= dy)
	{
		*err += dy;
		coords[0] += sx;
	}
	if (e2 <= dx)
	{
		*err += dx;
		coords[1] += sy;
	}
}

/**
 * @brief Draws a line between two points on an image.
 *
 * This function draws a line from the starting point (`coords[0]`,
 * `coords[1]`) to the ending point (`coords[2]`, `coords[3]`) on
 * the provided image (`img`). It uses Bresenham's line algorithm
 * for efficient line drawing.
 *
 * @note The function performs input validation:
 *   - Checks if the image pointer (`img`) is valid.
 *   - Ensures starting and ending coordinates are within the image
 * boundaries defined by `WIDTH` and `DEF_HEIGHT`.
 *
 * @param img: Pointer to the image data buffer.
 * @param coords: Array of four integers representing the line coordinates:
 *   - `coords[0]`: X-coordinate of the starting point.
 *   - `coords[1]`: Y-coordinate of the starting point.
 *   - `coords[2]`: X-coordinate of the ending point.
 *   - `coords[3]`: Y-coordinate of the ending point.
 * @param color: Color of the line.
 *
 * @retval 0 on success, 1 on error.
 *   - Error conditions:
 *     - Invalid image pointer.
 *     - Invalid coordinates outside image boundaries.
 *
 * @details This function relies on an internal helper function `update_pos`
 * to handle efficient movement along the line path based on Bresenham's
 * algorithm. The details of this algorithm can be found in relevant
 * literature or references.
 */
int	draw_line(t_img *img, int coords[4], int color)
{
	int		dx;
	int		dy;
	int		err;

	if (!img || !img->addr)
		return (ft_printf(2, "E: Invalid image.\n"), 1);
	if ((coords[0] > WIDTH || coords[1] > HEIGHT)
		|| (coords[2] > WIDTH || coords[3] > HEIGHT))
		return (ft_printf(2, "E: Invalid coordinates (%d %d %d %d).\n",
				coords[0], coords[1], coords[2], coords[3]), 1);
	dx = abs(coords[2] - coords[0]);
	dy = -abs(coords[3] - coords[1]);
	err = dx + dy;
	while (1)
	{
		ft_put_pixel(img, coords[0], coords[1], color);
		if (coords[0] == coords[2] && coords[1] == coords[3])
			break ;
		update_pos(&err, dx, dy, coords);
	}
	return (0);
}