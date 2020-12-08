#include "keyboard.h"
#include "ui_keyboard.h"
#include <QFile>
#include <QDebug>

/********************************************************************************
Keyboard
********************************************************************************/
Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    //设置样式
    QFile file(":/keyboard_style.qss");
    file.open(QIODevice::ReadOnly);
    QByteArray style =  file.readAll();
    qDebug() << style;
    this->setStyleSheet(style);
    file.close();
}

Keyboard::~Keyboard()
{
    delete ui;
}

/********************************************************************************
SoftKey
********************************************************************************/
Qt::KeyboardModifier SoftKey::modifier = Qt::NoModifier;

SoftKey::SoftKey(QWidget *parent):QToolButton(parent)
{
    //响应clicked信号
    connect(this, &QToolButton::clicked, this, &SoftKey::slot_button_clicked);

}

void SoftKey::slot_button_clicked(bool)
{
    //向前删除
    if(this->objectName() == "btn_backspace")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace, Qt::NoModifier, this->text());
        QApplication::postEvent(QApplication::focusWidget(),keyEvent);
    }
    //逗号
    else if(this->objectName() == "btn_comma")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Comma, Qt::NoModifier, ",");
        QApplication::postEvent(this->parentWidget() ,keyEvent);
    }
    //句号
    else if(this->objectName() == "btn_period")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Period, Qt::NoModifier, ".");
        QApplication::postEvent(this->parentWidget() ,keyEvent);
    }
    //问号
    else if(this->objectName() == "btn_question")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Question, Qt::NoModifier, "?");
        QApplication::postEvent(this->parentWidget() ,keyEvent);
    }
    //空格键
    else if(this->objectName() == "btn_space")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Space, Qt::NoModifier, " ");
        QApplication::postEvent(this->parentWidget() ,keyEvent);
    }
    //回车键
    else if(this->objectName() == "btn_enter")
    {
        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,Qt::Key_Enter, Qt::NoModifier, this->objectName());
        QApplication::postEvent(QApplication::focusWidget(),keyEvent);
    }
    //大写模式
    else if(this->objectName() == "btn_case")
    {
        set_modifier_change(this, Qt::ShiftModifier);

    }
    //数字模式
    else if(this->objectName() == "btn_num")
    {
        set_modifier_change(this, Qt::KeypadModifier);
    }
    //退出
    else if(this->objectName() == "btn_quit")
    {
        this->parentWidget()->hide();
    }
    else if(this->objectName() == "btn_pinyin")
    {
        qDebug() << "Not support function";
    }
    else if(this->objectName() == "btn_switch")
    {
        qDebug() << "Not support function";
    }
    //普通字母
    else
    {
        QString text;
        switch (modifier)
        {
        case Qt::NoModifier:
            text = this->objectName();
            break;

        case Qt::ShiftModifier:
            text = this->objectName().toUpper();
            break;
        case Qt::KeypadModifier:
            get_keypad_number(this->objectName(), text);
            break;
        default:
            break;
        }

        QKeyEvent* keyEvent = new QKeyEvent(QEvent::KeyPress,'w', modifier, text);
        //通过postEvent将事件key的文本内容发送到有光标所在的控件上
        QApplication::postEvent(QApplication::focusWidget(),keyEvent);
    }
}

/********************************************************************************
 * 获取键盘上的数字
********************************************************************************/
void SoftKey::get_keypad_number(const QString & button, QString &text)
{
    if(button == "q")
        text = "1";
    else if(button == "w")
        text = "2";
    else if(button == "e")
        text = "3";
    else if(button == "r")
        text = "4";
    else if(button == "t")
        text = "5";
    else if(button == "y")
        text = "6";
    else if(button == "u")
        text = "7";
    else if(button == "i")
        text = "8";
    else if(button == "o")
        text = "9";
    else if(button == "p")
        text = "0";
    else
        text = "";
}

/********************************************************************************
 * 键盘的修饰模式改变时判断是否冲突
 * 其他模式转换时，初始模式必须为本模式或者NoModifier
********************************************************************************/
void SoftKey::set_modifier_change(SoftKey *key, const Qt::KeyboardModifier change)
{
        if(modifier == change)
        {
            modifier = Qt::NoModifier;
            key->setStyleSheet("border-radius: 10px;background-color:rgba(0, 0, 0, 0);");
        }
        else if(modifier == Qt::NoModifier)
        {
            modifier = change;
            key->setStyleSheet("border-radius: 10px;background-color:rgba(32,255,84,100);");
        }
        else
        {
            qDebug() << "The key conflict";
        }
}
