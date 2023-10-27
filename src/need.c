
#include "../inc/fdf.h"
#include "math.h"

void drawline_2(t_fdf *fdf, t_con cons)
{
    while (fdf->draw.x1 != fdf->draw.x2 || fdf->draw.y1 != fdf->draw.y2)
    {
        fdf->draw.x = (fdf->draw.x1 + fdf->draw.y1) * fdf->draw.cosxy;;
        fdf->draw.y = (fdf->draw.x1 + fdf->draw.y1) * fdf->draw.sinxy;;
        mlx_pixel_put(fdf->win.mlx_ptr, fdf->win.win_ptr, fdf->draw.x, fdf->draw.y, fdf->draw.color);
        fdf->draw.error2 = fdf->draw.error * 2 - 1;
        if (fdf->draw.error2 > -cons.deltay)
        {
            fdf->draw.error -= cons.deltay;
            fdf->draw.x1 += cons.signx;
        }
        if (fdf->draw.error2 < cons.deltax)
        {
            fdf->draw.error += cons.deltax;
            fdf->draw.y1 += cons.signy;
        }
    }
}

void drawline(t_fdf *fdf)
{
    t_con cons;

    cons.deltax = abs(fdf->draw.x2 - fdf->draw.x1);
    cons.deltay = abs(fdf->draw.y2 - fdf->draw.y1);

    //cons.signx = fdf->draw.x1 < fdf->draw.x2 ? 1 : -1;
    //cons.signy = fdf->draw.y1 < fdf->draw.y2 ? 1 : -1;
    if (fdf->draw.x1 < fdf->draw.x2)
        cons.signx = 1;
    else
        cons.signx = -1;
    if (fdf->draw.y1 < fdf->draw.y2)
        cons.signy = 1;
    else
        cons.signy = -1;
        
    fdf->draw.error = cons.deltax - cons.deltay;
    fdf->draw.x = (fdf->draw.x2 - fdf->draw.y2) * fdf->draw.cosxy;
    fdf->draw.y = (fdf->draw.x2 + fdf->draw.y2) * fdf->draw.sinxy;
    mlx_pixel_put(fdf->win.mlx_ptr, fdf->win.win_ptr,
        fdf->draw.x, fdf->draw.y, fdf->draw.color);
    drawline_2(fdf, cons);
}
