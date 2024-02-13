/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:50:40 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/13 21:20:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

void	place_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			// draw_line(&fdf->img,
			// 	(int [4]){fdf->matrix[i][j].x, fdf->matrix[i][j].x,
			// 	fdf->matrix[i][j].x + STEP, fdf->matrix[i][j].y + STEP},
			// 	0x00FF0000);
			ft_put_pixel(&fdf->img, fdf->matrix[i][j].x * STEP,
				fdf->matrix[i][j].y * STEP,
				0x00FF0000);
			j++;
		}
		i++;
	}
}
