#pragma once
#ifndef win_h
#define win_h
#include <QtWidgets>

// Основное окно приложения
class Win : public QWidget
{
    Q_OBJECT
protected:
    QTextCodec* _codec;			// Текстовый кодек
    QFrame* _frame;				// Рамка
    QLabel* _inputLabel;		// Метка редактора ввода
    QLabel* _outputLabel;		// Метка редактора вывода
    QLineEdit* _inputEdit;		// Редактор ввода
    QLineEdit* _outputEdit;		// Редактор вывода
    QPushButton* _nextButton;	// Кнопка "Следующий"
    QPushButton* _exitButton;	// Кнопка "Выход"
public:
    Win(QWidget* parent = 0);	// Конструктор окна
public slots:
    void begin();	// Начальная настройка интерфейса
    void calc();	// Реализация вычислений
};

// Валидатор ввода
class StrValidator : public QValidator
{
public:
    StrValidator(QObject* parent) :QValidator(parent) {}
    virtual State validate(QString& , int& position) const
    {
        return Acceptable;
    }
};
#endif
