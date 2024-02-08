/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:54:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/08 21:37:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEF_SCRN_X 960
# define DEF_SCRN_Y 540
# define W_NAME "._."

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_WINDOWCLOSE = 17,
	ON_WIN_LEAVE = 8,
	ON_WIN_ENTER = 7
}	t_events;

/* fdf.c */

int		terminate(t_fdf *fdf);

/* HOOKS */

void	key_up_hook(int k, t_fdf *fdf);

#endif
