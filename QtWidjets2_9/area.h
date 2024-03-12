#ifndef AREA_H
#define AREA_H

#include "figure.h"
#include <QWidget>
#include <QPaintEvent>
#include <QShowEvent>

class Area : public QWidget
{
    int _timer; // идентификатор таймера
    float _alpha; // угол поворота
public:
    Area(QWidget *parent = 0);
    ~Area();
    Line *_line;
    Rect *_rect;
protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};

#endif // AREA_H
