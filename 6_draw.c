/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:50:40 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/14 23:01:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

int	rotate_coords(t_dot d, t_fdf *fdf, double fn(double))
{
	return (d.x * fn(fdf->angle) + d.y * fn(fdf->angle + 2)
		+ d.z * fn(fdf->angle - 2));
}

void	place_points(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	fdf->trm = malloc(fdf->rows * sizeof(t_dot *));
	while (i < fdf->rows)
	{
		j = 0;
		fdf->trm[i] = malloc(fdf->row_len[i] * sizeof(t_dot));
		while (j < fdf->row_len[i])
		{
			fdf->trm[i][j].x = rotate_coords(fdf->matrix[i][j], fdf, &cos);
			fdf->trm[i][j].y = rotate_coords(fdf->matrix[i][j], fdf, &sin);
			fdf->trm[i][j].z = 0;
			ft_put_pixel(&fdf->img, fdf->trm[i][j].x,
				fdf->trm[i][j].y, 0xF00FFFFF);
			j++;
		}
		i++;
	}
}

void	connect_points(t_fdf *fdf)
{
	int		i;
	int		j;
	t_dot	**m;

	i = 0;
	m = fdf->trm;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->row_len[i])
		{
			if (j < fdf->row_len[i] - 1)
				draw_line(&fdf->img, (int[4]){m[i][j].x, m[i][j].y,
					m[i][j + 1].x, m[i][j + 1].y}, 0x00FF0000);
			if (i < fdf->row_len[i] - 1)
				draw_line(&fdf->img, (int[4]){m[i][j].x, m[i][j].y,
					m[i + 1][j].x, m[i + 1][j].y}, 0xAAFFAAAA);
			j++;
		}
		i++;
	}
}

/**
 * 
 * fdf->trm[i][j].x = (fdf->matrix[i][j].x - fdf->matrix[i][j].z)
				/ sqrt(2);
			fdf->trm[i][j].y = ((fdf->matrix[i][j].x + (2 * fdf->matrix[i][j].y)
						+ fdf->matrix[i][j].z) / sqrt(6));

			fdf->trm[i][j].x = rotate_coords(fdf->matrix[i][j], fdf, &cos);
			fdf->trm[i][j].y = rotate_coords(fdf->matrix[i][j], fdf, &sin);
*/
