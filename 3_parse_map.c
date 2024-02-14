/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:37:41 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/14 17:07:07 by astavrop         ###   ########.fr       */
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

void	parse_file(t_fdf *fdf, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	fdf->rows = count_lines(argv[1]);
	i = 0;
	fdf->map = malloc(fdf->rows * sizeof(char *));
	line = get_next_line(fd);
	fdf->cols = count_cols(line, ' ');
	if (!line)
		error_exit("Can't parse the line.", 1);
	while (line)
	{
		fdf->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

t_dot	*parse_row(t_fdf *fdf, int index)
{
	t_dot	*dots;
	char	**s;
	int		i;

	dots = malloc(fdf->cols * sizeof(t_dot));
	s = ft_split(fdf->map[index], ' ');
	if (!dots)
		return (NULL);
	i = 0;
	while (i < fdf->cols)
	{
		dots[i].z = atoi(s[i]);
		dots[i].x = START_X + i * STEP;
		dots[i].y = START_Y + index * STEP;
		i++;
	}
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (dots);
}

t_dot	**get_matrix(t_fdf *fdf)
{
	t_dot	**matrix;
	int		i;

	i = 0;
	matrix = malloc(fdf->rows * sizeof(t_dot *));
	if (!matrix)
		error_exit("memory allocation failed during matrix generation.", 1);
	while (i < fdf->rows)
	{
		matrix[i] = parse_row(fdf, i);
		i++;
	}
	for (int a = 0; a < fdf->rows; a++)
	{
		for (int b = 0; b <fdf->cols; b++)
		{
			ft_printf(1, "[%i,%i,%i] ", matrix[a][b].x, matrix[a][b].y, matrix[a][b].z);
		}
		ft_printf(1, "\n");
	}
	return (matrix);
}

/**
 * for (int a = 0; a < fdf->rows; a++)
 * 	{
 * 		for (int b = 0; b <fdf->cols; b++)
 * 		{
 * 			ft_printf(1, "[%i] ", matrix[a][b].z);
 * 		}
 * 		ft_printf(1, "\n");
 * 	}
 */
