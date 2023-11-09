/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:55 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/09 09:22:25 by ookamonu         ###   ########.fr       */
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

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return NULL;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

int ft_check(const int fd, char *buffer, char *result[fd])
{
    int i;
    char *temp;
    int ret = 0;

    while (ft_strchr(buffer, '\n') == NULL && (i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[i] = '\0';
        temp = result[fd];
        result[fd] = ft_strjoin(temp, buffer);
        ft_strdel(&temp);
        ft_strdel(&buffer);
        if (i == -1)
        {
            ret = -1;
            break;
        }
        ret = 1;
        break;
    }
    return (ret);
}

int	get_next_line(const int fd, char **line)
{
    char		*buffer;
    static char	*result[BUFFER_SIZE + 1];
    char		*leak;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, result[BUFFER_SIZE], 0) != 0)
        return (-1);
    if (result[fd] == NULL)
        result[fd] = ft_strnew(1);
    buffer = ft_strnew(BUFFER_SIZE);
    if (ft_check(fd, buffer, result) == -1)
        return (-1);
    char *temp = ft_strchr(result[fd], '\n');
    if (temp != NULL)
    {
        *line = ft_substr(result[fd], 0, temp - result[fd]);
        leak = result[fd];
        result[fd] = ft_strdup(temp + 1);
        ft_strdel(&leak);
        return (1);
    }
    *line = ft_strdup(result[fd]);
    ft_strdel(&result[fd]);
    ft_strdel(&temp);
    if (ft_strlen(*line) > 0)
        return (1);
    else
        return (0);
}
