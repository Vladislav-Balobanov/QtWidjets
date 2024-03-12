#include "win.h"

Win::Win()
{
    _codec = QTextCodec::codecForName("Windows-1251");
    this->setWindowTitle(_codec->toUnicode("Обработка событий"));
    _area = new Area( this );
    _button = new QPushButton(_codec->toUnicode("Завершить"),this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_area);
    layout->addWidget(_button);
    connect(_button, &QPushButton::clicked, this, &QWidget::close);
}
