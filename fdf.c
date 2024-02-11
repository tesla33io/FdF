/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:08:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 19:38:16 by astavrop         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_fdf	*fdf;
	t_img	img;

	fdf = malloc(1 * sizeof(t_fdf));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, DEF_SCRN_X, DEF_SCRN_Y, W_NAME);
	fdf->mlx = mlx;
	fdf->win = mlx_win;
	img.img = mlx_new_image(mlx, DEF_SCRN_X, DEF_SCRN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_l, &img.endian);
	draw_rect_p(&img, (int []){34, 23, 12, 567, 345, 456}, 120, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	hook_init(fdf);
	mlx_loop(mlx);
	free(fdf);
	return (0);
}
