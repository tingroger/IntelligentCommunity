/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "Keyboard.h"

QT_BEGIN_NAMESPACE

class Ui_Keyboard
{
public:
    QLabel *_label;
    SoftKey *q;
    SoftKey *w;
    SoftKey *e;
    SoftKey *r;
    SoftKey *t;
    SoftKey *y;
    SoftKey *u;
    SoftKey *i;
    SoftKey *o;
    SoftKey *p;
    SoftKey *btn_backspace;
    SoftKey *a;
    SoftKey *s;
    SoftKey *d;
    SoftKey *f;
    SoftKey *g;
    SoftKey *h;
    SoftKey *j;
    SoftKey *k;
    SoftKey *l;
    SoftKey *btn_enter;
    SoftKey *btn_case;
    SoftKey *z;
    SoftKey *x;
    SoftKey *c;
    SoftKey *v;
    SoftKey *b;
    SoftKey *n;
    SoftKey *m;
    SoftKey *btn_comma;
    SoftKey *btn_period;
    SoftKey *btn_question;
    SoftKey *btn_switch;
    SoftKey *btn_pinyin;
    SoftKey *btn_space;
    SoftKey *btn_num;
    SoftKey *btn_quit;

    void setupUi(QWidget *Keyboard)
    {
        if (Keyboard->objectName().isEmpty())
            Keyboard->setObjectName(QString::fromUtf8("Keyboard"));
        Keyboard->resize(800, 255);
        Keyboard->setStyleSheet(QString::fromUtf8(""));
        _label = new QLabel(Keyboard);
        _label->setObjectName(QString::fromUtf8("_label"));
        _label->setGeometry(QRect(0, 0, 800, 255));
        _label->setStyleSheet(QString::fromUtf8("background-image: url(:/kb_letter.jpg);"));
        _label->setLineWidth(0);
        q = new SoftKey(Keyboard);
        q->setObjectName(QString::fromUtf8("q"));
        q->setGeometry(QRect(7, 7, 61, 55));
        q->setStyleSheet(QString::fromUtf8(""));
        w = new SoftKey(Keyboard);
        w->setObjectName(QString::fromUtf8("w"));
        w->setGeometry(QRect(76, 7, 61, 55));
        e = new SoftKey(Keyboard);
        e->setObjectName(QString::fromUtf8("e"));
        e->setGeometry(QRect(145, 7, 62, 55));
        r = new SoftKey(Keyboard);
        r->setObjectName(QString::fromUtf8("r"));
        r->setGeometry(QRect(214, 7, 62, 55));
        t = new SoftKey(Keyboard);
        t->setObjectName(QString::fromUtf8("t"));
        t->setGeometry(QRect(283, 7, 62, 55));
        y = new SoftKey(Keyboard);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(352, 7, 62, 55));
        u = new SoftKey(Keyboard);
        u->setObjectName(QString::fromUtf8("u"));
        u->setGeometry(QRect(421, 7, 62, 55));
        i = new SoftKey(Keyboard);
        i->setObjectName(QString::fromUtf8("i"));
        i->setGeometry(QRect(490, 7, 62, 55));
        o = new SoftKey(Keyboard);
        o->setObjectName(QString::fromUtf8("o"));
        o->setGeometry(QRect(559, 7, 62, 55));
        p = new SoftKey(Keyboard);
        p->setObjectName(QString::fromUtf8("p"));
        p->setGeometry(QRect(628, 7, 62, 55));
        btn_backspace = new SoftKey(Keyboard);
        btn_backspace->setObjectName(QString::fromUtf8("btn_backspace"));
        btn_backspace->setGeometry(QRect(697, 7, 62, 55));
        a = new SoftKey(Keyboard);
        a->setObjectName(QString::fromUtf8("a"));
        a->setGeometry(QRect(33, 70, 61, 52));
        s = new SoftKey(Keyboard);
        s->setObjectName(QString::fromUtf8("s"));
        s->setGeometry(QRect(102, 70, 61, 52));
        d = new SoftKey(Keyboard);
        d->setObjectName(QString::fromUtf8("d"));
        d->setGeometry(QRect(171, 70, 61, 52));
        f = new SoftKey(Keyboard);
        f->setObjectName(QString::fromUtf8("f"));
        f->setGeometry(QRect(240, 70, 61, 52));
        g = new SoftKey(Keyboard);
        g->setObjectName(QString::fromUtf8("g"));
        g->setGeometry(QRect(309, 70, 62, 52));
        h = new SoftKey(Keyboard);
        h->setObjectName(QString::fromUtf8("h"));
        h->setGeometry(QRect(378, 70, 62, 52));
        j = new SoftKey(Keyboard);
        j->setObjectName(QString::fromUtf8("j"));
        j->setGeometry(QRect(447, 70, 62, 52));
        k = new SoftKey(Keyboard);
        k->setObjectName(QString::fromUtf8("k"));
        k->setGeometry(QRect(516, 70, 62, 52));
        l = new SoftKey(Keyboard);
        l->setObjectName(QString::fromUtf8("l"));
        l->setGeometry(QRect(585, 70, 62, 52));
        btn_enter = new SoftKey(Keyboard);
        btn_enter->setObjectName(QString::fromUtf8("btn_enter"));
        btn_enter->setGeometry(QRect(654, 70, 105, 52));
        btn_case = new SoftKey(Keyboard);
        btn_case->setObjectName(QString::fromUtf8("btn_case"));
        btn_case->setGeometry(QRect(7, 131, 61, 53));
        z = new SoftKey(Keyboard);
        z->setObjectName(QString::fromUtf8("z"));
        z->setGeometry(QRect(76, 131, 62, 53));
        x = new SoftKey(Keyboard);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(145, 131, 62, 53));
        c = new SoftKey(Keyboard);
        c->setObjectName(QString::fromUtf8("c"));
        c->setGeometry(QRect(214, 131, 62, 53));
        v = new SoftKey(Keyboard);
        v->setObjectName(QString::fromUtf8("v"));
        v->setGeometry(QRect(283, 131, 62, 53));
        b = new SoftKey(Keyboard);
        b->setObjectName(QString::fromUtf8("b"));
        b->setGeometry(QRect(352, 131, 62, 53));
        b->setStyleSheet(QString::fromUtf8(""));
        n = new SoftKey(Keyboard);
        n->setObjectName(QString::fromUtf8("n"));
        n->setGeometry(QRect(421, 131, 62, 53));
        m = new SoftKey(Keyboard);
        m->setObjectName(QString::fromUtf8("m"));
        m->setGeometry(QRect(490, 131, 62, 53));
        btn_comma = new SoftKey(Keyboard);
        btn_comma->setObjectName(QString::fromUtf8("btn_comma"));
        btn_comma->setGeometry(QRect(559, 131, 62, 53));
        btn_period = new SoftKey(Keyboard);
        btn_period->setObjectName(QString::fromUtf8("btn_period"));
        btn_period->setGeometry(QRect(628, 131, 62, 53));
        btn_question = new SoftKey(Keyboard);
        btn_question->setObjectName(QString::fromUtf8("btn_question"));
        btn_question->setGeometry(QRect(697, 131, 62, 53));
        btn_switch = new SoftKey(Keyboard);
        btn_switch->setObjectName(QString::fromUtf8("btn_switch"));
        btn_switch->setGeometry(QRect(7, 193, 96, 53));
        btn_pinyin = new SoftKey(Keyboard);
        btn_pinyin->setObjectName(QString::fromUtf8("btn_pinyin"));
        btn_pinyin->setGeometry(QRect(111, 193, 96, 53));
        btn_space = new SoftKey(Keyboard);
        btn_space->setObjectName(QString::fromUtf8("btn_space"));
        btn_space->setGeometry(QRect(214, 193, 442, 53));
        btn_space->setStyleSheet(QString::fromUtf8(""));
        btn_num = new SoftKey(Keyboard);
        btn_num->setObjectName(QString::fromUtf8("btn_num"));
        btn_num->setGeometry(QRect(663, 193, 96, 53));
        btn_quit = new SoftKey(Keyboard);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setGeometry(QRect(768, 7, 25, 25));

        retranslateUi(Keyboard);

        QMetaObject::connectSlotsByName(Keyboard);
    } // setupUi

    void retranslateUi(QWidget *Keyboard)
    {
        Keyboard->setWindowTitle(QCoreApplication::translate("Keyboard", "Form", nullptr));
        _label->setText(QString());
        q->setText(QString());
        w->setText(QString());
        e->setText(QString());
        r->setText(QString());
        t->setText(QString());
        y->setText(QString());
        u->setText(QString());
        i->setText(QString());
        o->setText(QString());
        p->setText(QString());
        btn_backspace->setText(QString());
        a->setText(QString());
        s->setText(QString());
        d->setText(QString());
        f->setText(QString());
        g->setText(QString());
        h->setText(QString());
        j->setText(QString());
        k->setText(QString());
        l->setText(QString());
        btn_enter->setText(QString());
        btn_case->setText(QString());
        z->setText(QString());
        x->setText(QString());
        c->setText(QString());
        v->setText(QString());
        b->setText(QString());
        n->setText(QString());
        m->setText(QString());
        btn_comma->setText(QString());
        btn_period->setText(QString());
        btn_question->setText(QString());
        btn_switch->setText(QString());
        btn_pinyin->setText(QString());
        btn_space->setText(QString());
        btn_num->setText(QString());
        btn_quit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Keyboard: public Ui_Keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
