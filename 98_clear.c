/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   98_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:39:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/15 21:04:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

void	dfree(char *msg, void *ptr)
{
	ft_printf(1, "[%s]free ptr: %p\n", msg, ptr);
	free(ptr);
}

void	clear_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		dfree("map loop", map[i]);
		i++;
	}
	dfree("map end", map);
}

void	clear_matrix(t_dot ***m)
{
	int	i;
	int	j;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j])
				dfree("mat loop2", m[i][j]);
			j++;
		}
		if (m[i])
			dfree("mat loop1", m[i]);
		i++;
	}
	dfree("mat end", m);
}

void	clear_all(t_fdf *fdf)
{
	if (!fdf)
		return ;
	clear_map(fdf->map);
	clear_matrix(fdf->matrix);
	clear_matrix(fdf->trm);
	free(fdf->row_len);
	if (fdf->img.img)
		free(fdf->img.img);
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
