/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   97_more_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:29:38 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/17 15:27:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "get_next_line.h"

int	get_col_len(char *str_col)
{
	char	**s;
	int		len;
	int		i;

	s = ft_split(str_col, ' ');
	if (!s)
		return (-1);
	len = count_cols(s);
	i = -1;
	while (++i < len)
		free(s[i]);
	free(s);
	return (len);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
