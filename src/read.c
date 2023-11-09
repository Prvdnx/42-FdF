/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:15:59 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/09 00:39:01 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void str_to_mass_num(char **map, t_fdf *fdf)
{
	char    **tmp;
	int     x;
	int     y;

	y = 0;
	fdf->map.structure = (int **)malloc(sizeof(int *) * fdf->map.line);
	while (y < fdf->map.line)
	{
		fdf->map.structure[y] = (int *)malloc(sizeof(int) * fdf->map.elem);
		tmp = ft_split(map[y], ' ');
		free(map[y]);
		x = 0;
		while (x < fdf->map.elem)
		{
			fdf->map.structure[y][x] = atoi(tmp[x]);
			free(tmp[x]);
			x++;
		}
		free(tmp);
		y++;
	}
	free(map);
}

int ft_count_words(char const *s, char c)
{
	int     word;
	int     i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			word++;
		}
	}
	return (word);
}

char *next_step(t_fdf *fdf, char *buf, char *tmp, char *line)
{
	if (!(ft_isdigit(*line) || *line == ',' || *line == 'x' \
	|| *line == ' ' || *line == '\n' || *line == '-'))
	{
		line++;
		return (0);
	}
	if (fdf->map.elem == ft_count_words(line, ' ') || fdf->map.line == 1)
		fdf->map.elem = ft_count_words(line, ' ');
	else
	{
		fdf_putstr("give me valid file");
		exit(0);
	}
	tmp = ft_strjoin(buf, line);
	free(buf);
	free(line);
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	return (buf);
}

void	check(t_fdf *fdf)
{
	if(!fdf->map.elem || fdf->map.error == -1)
	{
		fdf_putstr("error file");
		exit(0);
	}
}

int	read_file(char *argv, t_fdf *fdf)
{
	char *line;
	char *buf;
	char **map;
	char *tmp;

	tmp = NULL;
	fdf->map.line = 0;
	if ((fdf->map.fd = open(argv, O_RDONLY)) < 0)
		fdf->map.error = -1;

	buf = ft_strdup("\0");

	while ((get_next_line(fdf->map.fd, &line) > 0) && ++fdf->map.line)
	{
		//if (fdf->map.elem != number_spaces(line) ?
			//fdf->map.error = -1 : fdf->map.elem);
    	if (fdf->map.elem != number_spaces(line))
        	fdf->map.error = -1;
    	else
        	fdf->map.elem = fdf->map.elem;
		buf = next_step(fdf, buf, tmp, line);
	}

	free(line);
	check(fdf);
	close(fdf->map.fd);
	map = ft_split(buf, '\n');
	free(buf);
	str_to_mass_num(map, fdf);
	close(fdf->map.fd);
	return (0);
}
