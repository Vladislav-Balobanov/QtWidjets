#include "area.h"

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(QSize(300,200));
    _line = new Line(80,100,50);
    _rect = new Rect(220,100,50);
    _alpha=0;
}

void Area::showEvent(QShowEvent *)
{
    _timer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    _line->move(_alpha,&painter);
    _rect->move(_alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == _timer) // если наш таймер
    {
        _alpha=_alpha+0.2;
        update(); // обновить внешний вид
    }
    else
    QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *event)
{
    killTimer(_timer); // уничтожить таймер
}

Area::~Area()
{
    delete _line;
    delete _rect;
}
