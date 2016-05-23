#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QVBoxLayout>
LoginDialog::LoginDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //创建QSqlTableModel
    //model=new QSqlTableModel(this);
    //设置 the strategy for editing values in the database to strategy.
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //设置为固定大小
    this->setMinimumSize(400,300);
    this->setMaximumSize(400,300);
    //设置登录对话框的标题
    this->setWindowTitle("登录");
    //设置调色板,用于设置titlelabel的颜色
    QPalette p;
    p.setColor(QPalette::WindowText,Qt::black);
    //  ui->titlelabel->setPalette(p);
    //设置登录按钮不可用
    ui->LoginButton->setEnabled(false);
    //设置lineEdit提示语句
    ui->IDEdit->setPlaceholderText("username:");
    ui->PasswordEdit->setPlaceholderText("password:");
    //设置PasswordEdit显示为密码模式
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    connect(ui->LoginButton,SIGNAL(clicked()),this,SLOT(LoginSlot()));
    connect(ui->RegisterButton,SIGNAL(clicked()),this,SLOT(RegisterSlot()));
    connect(ui->QuitButton,SIGNAL(clicked()),this,SLOT(QuitSlot()));
    //设置登录按钮可以使用
    connect(ui->IDEdit,SIGNAL(textChanged(QString)),this,SLOT(loginSetSlot(QString)));
    connect(ui->PasswordEdit,SIGNAL(textChanged(QString)),this,SLOT(loginSetSlot(QString)));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
//登录的槽
void LoginDialog::LoginSlot()
{
    if(!this->judgeEmpty())
    {
        ui->PasswordEdit->clear();
        return;
    }
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<db.isValid();
    db.setDatabaseName("student.db");
    /************************************
    bool ok1= QFile::remove("student");
    if(ok1)
        qDebug()<<"shan chu cheng gong";
    ***********************************/
    if(!db.open())
    {
        qDebug()<<"数据库打开失败!";
        return ;
    }
    else
        qDebug()<<"数据库打开成功!";
    QSqlQuery query;
    /**************************************************************************
     * //创建表

    bool ok1 = query.exec("CREATE TABLE IF NOT EXISTS  userinformation (id INTEGER primary key autoincrement,"
                                            "username varchar(10) not null,"
                                            "name VARCHAR(20) NOT NULL,"
                                            "password varchar(20) NOT NULL)");
    if (ok1)
    {

        qDebug()<<"ceate table partition success\n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"ceate table partition failed\n";
    }
    ****************************************************************************/
    /**********************************************************************************************
    //清空表
    QSqlQuery sql_query;
    sql_query.prepare("delete from userinformation");
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    qDebug()<<"cleared";
    }
    **********************************************************************************************/
    /**********************************************************************************************
     // 初始化的时候增加一项表的内容
    query.prepare("INSERT INTO userinformation (id,studentNumber, name, password) VALUES (:id, :studentNumber,:name, :password)");
    query.bindValue(":studentNumber",QString("20142010"));
    query.bindValue(":name", QString("libo"));
    query.bindValue(":password", QString("1234567"));
    bool ok=query.exec();
    if (ok)
    {
        qDebug()<<"cha ru cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"cha ru shi bai\n";
    }
   ****************************************************************************************************/

    bool ok2=query.exec("SELECT id, name, password FROM userinformation");
    if (ok2)
    {
        qDebug()<<"operation success\n";
    }
    else
    {
        qDebug()<<"operation failed/n";
    }
    while (query.next())
    {
         qDebug()<<query.value(0).toInt()<<query.value(1).toString()<<query.value(2).toString();
    }

    model=new QSqlTableModel(this);
    model->setTable("userinformation");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    int i;
    for(i=0;i<model->rowCount();i++)
    {
        qDebug()<<i;
        QSqlRecord record=model->record(i);
        if(record.value(1)==ui->IDEdit->text()&&
                record.value(3)==ui->PasswordEdit->text())
        {
            qDebug()<<record.value(1)<<record.value(2);
            qDebug()<<ui->IDEdit->text()<<ui->PasswordEdit->text();
            QString str1="登录成功";
            QString str2=record.value(2).toString();
            QString str3="恭喜";
            QMessageBox::information(this,"提示",str3+str2+str1,QMessageBox::Yes);
            this->clearAll();
            //登录成功后关闭该对话框
            student=new StudentManage();

            connect(student,SIGNAL(toLoginDialog()),this,SLOT(showNormal()));
            student->show();
            connect(this,SIGNAL(toStudentManage(QString,QString)),student,SLOT(comeLoginDialog(QString,QString)));
            emit toStudentManage(str2,record.value(1).toString());
            this->hide();
            return ;
        }
        else if(record.value(1)==ui->IDEdit->text()&&
                 record.value(3)!=ui->PasswordEdit->text())
        {
            QMessageBox::information(this,"提示","密码输入有误!",QMessageBox::Yes);
            this->clearAll();
            return;
        }
     }
     QMessageBox::warning(this,"提示","用户不存在,请注册!",QMessageBox::Yes);
     this->clearAll();
     return;
}
//注册的槽
void LoginDialog::RegisterSlot()
{

    RegisterDialog *d=new RegisterDialog;

    //this->hide();
    if(d->exec()==QDialog::Accepted)
    {
        d->show();
    }
    this->clearAll();

}
//退出的槽
void LoginDialog::QuitSlot()
{
    this->close();
}
//设置登录按钮为可用状态
void LoginDialog::loginSetSlot(QString)
{
    ui->LoginButton->setEnabled(true);
}
void LoginDialog::clearAll()
{
    ui->IDEdit->clear();
    ui->PasswordEdit->clear();
}
bool LoginDialog::judgeEmpty()
{
    if(ui->IDEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","用户名不能为空!");
        return false;
    }
    if(ui->PasswordEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","密码不能为空!");
        return false;
    }
    else
        return true;
}


