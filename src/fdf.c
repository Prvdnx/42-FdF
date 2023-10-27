
#include "../inc/fdf.h"

int main(int argc, char *arg[])
{
    t_fdf *fdf;

    if (argc < 2)
    {
        ft_putstr("no file to read\n");
    }
    else if (argc > 2)
    {
        ft_putstr("too many files\n");
    }
    else if (argc == 2)
    {
        fdf = (t_fdf*)malloc(sizeof(t_fdf));
        
        if (ft_read_2(arg[1], fdf) == -1)
        {
            ft_putstr("error file");
            exit(1);
        }
        read_file(arg[1], fdf);
        test_draw(fdf);
    }

    return (0);
}
