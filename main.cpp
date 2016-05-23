
#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "StudentManage.h"
#include "AddStudent.h"
#include "AddMajor.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QFile>
#include <QWidget>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    LoginDialog w;
    w.show();
    return a.exec();
}

