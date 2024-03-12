#ifndef FIGURE_H
#define FIGURE_H

#include<QtGui>
#include<QPainter>

class Figure
{
protected:
    int _x;
    int _y;
    int _halflen;
    int _dx;
    int _dy;
    int _r;
    virtual void draw(QPainter* painter) = 0;
public:
    Figure(int x, int y, int halflen) : _x(x), _y(y), _halflen(halflen) {}
    void move(float alpha, QPainter* painter);
};

class Line : public Figure
{
protected:
    void draw(QPainter* painter);
public:
    Line(int x,int y,int halflen): Figure(x, y, halflen){}
};

class Rect: public Figure
{
protected:
    void draw(QPainter* painter);
public:
    Rect(int x, int y, int halflen):Figure(x, y, halflen) {}
};

#endif // FIGURE_H
