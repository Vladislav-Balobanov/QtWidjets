#include "win.h"

Win::Win(QWidget* parent) : QWidget(parent)
{
    // Настраиваем кодировку
    codec = QTextCodec::codecForName("Windows-1251");

    // Инициализруем Layout-ы окна
    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);

    // Инициализация счётчиков
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);

    // Инициализируем кнопки
    calcbutton = new QPushButton("+1",this);
    exitbutton = new QPushButton(codec->toUnicode("Выход"),this);

    // Задаём заголовок окна
    this->setWindowTitle(codec->toUnicode("Счетчик"));

    // Задаём заголовки компонентов окна
    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);

    /// Компановка окна
    // Добавляем виджеты первого LayOut-а
    layout1->addWidget(label1);
    layout1->addWidget(label2);

    // Добавляем виджеты второго LayOut-а
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);

    // Добавляем виджеты третьего LayOut-а
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);

    // Добавляем виджеты третьего LayOut-а
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    // Связь сигналов и слотов
    connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one);
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);
    connect(exitbutton, &QPushButton::clicked, this, &QWidget::close);
}


