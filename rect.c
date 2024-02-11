/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:26:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 21:12:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./fdf.h"

int	*calculate_coords(int coords[4][2], int a)
{
	int	*iso_coords;

	iso_coords = malloc(8 * sizeof(int));
	if (!iso_coords)
		return (NULL);
	iso_coords[0] = coords[0][0] * cos(a) + coords[0][1] * cos(a + 2)
		+ Z * cos(a - 2);
	iso_coords[1] = coords[0][0] * sin(a) + coords[0][1] * sin(a + 2)
		+ Z * sin(a - 2);
	iso_coords[2] = coords[1][0] * cos(a) + coords[1][1] * cos(a + 2)
		+ Z * cos(a - 2);
	iso_coords[3] = coords[1][0] * sin(a) + coords[1][1] * sin(a + 2)
		+ Z * sin(a - 2);
	iso_coords[4] = coords[2][0] * cos(a) + coords[2][1] * cos(a + 2)
		+ Z * cos(a - 2);
	iso_coords[5] = coords[2][0] * sin(a) + coords[2][1] * sin(a + 2)
		+ Z * sin(a - 2);
	iso_coords[6] = coords[3][0] * cos(a) + coords[3][1] * cos(a + 2)
		+ Z * cos(a - 2);
	iso_coords[7] = coords[3][0] * sin(a) + coords[3][1] * sin(a + 2)
		+ Z * sin(a - 2);
	return (iso_coords);
}

int	draw_rect_p(t_img *img, int coords[4][2], int a, int color)
{
	int	*iso_coords;
	int	ret;

	ret = 0;
	iso_coords = calculate_coords(coords, a);
	if (!iso_coords)
		return (1);
	ret += draw_line(img, (int []){iso_coords[0], iso_coords[1],
			iso_coords[2], iso_coords[3]}, color);
	ret += draw_line(img, (int []){iso_coords[2], iso_coords[3],
			iso_coords[4], iso_coords[5]}, color);
	ret += draw_line(img, (int []){iso_coords[4], iso_coords[5],
			iso_coords[6], iso_coords[7]}, color);
	ret += draw_line(img, (int []){iso_coords[6], iso_coords[7],
			iso_coords[0], iso_coords[1]}, color);
	free(iso_coords);
	return (ret);
}
