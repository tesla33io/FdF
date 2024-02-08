/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:18:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/08 21:37:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "./key_codes.h"

void	key_up_hook(int k, t_fdf *fdf)
{
	if (k == KEY_ESCAPE)
		terminate(fdf);
}
