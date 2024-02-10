/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:36:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/10 17:56:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./fdf.h"

void	ft_put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

// TODO: Read about Bresenham's line algorithm
int	draw_line(t_line *l)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	if (!l->img)
		return (ft_printf(2, "E: No pointer to image.\n"), 1);
	if ((l->x_s > DEF_SCRN_X || l->y_s > DEF_SCRN_Y)
		|| (l->x_e > DEF_SCRN_X || l->y_e > DEF_SCRN_Y))
		return (ft_printf(2, "E: Invalid coordinates.\n"), 1);
	dx = abs(l->x_e - l->x_s);
	dy = -abs(l->y_e - l->y_s);
	err = dx + dy;
	while (1)
	{
		ft_put_pixel(l->img, l->x_s, l->y_s, l->color);
		if (l->x_s == l->x_e && l->y_s == l->y_e)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			l->x_s += l->sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			l->y_s += l->sy;
		}
	}
	return (0);
}
