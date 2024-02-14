/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:26:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/14 22:14:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include "colors.h"

void	print_usage(void)
{
	ft_printf(2, "🤨 "RED"Looks like you have typed something wrong..."R"\n");
	ft_printf(2, GREEN"Try:\t" YELLOW "./fdf "CYAN"*.fdf"R"\n");
	exit (1);
}

void	error_exit(char *msg, int code)
{
	ft_printf(2, RED"Error: %s"R"\n", msg);
	exit (code);
}

int	count_lines(char *fn)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(fn, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

int	count_cols(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
