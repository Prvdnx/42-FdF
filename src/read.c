
#include "../inc/fdf.h"

int str_to_mass_num(char **map, t_fdf *fdf)
{
    char    **tmp;
    int     x;
    int     y;

    y = 0;
    fdf->map.karta = (int **)malloc(sizeof(int *) * fdf->map.line);
    while (y < fdf->map.line)
    {
        fdf->map.karta[y] = (int *)malloc(sizeof(int) * fdf->map.elem);
        tmp = ft_strsplit(map[y], ' ');
        free(map[y]);
        x = 0;
        while (x < fdf->map.elem)
        {
            fdf->map.karta[y][x] = atoi(tmp[x]);
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
        return 0;
    }
    if (fdf->map.elem == ft_count_words(line, ' ') || fdf->map.line == 1)
        fdf->map.elem = ft_count_words(line, ' ');
    else
    {
        ft_putstr("give me valid file");
        exit(0);
    }
    tmp = ft_strjoin(buf, line);
    free(buf);
    free(line);
    buf = ft_strjoin(tmp, "\n");
    free(tmp);
    return (buf);
}
