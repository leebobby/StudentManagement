#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QDebug>
#include <QPalette>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QHeaderView>
#include <QSqlError>
#include <QVariant>
namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    ~ChangePassword();

private slots:
    void on_SureButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::ChangePassword *ui;
    QSqlDatabase db;
};

#endif // CHANGEPASSWORD_H
