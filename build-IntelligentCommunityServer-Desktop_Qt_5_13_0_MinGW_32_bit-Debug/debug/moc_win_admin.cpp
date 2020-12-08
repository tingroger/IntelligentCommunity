/****************************************************************************
** Meta object code from reading C++ file 'win_admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../IC_server/win_admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WinAdmin_t {
    QByteArrayData data[14];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WinAdmin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WinAdmin_t qt_meta_stringdata_WinAdmin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "WinAdmin"
QT_MOC_LITERAL(1, 9, 14), // "sig_send_video"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 22), // "slot_get_clicked_index"
QT_MOC_LITERAL(4, 48, 11), // "QModelIndex"
QT_MOC_LITERAL(5, 60, 5), // "index"
QT_MOC_LITERAL(6, 66, 18), // "on_btn_add_clicked"
QT_MOC_LITERAL(7, 85, 18), // "on_btn_del_clicked"
QT_MOC_LITERAL(8, 104, 22), // "on_btn_refresh_clicked"
QT_MOC_LITERAL(9, 127, 15), // "slot_new_client"
QT_MOC_LITERAL(10, 143, 13), // "slot_get_data"
QT_MOC_LITERAL(11, 157, 20), // "slot_send_video_file"
QT_MOC_LITERAL(12, 178, 29), // "on_btn_set_video_file_clicked"
QT_MOC_LITERAL(13, 208, 25) // "on_btn_send_video_clicked"

    },
    "WinAdmin\0sig_send_video\0\0"
    "slot_get_clicked_index\0QModelIndex\0"
    "index\0on_btn_add_clicked\0on_btn_del_clicked\0"
    "on_btn_refresh_clicked\0slot_new_client\0"
    "slot_get_data\0slot_send_video_file\0"
    "on_btn_set_video_file_clicked\0"
    "on_btn_send_video_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WinAdmin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WinAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WinAdmin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_send_video(); break;
        case 1: _t->slot_get_clicked_index((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_btn_add_clicked(); break;
        case 3: _t->on_btn_del_clicked(); break;
        case 4: _t->on_btn_refresh_clicked(); break;
        case 5: _t->slot_new_client(); break;
        case 6: _t->slot_get_data(); break;
        case 7: _t->slot_send_video_file(); break;
        case 8: _t->on_btn_set_video_file_clicked(); break;
        case 9: _t->on_btn_send_video_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WinAdmin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WinAdmin::sig_send_video)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WinAdmin::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_WinAdmin.data,
    qt_meta_data_WinAdmin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WinAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WinAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WinAdmin.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WinAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WinAdmin::sig_send_video()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
