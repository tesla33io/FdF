/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:08:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/08 21:35:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "./fdf.h"

int	terminate(t_fdf *fdf)
{
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_loop_end(fdf->mlx);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
	exit (0);
	return (0);
}

void	hook_init(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_WINDOWCLOSE, 1L << 17, terminate, fdf);
	mlx_hook(fdf->win, ON_KEYUP, 1L << 1, key_up_hook, fdf);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_fdf	*fdf;

	fdf = malloc(1 * sizeof(t_fdf));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, DEF_SCRN_X, DEF_SCRN_Y, W_NAME);
	fdf->mlx = mlx;
	fdf->win = mlx_win;
	hook_init(fdf);
	mlx_loop(mlx);
	free(fdf);
	return (0);
}
