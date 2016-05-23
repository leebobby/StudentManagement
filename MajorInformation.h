#ifndef MAJORINFORMATION_H
#define MAJORINFORMATION_H

#include "StudentManage.h"
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTime>
#include <QMessageBox>
#include <QT>
#include <QSqlQuery>
#include <QFont>
#include <QSqlError>
#include <QTableWidgetItem>

namespace Ui {
class MajorInformation;
}

class MajorInformation : public QWidget
{
    Q_OBJECT

public:
    explicit MajorInformation(QWidget *parent = 0);
    ~MajorInformation();

private slots:
    void on_AddButton_clicked();

    void on_ChangeButton_clicked();

    void on_DeleteButton_clicked();

    void on_SureButton_clicked();

    void on_CancelButton_clicked();

    void mySort(int coloum);

    void updataSlot(QTableWidgetItem*);

    void changeSlot(int,int);


private:
   Ui::MajorInformation *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlTableModel *model1;

signals:
    void toStudentManage();
};

#endif // MAJORINFORMATION_H
