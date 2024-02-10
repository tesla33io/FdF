/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/10 17:34:25 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "./fdf.h"

/**
 * Convert color values to TRGB representation
 * 
 * @param t	transparency
 * @param r	red component
 * @param g	green component
 * @param b	blue component
 * 
 * @return TRGB Color (0xTTRRGGBB)
 */
int	create_trgb(
	unsigned char t,
	unsigned char r,
	unsigned char g,
	unsigned char b
	)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/**
 * This function takes an integer as input and returns its absolute value.
 * If the input number is negative, it returns the negation of that number;
 * otherwise, it returns the number itself. 
 * 
 * @param num	number
 * 
 * @return absolute value of num.
 */
int	abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

/**
 * Initializes a line structure with the given start and end coordinates.
 * 
 * Allocates memory for a new t_line structure, initializes its members
 * with the provided coordinates,
 * and determines the slope direction (sx and sy) based on the start and
 * end points.
 * 
 * @param xs    The x-coordinate of the start point.
 * @param ys    The y-coordinate of the start point.
 * @param xe    The x-coordinate of the end point.
 * @param ye    The y-coordinate of the end point.
 * 
 * @return      A pointer to the newly initialized t_line structure.
 */
t_line	*line_init(int xs, int ys, int xe, int ye)
{
	t_line	*l;

	l = malloc(1 * sizeof(t_line));
	l->x_s = xs;
	l->y_s = ys;
	l->x_e = xe;
	l->y_e = ye;
	if (xs < xe)
		l->sx = 1;
	else
		l->sx = -1;
	if (ys < ye)
		l->sy = 1;
	else
		l->sy = -1;
	return (l);
}
