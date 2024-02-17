/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/14 22:12:28 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "get_next_line.h"

void	input_check(int argc, char **argv)
{
	char	**file;
	int		i;
	int		cmp;

	if (argc != 2)
		print_usage();
	file = ft_split(argv[1], '.');
	if (!file)
		error_exit("memory allocation failed during input check.", 1);
	i = 0;
	while (file[i])
		i++;
	cmp = ft_strncmp(file[i - 1], "fdf", 42);
	i = 0;
	while (file[i])
		free(file[i++]);
	free(file);
	if (cmp != 0)
		print_usage();
}

void	retrieve_line(int fd, char **line)
{
	free(*line);
	*line = get_next_line(fd);
}

void	check_file(char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Can't open your map.", 1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_exit("Can't read from your map.", 1);
	}
	while (line)
		retrieve_line(fd, &line);
	close(fd);
}
