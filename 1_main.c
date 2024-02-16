/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:18:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/16 19:17:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"

int	terminate(t_fdf *fdf)
{
	clear_all(fdf);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	input_check(argc, argv);
	check_file(argv);
	start_mlx(fdf);
	parse_file(fdf, argv);
	fdf->matrix = get_matrix(fdf);
	place_points(fdf);
	connect_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 1, 1);
	hook_init(fdf);
	mlx_loop(fdf->mlx);
	clear_all(fdf);
	return (0);
}
