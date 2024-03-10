#include "win.h"

Win::Win(QWidget* parent) : QWidget(parent)
{
    // ����������� ���������
    codec = QTextCodec::codecForName("Windows-1251");

    // ������������� Layout-� ����
    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);

    // ������������� ���������
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);

    // �������������� ������
    calcbutton = new QPushButton("+1",this);
    exitbutton = new QPushButton(codec->toUnicode("�����"),this);

    // ����� ��������� ����
    this->setWindowTitle(codec->toUnicode("�������"));

    // ����� ��������� ����������� ����
    label1 = new QLabel(codec->toUnicode("C��� �� 1"),this);
    label2 = new QLabel(codec->toUnicode("C��� �� 5"),this);

    /// ���������� ����
    // ��������� ������� ������� LayOut-�
    layout1->addWidget(label1);
    layout1->addWidget(label2);

    // ��������� ������� ������� LayOut-�
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);

    // ��������� ������� �������� LayOut-�
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);

    // ��������� ������� �������� LayOut-�
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    // ����� �������� � ������
    connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one);
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);
    connect(exitbutton, &QPushButton::clicked, this, &QWidget::close);
}


