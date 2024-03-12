#include "figure.h"

void Figure::move(float alpha, QPainter* painter)
{
    _dx=_halflen*cos(alpha);
    _dy=_halflen*sin(alpha);
    draw(painter);
}

void Line::draw(QPainter* painter)
{
    painter->drawLine(_x+_dx, _y+_dy, _x-_dx,_y-_dy);
}

void Rect::draw(QPainter* painter)
{
    painter->drawLine(_x+_dx, _y+_dy, _x+_dy, _y-_dx);
    painter->drawLine(_x+_dy, _y-_dx, _x-_dx, _y-_dy);
    painter->drawLine(_x-_dx, _y-_dy, _x-_dy, _y+_dx);
    painter->drawLine(_x-_dy, _y+_dx, _x+_dx, _y+_dy);
}
