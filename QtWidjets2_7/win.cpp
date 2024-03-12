#pragma once
#include "win.h"

// Родитель
Win::Win(QWidget* parent) : QWidget(parent)
{
    // Настраиваем кодировку
    _codec = QTextCodec::codecForName("Windows-1251");

    // Задаём имя окна
    setWindowTitle(_codec->toUnicode("Возведение в квадрат"));

    // Инициализация окна и его настройка
    _frame = new QFrame(this);
    _frame->setFrameShadow(QFrame::Raised);
    _frame->setFrameShape(QFrame::Panel);

    // Настраиваем заголовок и поле для ввода числа
    _inputLabel = new QLabel(_codec->toUnicode("Введите число:"), this);
    _inputEdit = new QLineEdit("", this);

    // Инициализируем валидатор и првязываем к полю ввода
    StrValidator* validator = new StrValidator(_inputEdit);
    _inputEdit->setValidator(validator);

    // Инициализация поля вывода и заголовка поля вывода
    _outputLabel = new QLabel(_codec->toUnicode("Результат:"), this);
    _outputEdit = new QLineEdit("", this);

    // Инициализируем кнопки
    _nextButton = new QPushButton(_codec->toUnicode("Следующее"), this);
    _exitButton = new QPushButton(_codec->toUnicode("Выход"), this);

    /// Компоновка приложения
    // Инициализируем объекты для компановки
    QVBoxLayout* vLayout1 = new QVBoxLayout(_frame);    
    QVBoxLayout* vLayout2 = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout(this);

    // Компануем объекты первого Layout-а
    vLayout1->addWidget(_inputLabel);
    vLayout1->addWidget(_inputEdit);
    vLayout1->addWidget(_outputLabel);
    vLayout1->addWidget(_outputEdit);
    vLayout1->addStretch();

    // Компануем объекты второго Layout-а
    vLayout2->addWidget(_nextButton);
    vLayout2->addWidget(_exitButton);
    vLayout2->addStretch();
    hLayout->addWidget(_frame);
    hLayout->addLayout(vLayout2);

    // Преднастройка интерфейса
    begin();

    // Подключаем слоты и сигналы(используем современый стиль подключения)
    connect(_exitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(_nextButton, &QPushButton::clicked, this, &Win::begin);
    connect(_inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

// Начальная настройка интерфейса
void Win::begin()
{
    _inputEdit->clear();
    _nextButton->setEnabled(false);
    _nextButton->setDefault(false);
    _inputEdit->setEnabled(true);
    _outputLabel->setVisible(false);
    _outputEdit->setVisible(false);
    _outputEdit->setEnabled(false);
    _inputEdit->setFocus();
}

// Выичисления
void Win::calc()
{
    bool Ok = true; float r, a;
    QString str = _inputEdit->text();
    a = str.toDouble(&Ok);

    if(a >= DBL_MAX)
    {
        QMessageBox msgBox
        (	QMessageBox::Information,
            _codec->toUnicode("Возведение в квадрат."),
            _codec->toUnicode("Невозможно вычислить результат. Число слишком велико."),
            QMessageBox::Ok
        );

        msgBox.exec();
        _inputEdit->clear();
    }
    else if (Ok)
    {
        r = a * a;
        str.setNum(r);
        _outputEdit->setText(str);
        _inputEdit->setEnabled(false);
        _outputLabel->setVisible(true);
        _outputEdit->setVisible(true);
        _nextButton->setDefault(true);
        _nextButton->setEnabled(true);
        _nextButton->setFocus();
    }
    else if (!str.isEmpty())
    {
        QMessageBox msgBox
        (	QMessageBox::Information,
            _codec->toUnicode("Возведение в квадрат."),
            _codec->toUnicode("Введено неверное значение."),
            QMessageBox::Ok
        );

        msgBox.exec();
    }
}
