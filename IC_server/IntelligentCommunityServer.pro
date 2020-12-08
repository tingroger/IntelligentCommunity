#-------------------------------------------------
#
# Project created by QtCreator 2020-07-25T11:01:48
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IntelligentCommunityServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        editable_table.cpp \
        main.cpp \
        intelligentmanagement.cpp \
        sqldatabase.cpp \
        user.cpp \
        user_tcp_server.cpp \
        win_admin.cpp \
        win_admin_tcp.cpp \
        win_admin_user.cpp

HEADERS += \
        common_header.h \
        editable_table.h \
        intelligentmanagement.h \
        sqldatabase.h \
        user.h \
        user_tcp_server.h \
        win_admin.h

FORMS += \
        intelligentmanagement.ui \
        win_admin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc

DISTFILES += \
    server.ico

RC_ICONS += server.ico
