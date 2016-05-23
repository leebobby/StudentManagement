#include "MajorInformation.h"
#include "ui_MajorInformation.h"

MajorInformation::MajorInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MajorInformation)
{
    ui->setupUi(this);
    this->setMaximumSize(400,286);
    this->setMinimumSize(400,286);
    this->setWindowTitle("各专业信息!");
    ui->tableWidget->setAlternatingRowColors(true);//设置没行变一色
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
    model=new QSqlTableModel(this);
    model->setTable("majorinformation");
    model->select();
    int recordcount=model->rowCount();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(recordcount); //动态设置行数

    QStringList list;
    list<<"专业"<<"必修";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    //设置列名为加粗
    QFont font=ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    //去掉第一列标号
    QHeaderView *header=ui->tableWidget->verticalHeader();
    header->setHidden(true);
    //设置选中背景色
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;");
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//设置为可以选中单个
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //显示信息
    int i=0;
    for(i=0;i<model->rowCount();i++)
    {
        QSqlRecord record=model->record(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(record.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(record.value(1).toString()));
         ui->tableWidget->item(i,0)->setFlags(Qt::NoItemFlags);
    }
    //按列排序
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(mySort(int)));
}

MajorInformation::~MajorInformation()
{
    delete ui;
}

void MajorInformation::on_AddButton_clicked()
{
    int rowcount=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowcount);
    //QWidget* temp=ui->tableWidget->cellWidget(rowcount-1,1);
    //connect(temp,SIGNAL(cellChanged(int,int)),this,SLOT(updataSlot(int,int)));
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(updataSlot(QTableWidgetItem*)));
}
void MajorInformation::updataSlot(QTableWidgetItem* temp)
{
    qDebug()<<"ke yi shua xin";
    disconnect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(changeSlot(int,int)));
    if(temp->column()==0)
        return;
    int rowcount=ui->tableWidget->rowCount();
    QString major=ui->tableWidget->item(rowcount-1,0)->text();
    //QString requiredcourse=temp->text();
    QString requiredcourse=ui->tableWidget->item(rowcount-1,1)->text();
    qDebug()<<"hello2";
    qDebug()<<major;
    qDebug()<<requiredcourse;
    model=new QSqlTableModel(this);
    model->setTable("majorinformation");
    model->select();
    for(int i=0;i<model->rowCount();i++)
    {
        QSqlRecord record=model->record(i);
        if(record.value(0)==major&&record.value(1)==requiredcourse)
        {
            QMessageBox::warning(this,"警告","该专业信息已经存在了哦~",QMessageBox::Yes);
            return ;
        }
    }
    QSqlQuery query;
    query.prepare("INSERT INTO majorinformation (major, requiredcourse) VALUES (:major, :requiredcourse)");
    qDebug()<<"hello1";
    qDebug()<<major;
    qDebug()<<requiredcourse;
    query.bindValue(":major",major);
    query.bindValue(":requiredcourse",requiredcourse);
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

}
void MajorInformation::on_ChangeButton_clicked()
{
    connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(changeSlot(int,int)));
}
void MajorInformation::on_DeleteButton_clicked()
{
    int rowIndex = ui->tableWidget->currentRow();
    model=new QSqlTableModel(this);
    model->setTable("majorinformation");
    model->select();
    QSqlTableModel *model1=new QSqlTableModel(this);
    model1->setTable("studentinformation");
    model1->select();
    QString major=ui->tableWidget->item(rowIndex,0)->text();
    for(int i=0;i<model1->rowCount();i++)
    {
        QSqlRecord record=model1->record(i);
        qDebug()<<"delete major";
        qDebug()<<major;
        qDebug()<<record.value(4).toString();
        qDebug()<<record.value(3).toString();
        if(record.value(3).toString()==major)
        {
            QMessageBox::warning(this,"提示","该专业还有同学在读的哦~",QMessageBox::Yes);
            return;
        }
    }
    if (rowIndex != -1)
    {
        QSqlQuery query;
        query.prepare("delete from majorinformation where major=:major");
        query.bindValue(":major",major);
        bool ok=query.exec();
        if (ok)
        {
            qDebug()<<"shan chu cheng gong \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"shan chu shi bai\n";
        }
        ui->tableWidget->removeRow(rowIndex);
    }
}
void MajorInformation::changeSlot(int row,int coloum)
{
    qDebug()<<"you gai bai de dong xi ";
    //专业名称改变则表示重新加入一个专业
    if(coloum==0)
    {
        QMessageBox::warning(this,"警告","不支持专业名称修改!",QMessageBox::Yes);
        return;
    }
    if(row==ui->tableWidget->rowCount()&&ui->tableWidget->item(row,1)->text().isEmpty())
    {
        qDebug()<<"xin jia zhuan ye";
        return;
    }
    qDebug()<<coloum<<row;
    QString major=ui->tableWidget->item(row,0)->text();
    qDebug()<<major;
    QString requiredcourse=ui->tableWidget->item(row,1)->text();
    qDebug()<<requiredcourse;

    QSqlTableModel* modelMajor=new QSqlTableModel(this);
    modelMajor->setTable("majorinformation");
    modelMajor->select();
    QSqlQuery query;
    bool ok;
    ok=query.prepare("UPDATE majorinformation SET requiredcourse=:requiredcourse where major=:major");
    query.bindValue(":requiredcourse",requiredcourse);
    query.bindValue(":major", major);
    if (ok)
    {
        qDebug()<<"zhixing \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"meizhixing\n";
    }
    ok=query.exec();
    if (ok)
    {
        qDebug()<<"zhixing \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"meizhixing\n";
    }
}
void MajorInformation::on_SureButton_clicked()
{
    emit toStudentManage();//发送信号到studentmanage
    this->close();
}

void MajorInformation::on_CancelButton_clicked()
{
    this->close();
}
void MajorInformation::mySort(int coloum)
{
    ui->tableWidget->sortByColumn(coloum);
}
