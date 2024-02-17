/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   98_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:39:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/16 19:44:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	clear_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_matrix(t_fdf *fdf, t_dot ***m)
{
	int	i;
	int	j;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (j < fdf->row_len[i])
		{
			if (m[i][j])
				free(m[i][j]);
			j++;
		}
		if (m[i])
			free(m[i]);
		i++;
	}
	free(m);
}

void	clear_all(t_fdf *fdf)
{
	if (!fdf)
		return ;
	clear_map(fdf->map);
	clear_matrix(fdf, fdf->matrix);
	clear_matrix(fdf, fdf->trm);
	free(fdf->row_len);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_loop_end(fdf->mlx);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
}
