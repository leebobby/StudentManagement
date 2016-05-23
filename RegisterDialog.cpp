#include "RegisterDialog.h"
#include "ui_RegisterDialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    this->setMaximumSize(274,307);
    this->setMinimumSize(274,307);
    this->setWindowTitle("注册新用户:");

    this->db=QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<db.isValid();
    db.setDatabaseName("student.db");
    if(!db.open())
    {
        qDebug()<<"数据库打开失败!";
        return ;
    }
    else
        qDebug()<<"数据库打开成功!";


    ui->PasswordLineEdit->setPlaceholderText("password:");
    ui->SurePasswordLineEdit->setPlaceholderText("password again:");
    ui->UserNameLineEdit->setPlaceholderText("usrname:");
    //ui->CodeLineEdit->setPlaceholderText("请输入验证码:");
    ui->NameLineEdit->setPlaceholderText("name:");

    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->SurePasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->SureButton->setEnabled(false);
    connect(ui->SureButton,SIGNAL(clicked()),this,SLOT(sureButtonSlot()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(cancelButtonSlot()));
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    this->setCode();
    connect(ui->UserNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(setSureButtonSlot()));
    connect(ui->PasswordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(setSureButtonSlot()));
}
void RegisterDialog::sureButtonSlot()
{
    int i;
    if(!this->judgeEmpty())
    {
        ui->PasswordLineEdit->clear();
        ui->SurePasswordLineEdit->clear();
        ui->CodeLineEdit->clear();
        return ;
    }
    //判断两次的密码是不是一致
    if(ui->PasswordLineEdit->text()!=ui->SurePasswordLineEdit->text())
    {
        QMessageBox::warning(this,"警告","两次密码不一致!",QMessageBox::Yes);
        ui->PasswordLineEdit->clear();
        ui->SurePasswordLineEdit->clear();
        ui->CodeLineEdit->clear();
        this->setCode();
        return ;
    }
    //判断验证码是不是正确
    if(this->code!=ui->CodeLineEdit->text().toInt())
    {
         QMessageBox::warning(this,"警告","验证码输入错误!",QMessageBox::Yes);
         ui->PasswordLineEdit->clear();
         ui->SurePasswordLineEdit->clear();
         ui->CodeLineEdit->clear();
         this->setCode();
         return;
    }
    model=new QSqlTableModel(this);
    model->setTable("userinformation");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    for(i=0;i<model->rowCount();i++)
    {
         QSqlRecord record=model->record(i);
         //判断用户信息已经存在
         if((record.value(1)==ui->UserNameLineEdit->text()&&record.value(3)!=""))
         {
             QMessageBox::warning(this,"警告!","用户已存在,请直接登录!",QMessageBox::Yes);
             this->clearAll();
             this->setCode();
             return;
         }
    }
    //如果用户信息不存在,添加用户信息进数据库
    if(i==model->rowCount())
    {
        QSqlQuery query;
        bool ok=query.prepare("INSERT INTO userinformation (username,name,password) VALUES (:username,:name,:password)");
        if (ok)
        {
            qDebug()<<"xin yong hu cha ru cheng gong \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"xin yong hu cha ru shi bai\n";
        }
        QString username=ui->UserNameLineEdit->text();
        QString name=ui->NameLineEdit->text();
        QString password=ui->PasswordLineEdit->text();
        qDebug()<<username<<name<<password;
        query.bindValue(":username",username);
        query.bindValue(":name", name);
        query.bindValue(":password", password);
        ok=query.exec();
        if (ok)
        {
            qDebug()<<"xin yong hu cha ru cheng gong \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"xin yong hu cha ru shi bai\n";
        }
        ok=query.exec("SELECT id,username, name, password FROM userinformation");
        if (ok)
        {
            qDebug()<<"operation success\n";
        }
        else
        {
            qDebug()<<"operation failed/n";
        }
        while (query.next())
        {
             qDebug()<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString();
        }
    }

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}
void RegisterDialog::cancelButtonSlot()
{
    this->accept();
}
void RegisterDialog::setSureButtonSlot()
{
    ui->SureButton->setEnabled(true);
}
//清空lineedit的上的文本
void RegisterDialog::clearAll()
{
    ui->UserNameLineEdit->clear();
    ui->PasswordLineEdit->clear();
    ui->SurePasswordLineEdit->clear();
    ui->CodeLineEdit->clear();
}
//设置验证码
void RegisterDialog::setCode()
{
    QPalette p1;
    p1.setColor(QPalette::WindowText,Qt::red);
    code=qrand()%10000;
    while(code<1000)
        code=qrand()%10000;
    ui->CodeLabel->setText(QString::number(code));
    ui->CodeLabel->setPalette(p1);
}
//判断是否为空
bool RegisterDialog::judgeEmpty()
{
    if(ui->UserNameLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告!","用户名不能为空!");
        return false;
    }
    else if(ui->PasswordLineEdit->text().isEmpty()||
            ui->SurePasswordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告!","用户密码不能为空!");
        return false;
    }
    else if(ui->CodeLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告!","验证码不能为空!");
        return false;
    }
    else
        return true;
}
