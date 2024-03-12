#pragma once
#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include "area.h"
#include <QPushButton>
#include <QVBoxLayout>

class Win : public QWidget
{
protected:
    QTextCodec* _codec;
    Area* _area; // область отображения рисунка
    QPushButton* _button;
public:
    Win();
};
#endif // WIN_H
