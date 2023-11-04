/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:55 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/03 23:15:02 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_gnlstrlen(char *string)
{
	int	count;

	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_gnlstrdup(char *string)
{
	int		i;
	int		size;
	char	*duplicate;

	i = 0;
	size = ft_gnlstrlen(string);
	duplicate = malloc(sizeof(char) * (size + 1));
	if (!duplicate)
		return (0);
	while (string[i])
	{
		duplicate[i] = string[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	line[7000000];
	int		b;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	i = 0;
	b = read(fd, &buffer, BUFFER_SIZE);
	while (b > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, BUFFER_SIZE);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_gnlstrdup(line));
}*/

int	get_next_line(const int fd, char **line)
{
	char	buffer;
	char	*str;
	int		b;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
		
	i = 0;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (-1);
	b = read(fd, &buffer, BUFFER_SIZE);
	while (b > 0)
	{
		str[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, BUFFER_SIZE);
	}
	str[i] = '\0';
	if (b <= 0 && i == 0)
	{
		free(str);
		return (0);
	}
	*line = str;
	if (ft_strlen(*line) > 0)
	return (1);
	else
	return (0);
}
	// return (ft_strlen(*line) > 0 ? 1 : 0);
