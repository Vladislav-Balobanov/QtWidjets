#pragma once
#ifndef win_h
#define win_h
#include <QtWidgets>

// �������� ���� ����������
class Win : public QWidget
{
    Q_OBJECT
protected:
    QTextCodec* _codec;			// ��������� �����
    QFrame* _frame;				// �����
    QLabel* _inputLabel;		// ����� ��������� �����
    QLabel* _outputLabel;		// ����� ��������� ������
    QLineEdit* _inputEdit;		// �������� �����
    QLineEdit* _outputEdit;		// �������� ������
    QPushButton* _nextButton;	// ������ "���������"
    QPushButton* _exitButton;	// ������ "�����"
public:
    Win(QWidget* parent = 0);	// ����������� ����
public slots:
    void begin();	// ��������� ��������� ����������
    void calc();	// ���������� ����������
};

// ��������� �����
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
