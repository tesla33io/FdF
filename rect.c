/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:26:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 19:36:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./fdf.h"

/**
 * @brief  xp = ((coords[0] - VP1_X) * (VP2_X - VP1_X) * D) /
 * ((coords[0] - VP1_X) + D);
 * @note   
 * @param  *xt: 
 * @param  *yt: 
 * @param  *xb: 
 * @param  *yb: 
 * @retval 
 */
int	*calc_p(int coords[4])
{
	int	*p_coords;

	p_coords = malloc(4 * sizeof(int));
	if (p_coords)
	{
		p_coords[0] = ((coords[0] - VP1_X) * (VP2_X - VP1_X) * D)
			/ ((coords[0] - VP1_X) + D);
		p_coords[1] = ((coords[1] - VP1_Y) * (VP2_Y - VP1_Y) * D)
			/ ((coords[1] - VP1_Y) + D);
		p_coords[2] = ((coords[2] - VP1_X) * (VP2_X - VP1_X) * D)
			/ ((coords[2] - VP1_X) + D);
		p_coords[3] = ((coords[3] - VP1_Y) * (VP2_Y - VP1_Y) * D)
			/ ((coords[3] - VP1_Y) + D);
	}
	return (p_coords);
}

int	draw_rect(t_img *img, int coords[4], int color)
{
	int	ret;

	ret = 0;
	ret += draw_line(img, (int []){coords[0], coords[1],
				coords[2], coords[1]}, color);
	ret += draw_line(img, (int []){coords[0], coords[1],
				coords[0], coords[3]}, color);
	ret += draw_line(img, (int []){coords[2], coords[1],
				coords[2], coords[3]}, color);
	ret += draw_line(img, (int []){coords[0], coords[3],
				coords[2], coords[3]}, color);
	return (!(ret == 0));
}

int	draw_rect_p(t_img *img, int coords[6], int a, int color)
{
	int	xt;
	int	yt;
	int	xb;
	int	yb;
	int	ret;

	ret = 0;
	xt = coords[0] * cos(a) + coords[1] * cos(a + 2) + coords[2] * cos(a - 2);
	yt = coords[3] * sin(a) + coords[4] * sin(a + 2) + coords[5] * sin(a - 2);
	xb = coords[3] * cos(a) + coords[4] * cos(a + 2) + coords[5] * cos(a - 2);
	yb = coords[0] * sin(a) + coords[1] * sin(a + 2) + coords[2] * sin(a - 2);
	ft_printf(1, "Coords + p {%d %d %d %d}\n", xt, yt, xb, yb);
	ret += draw_line(img, (int []){xt, yt, xb, yt}, color);
	ret += draw_line(img, (int []){xb, yt, xb, yb}, color);
	ret += draw_line(img, (int []){xb, yb, xt, yb}, color);
	ret += draw_line(img, (int []){xt, yb, xt, yt}, color);

	return (ret);
}
