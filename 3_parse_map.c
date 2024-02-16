/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:37:41 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/16 19:53:42 by astavrop         ###   ########.fr       */
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
	fdf->map = malloc((fdf->rows + 1) * sizeof(char *));
	if (!fdf->map)
		ft_printf(2, "[parse_fill:fdf->map]:MAE:\n");
	line = get_next_line(fd);
	if (!line)
		error_exit("Can't parse the line.", 1);
	while (line)
	{
		fdf->map[i] = ft_strdup(line);
		if (!fdf->map[i])
			ft_printf(2, "[parse_file:fdf->map[i]]:MAE:\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	fdf->map[i] = NULL;
	free(line);
	close(fd);
}

t_dot	**parse_row(t_fdf *fdf, int index)
{
	t_dot	**dots;
	char	**s;
	int		i;

	s = ft_split(fdf->map[index], ' ');
	if (!s)
		return (NULL);
	fdf->row_len[index] = count_cols(s);
	dots = malloc((1 + fdf->row_len[index]) * sizeof(t_dot *));
	if (!dots)
		return (NULL);
	i = 0;
	while (i < fdf->row_len[index])
	{
		dots[i] = malloc(sizeof(t_dot));
		dots[i]->z = atoi(s[i]);
		dots[i]->x = fdf->x_start + index * fdf->step;
		dots[i]->y = fdf->y_start - i * fdf->step;
		i++;
	}
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (dots);
}

t_dot	***get_matrix(t_fdf *fdf)
{
	t_dot	***matrix;
	int		i;

	i = 0;
	matrix = malloc((1 + fdf->rows) * sizeof(t_dot **));
	fdf->row_len = malloc(fdf->rows * sizeof(int));
	if (!matrix)
		error_exit("memory allocation failed during matrix generation.", 1);
	while (i < fdf->rows)
	{
		matrix[i] = parse_row(fdf, i);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

/**
 * ft_printf(1, "rows: %d\n", fdf->rows);
	for (int a = 0; a < fdf->rows; a++)
	{
		ft_printf(1, "<%d> ", fdf->row_len[a]);
		for (int b = 0; b < fdf->row_len[a]; b++)
		{
			ft_printf(1, "[%i,%i,%i] ", matrix[a][b]->x,
				matrix[a][b]->y, matrix[a][b]->z);
		}
		ft_printf(1, "\n");
	}
	ft_printf(1, "\n\n-*-*-*-*-*-*-*-*-*-*-*-\n\n");
 */
