
#include "../inc/fdf.h"

void    show_map(t_fdf *fdf)
{
    if (fdf->draw.show == 1)
    {
        fdf->draw.cosxy = 0.8660254;
        fdf->draw.sinxy = 0.5;
        fdf->draw.show = 2;
    }
    else
    {
        fdf->draw.sinxy = 0.525321989;
        fdf->draw.cosxy = 0.525321989;
        fdf->draw.show = 1;
    }
}

void    color(t_fdf *fdf, int key)
{
    if (key == 18)
        fdf->draw.c_color = 0xFF0000;
    if (key == 19)
        fdf->draw.c_color = 0x0000FF;
    if (key == 20)
        fdf->draw.c_color = 0xC0C0C0;
    if (key == 21)
        fdf->draw.c_color = 0xFF8C00;
    if (key == 23)
        fdf->draw.c_color = 0xD2691E;
    if (key == 22)
        fdf->draw.c_color = 0xFFFFFF;
    if (key == 26)
        fdf->draw.c_color = 0x800080;
    if (key == 28)
        fdf->draw.c_color = 0xFFFF00;
    if (key == 25)
        fdf->draw.c_color = 0x00FFFF;
    if (key == 29)
        fdf->draw.c_color = 0x00FF00;
}

void    move(t_fdf *fdf, int key)
{
    if (key == 69)
        fdf->draw.height <= 10 ? fdf->draw.height += 1 : fdf->draw.height;
    if (key == 78)
        fdf->draw.height >= -18 ? fdf->draw.height -= 1 : fdf->draw.height;
    if (key == 35)
        fdf->draw.spase <= 58 ? fdf->draw.spase += 1 : fdf->draw.spase;
    if (key == 46)
        fdf->draw.spase >= 2 ? fdf->draw.spase - 1 : fdf->draw.spase;
    

    if (key == 69)
    {
        if (fdf->draw.height < 10)
            fdf->draw.height += 1;
    }
    if (key == 78)
    {
        if (fdf->draw.height >= -18)
            fdf->draw.height -= 1;
    }
    if (key == 35)
    {
        if (fdf->draw.spase < 58)
            fdf->draw.spase += 1;
    }
    if (key == 46)
    {
        if (fdf->draw.spase > 2)
            fdf->draw.spase -= 1;
    }

/*if (key == 69) {
    if (fdf->draw.height <= 10) {
        fdf->draw.height += 1;
    } else {
        fdf->draw.height = fdf->draw.height;
    }
}
if (key == 78) {
    if (fdf->draw.height >= -18) {
        fdf->draw.height -= 1;
    } else {
        fdf->draw.height = fdf->draw.height;
    }
}
if (key == 35) {
    if (fdf->draw.spase <= 58) {
        fdf->draw.spase += 1;
    } else {
        fdf->draw.spase = fdf->draw.spase;
    }
}
if (key == 46) {
    if (fdf->draw.spase >= 2) {
        fdf->draw.spase -= 1;
    } else {
        fdf->draw.spase = fdf->draw.spase;
    }
}*/
    
    if (key == 126)
        fdf->draw.start_x += 10;
    if (key == 123)
        fdf->draw.start_y += 10;
    if (key == 125)
        fdf->draw.start_x = 10;
    if (key == 124)
        fdf->draw.start_y -= 10;
    if (key == 6)
        show_map(fdf);
    if (key == 4)
        start_value(fdf);
}

int wtrite_key(int key, t_fdf *fdf)
{
    mlx_clear_window(fdf->win.mlx_ptr, fdf->win.win_ptr);
    move(fdf, key);
    color(fdf, key);
    if (key == 53)
        exit(1);
    draw_point(fdf);
    if (key == 48 && fdf->menu.m_menu == 1)
        menu(fdf, key);
    if (key == 48 && fdf->menu.m_menu == 2)
        menu_key(key, fdf);
    return (0);
}

int mouse(int key)
{
    key = 1;
    exit(1);
    return 0;
}
