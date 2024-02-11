/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:26:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 21:37:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./fdf.h"

t_rect	*create_rect(int coords[4][2], int a)
{
	t_rect	*rect;

	rect = malloc(sizeof(t_rect));
	if (!rect)
		return (NULL);
	rect->top[0] = coords[0][0] * cos(a) + coords[0][1] * cos(a + 2)
		+ Z * cos(a - 2);
	rect->top[1] = coords[0][0] * sin(a) + coords[0][1] * sin(a + 2)
		+ Z * sin(a - 2);
	rect->right[0] = coords[1][0] * cos(a) + coords[1][1] * cos(a + 2)
		+ Z * cos(a - 2);
	rect->right[1] = coords[1][0] * sin(a) + coords[1][1] * sin(a + 2)
		+ Z * sin(a - 2);
	rect->bottom[0] = coords[2][0] * cos(a) + coords[2][1] * cos(a + 2)
		+ Z * cos(a - 2);
	rect->bottom[1] = coords[2][0] * sin(a) + coords[2][1] * sin(a + 2)
		+ Z * sin(a - 2);
	rect->left[0] = coords[3][0] * cos(a) + coords[3][1] * cos(a + 2)
		+ Z * cos(a - 2);
	rect->left[1] = coords[3][0] * sin(a) + coords[3][1] * sin(a + 2)
		+ Z * sin(a - 2);
	return (rect);
}

t_rect	*draw_rect_p(t_img *img, int coords[4][2], int a, int color)
{
	t_rect	*rect;
	int		ret;

	ret = 0;
	rect = create_rect(coords, a);
	if (!rect)
		return (NULL);
	ret += draw_line(img, (int []){rect->top[0], rect->top[1],
			rect->right[0], rect->right[1]}, color);
	ret += draw_line(img, (int []){rect->right[0], rect->right[1],
			rect->bottom[0], rect->bottom[1]}, color);
	ret += draw_line(img, (int []){rect->bottom[0], rect->bottom[1],
			rect->left[0], rect->left[1]}, color);
	ret += draw_line(img, (int []){rect->left[0], rect->left[1],
			rect->top[0], rect->top[1]}, color);
	return (rect);
}
