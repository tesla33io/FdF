/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:39:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/17 13:40:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

void	start_mlx(t_fdf *fdf, char *wname)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, wname);
	fdf->angle = 120;
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.line_length, &fdf->img.endian);
	fdf->img.width = WIDTH;
	fdf->img.height = HEIGHT;
	fdf->x_start = 350;
	fdf->y_start = 200;
	fdf->step = 10;
}

void	hook_init(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_WINDOWCLOSE, 1L << 17, terminate, fdf);
	mlx_hook(fdf->win, ON_KEYUP, 1L << 1, key_up_hook, fdf);
}
