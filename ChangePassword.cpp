#include "ChangePassword.h"
#include "ui_ChangePassword.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
     this->setWindowTitle("修改密码");
    ui->newPasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->SureNewPasswordLineEdit->setEchoMode(QLineEdit::Password);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_SureButton_clicked()
{
    QString username=ui->userNameLineEdit->text();
    QString newpassword=ui->newPasswordLineEdit->text();
    QString newpassword1=ui->SureNewPasswordLineEdit->text();
    if(username.isEmpty())
    {
        QMessageBox::warning(this,"警告!","用户名不能为空!",QMessageBox::Yes);
        return;
    }
    ui->newPasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->SureNewPasswordLineEdit->setEchoMode(QLineEdit::Password);

    if(newpassword!=newpassword1)
    {
        QMessageBox::warning(this,"警告!","两次输入的密码不同!",QMessageBox::Yes);
        ui->newPasswordLineEdit->clear();
        ui->SureNewPasswordLineEdit->clear();
    }
    else{
        this->db = QSqlDatabase::addDatabase("QSQLITE");
        this->db.setDatabaseName("student.db");
        if(!db.open())
        {
            qDebug()<<"数据库打开失败!";
        }
        else
            qDebug()<<"数据库打开成功!";
        QSqlTableModel* model=new QSqlTableModel(this);
        model->setTable("userinformation");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        QSqlQuery query;
        //UPDATE 表名字 SET 列1=值1,列2=值2WHERE 条件;
        bool ok=query.prepare("update userinformation set password=(:password) where username=(:name)");
        if(ok)
        {

            qDebug()<<"xiu gai cheng gong  ";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"xiu gai shi bai ";

        }
        query.bindValue(":password",newpassword);
        query.bindValue(":name", username);
        ok=query.exec();
        if(ok)
        {
            QMessageBox::information(this,"提示","密码修改成功",QMessageBox::Yes);
            //qDebug()<<query.lastError();
        }
        else
        {
             QMessageBox::warning(this,"警告","密码修改失败",QMessageBox::Yes);
        }

        db.close();
    }
    this->close();
}

void ChangePassword::on_CancelButton_clicked()
{
    this->close();
}
