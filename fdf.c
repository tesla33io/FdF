/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:08:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 21:38:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
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
	t_fdf	*fdf;
	t_img	img;
	t_rect	*main_r;

	fdf = malloc(1 * sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCRN_X, SCRN_Y, W_NAME);
	img.img = mlx_new_image(fdf->mlx, SCRN_X, SCRN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_l, &img.endian);
	main_r = draw_rect_p(&img, (int [4][2]){{SPX, SPY}, {SPX + W, SPY},
	{SPX + W, SPY + H}, {SPX, SPY + H}}, 120, 0xFFFFFFFF);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, 10, 10);
	hook_init(fdf);
	mlx_loop(fdf->mlx);
	free(main_r);
	free(fdf);
	return (0);
}
