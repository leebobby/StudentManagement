#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include "RegisterDialog.h"
#include "StudentManage.h"
#include "AddStudent.h"
#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QButtonGroup>
#include <QMessageBox>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    void clearAll();//清空两个LineEdit
    bool judgeEmpty();//判断两个LineEdit是不是有内容

private:
    Ui::LoginDialog *ui;
    QSqlTableModel *model;
    StudentManage *student;
signals:
    void toStudentManage(QString,QString);
private slots:
    void QuitSlot();
    void RegisterSlot();
    void LoginSlot();
    void loginSetSlot(QString);
};

#endif // LOGINDIALOG_H
