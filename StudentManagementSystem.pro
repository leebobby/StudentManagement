#-------------------------------------------------
#
# Project created by QtCreator 2016-04-30T14:47:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentManagementSystem
TEMPLATE = app


SOURCES += main.cpp \
    LoginDialog.cpp \
    RegisterDialog.cpp \
    StudentManage.cpp \
    ChangePassword.cpp \
    MajorInformation.cpp

HEADERS  += \
    LoginDialog.h \
    RegisterDialog.h \
    StudentManage.h \
    ChangePassword.h \
    MajorInformation.h

FORMS    += \
    LoginDialog.ui \
    RegisterDialog.ui \
    StudentManage.ui \
    ChangePassword.ui \
    MajorInformation.ui
