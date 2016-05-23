#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
#include "AddStudent.h"
#include "StudentManage.h"
#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTime>
#include <QMessageBox>
#include <QT>
#include <QSqlQuery>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    void clearAll();
    void setCode();
    bool judgeEmpty();

private:
    Ui::RegisterDialog *ui;
    int code;
    QSqlDatabase db;
    QSqlTableModel *model;
private slots:
    void sureButtonSlot();
    void cancelButtonSlot();
    void setSureButtonSlot();
};

#endif // REGISTERDIALOG_H
