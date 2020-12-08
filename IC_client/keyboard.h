#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

//SoftKey
#include <QToolButton>
#include <QKeyEvent>
#include <QApplication>

namespace Ui {
class Keyboard;
}

/*键盘的类*/
class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();
private:
    Ui::Keyboard *ui;
};



/*按键的类*/
class SoftKey : public QToolButton
{
    Q_OBJECT
public:
     explicit SoftKey(QWidget *parent = Q_NULLPTR);

private slots:
    void slot_button_clicked(bool);

private:
    static Qt::KeyboardModifier modifier;
    void get_keypad_number(const QString & button, QString & text);
    void set_modifier_change(SoftKey * key, const Qt::KeyboardModifier change);
};

#endif // KEYBOARD_H
