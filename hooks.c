/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:18:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/09 11:50:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "./key_codes.h"

int	key_up_hook(int k, t_fdf *fdf)
{
	if (k == KEY_ESCAPE)
		terminate(fdf);
	return (0);
}
