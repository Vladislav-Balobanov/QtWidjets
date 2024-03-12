#pragma once
#include "win.h"

// ��������
Win::Win(QWidget* parent) : QWidget(parent)
{
    // ����������� ���������
    _codec = QTextCodec::codecForName("Windows-1251");

    // ����� ��� ����
    setWindowTitle(_codec->toUnicode("���������� � �������"));

    // ������������� ���� � ��� ���������
    _frame = new QFrame(this);
    _frame->setFrameShadow(QFrame::Raised);
    _frame->setFrameShape(QFrame::Panel);

    // ����������� ��������� � ���� ��� ����� �����
    _inputLabel = new QLabel(_codec->toUnicode("������� �����:"), this);
    _inputEdit = new QLineEdit("", this);

    // �������������� ��������� � ���������� � ���� �����
    StrValidator* validator = new StrValidator(_inputEdit);
    _inputEdit->setValidator(validator);

    // ������������� ���� ������ � ��������� ���� ������
    _outputLabel = new QLabel(_codec->toUnicode("���������:"), this);
    _outputEdit = new QLineEdit("", this);

    // �������������� ������
    _nextButton = new QPushButton(_codec->toUnicode("���������"), this);
    _exitButton = new QPushButton(_codec->toUnicode("�����"), this);

    /// ���������� ����������
    // �������������� ������� ��� ����������
    QVBoxLayout* vLayout1 = new QVBoxLayout(_frame);    
    QVBoxLayout* vLayout2 = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout(this);

    // ��������� ������� ������� Layout-�
    vLayout1->addWidget(_inputLabel);
    vLayout1->addWidget(_inputEdit);
    vLayout1->addWidget(_outputLabel);
    vLayout1->addWidget(_outputEdit);
    vLayout1->addStretch();

    // ��������� ������� ������� Layout-�
    vLayout2->addWidget(_nextButton);
    vLayout2->addWidget(_exitButton);
    vLayout2->addStretch();
    hLayout->addWidget(_frame);
    hLayout->addLayout(vLayout2);

    // ������������� ����������
    begin();

    // ���������� ����� � �������(���������� ���������� ����� �����������)
    connect(_exitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(_nextButton, &QPushButton::clicked, this, &Win::begin);
    connect(_inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

// ��������� ��������� ����������
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

// �����������
void Win::calc()
{
    bool Ok = true; float r, a;
    QString str = _inputEdit->text();
    a = str.toDouble(&Ok);

    if(a >= DBL_MAX)
    {
        QMessageBox msgBox
        (	QMessageBox::Information,
            _codec->toUnicode("���������� � �������."),
            _codec->toUnicode("���������� ��������� ���������. ����� ������� ������."),
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
            _codec->toUnicode("���������� � �������."),
            _codec->toUnicode("������� �������� ��������."),
            QMessageBox::Ok
        );

        msgBox.exec();
    }
}
