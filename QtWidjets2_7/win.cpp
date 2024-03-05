#pragma once
#include "win.h"

// Родитель
Win::Win(QWidget* parent) : QWidget(parent)
{
    _codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(_codec->toUnicode("Возведение в квадрат"));
    _frame = new QFrame(this);
    _frame->setFrameShadow(QFrame::Raised);
    _frame->setFrameShape(QFrame::Panel);
    _inputLabel = new QLabel(_codec->toUnicode("Введите число:"),
        this);
    _inputEdit = new QLineEdit("", this);
    StrValidator* v = new StrValidator(_inputEdit);
    _inputEdit->setValidator(v);
    _outputLabel = new QLabel(_codec->toUnicode("Результат:"),
        this);
    _outputEdit = new QLineEdit("", this);
    _nextButton = new QPushButton(_codec->toUnicode("Следующее"),
        this);
    _exitButton = new QPushButton(_codec->toUnicode("Выход"),
        this);
    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout* vLayout1 = new QVBoxLayout(_frame);
    vLayout1->addWidget(_inputLabel);
    vLayout1->addWidget(_inputEdit);
    vLayout1->addWidget(_outputLabel);
    vLayout1->addWidget(_outputEdit);
    vLayout1->addStretch();
    QVBoxLayout* vLayout2 = new QVBoxLayout();

    vLayout2->addWidget(_nextButton);
    vLayout2->addWidget(_exitButton);
    vLayout2->addStretch();
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(_frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(_exitButton, SIGNAL(clicked(bool)),
        this, SLOT(close()));
    connect(_nextButton, SIGNAL(clicked(bool)),
        this, SLOT(begin()));
    connect(_inputEdit, SIGNAL(returnPressed()),
        this, SLOT(calc()));
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

    if (a <= DBL_MAX && Ok)
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
