#include "StudentManage.h"
#include "ui_StudentManage.h"

int StudentManage::changeItemNum=0;
int StudentManage::addItemNum=0;
int StudentManage::deleteItemNum=0;
QTextCodec *codec= QTextCodec::codecForName("gbk");
StudentManage::StudentManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentManage)
{
    ui->setupUi(this);
    this->setMaximumSize(800,600);
    this->setMinimumSize(800,600);
    this->setWindowTitle("学生管理系统");
    //设置工具栏名称
    ui->toolBox->setItemText(0,"学生信息管理");
    //ui->UsernameLable->setText(" 管理员您好  ");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//选中整行
    //ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignHCenter);//选择对齐方式
    ui->tableWidget->setAlternatingRowColors(true);//设置没行变一色
    //设置时间
    QTimer *timer=new QTimer(this);
    displayTime();
    connect(timer,SIGNAL(timeout()),this,SLOT(displayTime()));
    timer->start(1000);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->TimeLable->setPalette(pe);
    ui->label1->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->StudentIDLineEdit->setVisible(false);
    ui->NameLineEdit->setVisible(false);
    ui->SexLineEdit->setVisible(false);
    ui->MajorLineEdit->setVisible(false);

    //退出系统按钮信号与槽连接
    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(on_ExitButton_clicked()));
    //点击列标进行排序
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(mySort(int)));
    this->db=QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<db.isValid();
    db.setDatabaseName("student.db");//设置为相对路径

    if(!db.open())
    {
        qDebug()<<"数据库打开失败!";
        return ;
    }
    else
        qDebug()<<"数据库打开成功!";
    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    int recordcount=model->rowCount();
    //因为tableWidget需要提前规定好行数与列数
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(recordcount); //动态设置行数
    QStringList list;
    list<<"选择"<<"学号"<<"姓名"<<"性别"<<"专业"<<"必修";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setColumnWidth(0,30);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,40);
    ui->tableWidget->setColumnWidth(4,180);
    ui->tableWidget->setColumnWidth(5,170);
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
    int i=0;
    for(i=0;i<model->rowCount();i++)
    {
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        QComboBox *comBoxSex = new QComboBox();
        comBoxSex->addItem("null");
        comBoxSex->addItem("M");
        comBoxSex->addItem("F");
        QComboBox *comBoxMajor = new QComboBox();

        QSqlTableModel* modelMajor=new QSqlTableModel(this);
        modelMajor->setTable("majorinformation");
        modelMajor->select();
        comBoxMajor->addItem("null");
        for(int j=0;j<modelMajor->rowCount();j++)
        {
            QSqlRecord recordMajor=modelMajor->record(j);
            comBoxMajor->addItem(recordMajor.value(0).toString());
        }
        QSqlRecord record=model->record(i);
        QString studentid = record.value(0).toString();
        QString name = record.value(1).toString();
        QString sex = record.value(2).toString();
        QString requiredcourse=record.value(4).toString();
        QString major = record.value(3).toString();
        ui->tableWidget->setItem(i,0,check); //插入复选框
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(studentid));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(name));
        //ui->tableWidget->setItem(i,3,new QTableWidgetItem(sex));
        ui->tableWidget->setCellWidget(i,3,comBoxSex);//插入combobox性别
        QWidget* widget=ui->tableWidget->cellWidget(i,3);
        QComboBox* comBoxSex1=(QComboBox*) widget;
        if(sex.compare(codec->toUnicode("F")))
        {
            comBoxSex1->setCurrentIndex(1);
        }
        else
            comBoxSex1->setCurrentIndex(2);
        ui->tableWidget->setCellWidget(i,4,comBoxMajor);
        widget=ui->tableWidget->cellWidget(i,4);
        QComboBox* comBoxMajor1=(QComboBox*) widget;
        int index=comBoxMajor1->findText(major);

        comBoxMajor1->setCurrentIndex(index);
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(requiredcourse));
        connect(comBoxMajor1,SIGNAL(currentTextChanged(QString)),this,SLOT(setCourseSlot(QString)));
        ui->tableWidget->item(i,5)->setFlags(Qt::NoItemFlags);
    }
   //有姓名和学号信息改变时候
    // connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(inforchanged(int,int)));
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        QComboBox* comBoxSex=(QComboBox*) ui->tableWidget->cellWidget(i,3);
        QComboBox* comBoxMajor=(QComboBox*) ui->tableWidget->cellWidget(i,4);
        connect(comBoxMajor,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeMajorSlot( QString)));
        connect(comBoxSex,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeSexSlot( QString)));
    }
    MajorInformation *majorinfo=new MajorInformation;
    connect(majorinfo,SIGNAL(toStudentManage()),this,SLOT(toChangeMajor()));
}

void StudentManage::inforchanged(int row,int coloum)
{
    qDebug()<<"you gai bai de dong xi ";
    //如果是复选框改变则不做动作
    changeItemNum++;
    if(coloum==0)
        return;
    if(row==ui->tableWidget->rowCount()&&ui->tableWidget->item(row,2)->text().isEmpty())
    {
        qDebug()<<"xin jia xue sheng";
        return;
    }
    qDebug()<<coloum<<row;
    QString studentid=ui->tableWidget->item(row,1)->text();
    qDebug()<<studentid;
    QString name=ui->tableWidget->item(row,2)->text();
    qDebug()<<name;
    QWidget* widget=ui->tableWidget->cellWidget(row,3);
    widget=ui->tableWidget->cellWidget(row,4);
    QComboBox* comBoxMajor1=(QComboBox*) widget;
    QString major = comBoxMajor1->currentText();
    widget=ui->tableWidget->cellWidget(row,3);
    QComboBox* comBoxSex1=(QComboBox*) widget;
    QString sex=comBoxSex1->currentText();
    qDebug()<<sex;
    QSqlTableModel* modelMajor=new QSqlTableModel(this);
    modelMajor->setTable("majorinformation");
    modelMajor->select();
    QString requiredcourse;
    for(int j=0;j<modelMajor->rowCount();j++)
    {
        QSqlRecord recordMajor=modelMajor->record(j);
        if(recordMajor.value(0).toString()==major)
        {
             requiredcourse= recordMajor.value(1).toString();
        }
    }
    QSqlQuery query;
    bool ok;
    switch(coloum)
    {
    case 1:
    {
        query.bindValue(":studentID",studentid);
        query.bindValue(":studentName", name);
        ok=query.prepare("UPDATE studentinformation SET studentid=:studentID where studentname=:studentName");
        ok=query.exec();
        break;
    }
    case 2:
    {
        ok=query.prepare("UPDATE studentinformation SET studentname=:studentName where studentid=:studentID");
        if (ok)
        {
            qDebug()<<"zhixing \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"meizhixing\n";
        }
        qDebug()<<"laile";
        query.bindValue(":studentID",studentid);
        query.bindValue(":studentName", name);
        ok=query.exec();
        break;
    }
    default: return;
    }
    if (ok)
    {
        qDebug()<<"xiu gai cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"xiu gai shi bai\n";
    }
}
void StudentManage::changeMajorSlot(QString)
{
    qDebug()<<"laile xiu gai major";
    changeItemNum++;
    QComboBox* comBoxMajor=(QComboBox*)sender();
    qDebug()<<comBoxMajor->currentText();
    int rowcount=ui->tableWidget->rowCount();
    int index=-1;
    for(int i=0;i<rowcount;i++)
    {
        if(comBoxMajor==(QComboBox*)(ui->tableWidget->cellWidget(i,4)))
        {
            index=i;
            break;
        }
    }
    qDebug()<<index;
    if(index>=rowcount)
        return;
    int k;
    QSqlRecord record;
    for(k=0;k<index;k++)
    {
         record=model->record(k);
    }
    record=model->record(k);
    QString studentid=record.value(0).toString();
    qDebug()<<studentid;
    QString major=comBoxMajor->currentText();
    QSqlTableModel* modelMajor=new QSqlTableModel(this);
    modelMajor->setTable("majorinformation");
    modelMajor->select();
    QString requiredcourse;
    for(int j=0;j<modelMajor->rowCount();j++)
    {
        QSqlRecord recordMajor=modelMajor->record(j);
        if(recordMajor.value(0).toString()==major)
        {
             requiredcourse= recordMajor.value(1).toString();
        }
    }
    QSqlQuery query;
    bool ok;
    ok=query.prepare("UPDATE studentinformation SET major=:major,RequiredCourse=:RequireCourse where studentid=:studentID");
    if (ok)
    {
        qDebug()<<"xiu gai cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"xiu gai shi bai\n";
    }
    query.bindValue(":studentID",studentid);
    query.bindValue(":major",major);
    query.bindValue(":RequireCourse", requiredcourse);
    ok=query.exec();
    if (ok)
    {
        qDebug()<<"xiu gai cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"xiu gai shi bai\n";
    }
    ui->tableWidget->setItem(index,5,new QTableWidgetItem(requiredcourse));

}
void StudentManage::changeSexSlot(QString)
{
    changeItemNum++;
    qDebug()<<"laile";
    QComboBox* comBoxSex=(QComboBox*)sender();
    qDebug()<<comBoxSex->currentText();
    int rowcount=ui->tableWidget->rowCount();
    int index=-1;
    for(int i=0;i<rowcount;i++)
    {
        if(comBoxSex==(QComboBox*)(ui->tableWidget->cellWidget(i,3)))
        {
            index=i;
            break;
        }
    }
    qDebug()<<index;
    if(index>=rowcount)
        return;
    int k;
    QSqlRecord record;
    for(k=0;k<index;k++)
    {
         record=model->record(k);
    }
    record=model->record(k);
    QString studentid=record.value(0).toString();
    qDebug()<<studentid;
    QString sex=comBoxSex->currentText();
    QSqlQuery query;
    bool ok;
    ok=query.prepare("UPDATE studentinformation SET sex=:sex where studentid=:studentID");
    if (ok)
    {
        qDebug()<<"xiu gai cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"xiu gai shi bai\n";
    }
    query.bindValue(":studentID",studentid);
    query.bindValue(":sex", sex);
    ok=query.exec();
    qDebug()<<"xing bie xiu gai";

    /******************
    if(temp->column()==3)//性别改变
    {
        qDebug()<<"laile";
        int rowcount=temp->row();
        QSqlQuery query;
        bool ok;
        QComboBox* sexcombox=(QComboBox*)temp;
        QString studentid=ui->tableWidget->item(rowcount,1)->text();
        QString sex=sexcombox->currentText();
        ok=query.prepare("UPDATE studentinformation SET sex=:sex where studentid=:studentID");
        if (ok)
        {
            qDebug()<<"zhixing \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"meizhixing\n";
        }
        qDebug()<<"laile";
        query.bindValue(":studentID",studentid);
        query.bindValue(":sex", sex);
        ok=query.exec();
        if (ok)
        {
            qDebug()<<"xiu gai cheng gong \n";
        }
        else
        {
            qDebug()<<query.lastError();
            qDebug()<<"xiu gai shi bai\n";
        }

    }
    *************/
}
StudentManage::~StudentManage()
{
    delete ui;
}

void StudentManage::setCourseSlot(QString)
{
    qDebug()<<"hellooo";
    QSqlTableModel* modelMajor=new QSqlTableModel(this);
    modelMajor->setTable("majorinformation");
    modelMajor->select();
    QString requiredcourse;
    int rowcount=ui->tableWidget->rowCount();
    QWidget* widget=ui->tableWidget->cellWidget(rowcount-1,3);
    widget=ui->tableWidget->cellWidget(rowcount-1,4);
    QComboBox* comBoxMajor1=(QComboBox*) widget;
    QString major = comBoxMajor1->currentText();
    for(int j=0;j<modelMajor->rowCount();j++)
    {
        QSqlRecord recordMajor=modelMajor->record(j);
        if(recordMajor.value(0).toString()==major)
        {
             requiredcourse= recordMajor.value(1).toString();
        }
    }
    ui->tableWidget->setItem(rowcount-1,5,new QTableWidgetItem(requiredcourse));
}
void StudentManage::comeLoginDialog(QString name,QString num)
{
   // ui->teachernameline->setText(username);
}

void StudentManage::on_ExitButton_clicked()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        this->close();
        delete this;
    }
}

void StudentManage::on_ReturnButton_clicked()
{
    if(QMessageBox::question(this,"提示","是否注销用户?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        emit toLoginDialog();
        delete this;
    }
}

void StudentManage::on_PasswordButton_clicked()
{
    this->changepassword=new ChangePassword;
    this->changepassword->show();
}

void StudentManage::on_AddButton_clicked()
{
    /*************************************
     * 方法一：重新开一个窗口添加
    this->add=new AddStudent;
    this->add->show();
    **********************************/
    //方法二：直接在table中添加
    //在最下方插入一行

    ui->label1->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->StudentIDLineEdit->setVisible(false);
    ui->NameLineEdit->setVisible(false);
    ui->SexLineEdit->setVisible(false);
    ui->MajorLineEdit->setVisible(false);
    int rowcount=ui->tableWidget->rowCount();
/**************
    if(ui->tableWidget->item(rowcount-1,1)==NULL||(ui->tableWidget->item(rowcount-1,2)&&ui->tableWidget->item(rowcount-1,2)->text().isEmpty()))
    {
        QMessageBox::warning(this,"警告","一个一个来，别急亲~",QMessageBox::Yes);
        return;
    }
    ***********/
    if(!studentinfoIsComplete(rowcount))
    {
        QMessageBox::warning(this,"警告","一个一个来，别急亲~",QMessageBox::Yes);
        return;
    }

    disconnect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(inforchanged(int,int)));
    qDebug()<<"hello";
    //ui->StudentIDLineEdit->setVisible(true);
    //ui->NameLineEdit->setVisible(true);
    //ui->label1->setVisible(true);
    //ui->label_3->setVisible(true);
   // int rowcount=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowcount);
    QTableWidgetItem *check = new QTableWidgetItem();
    check->setCheckState(Qt::Unchecked);
    QComboBox *comBoxSex = new QComboBox();
    comBoxSex->addItem(" ");
    comBoxSex->addItem("M");
    comBoxSex->addItem("F");
    QComboBox *comBoxMajor = new QComboBox();
    QSqlTableModel* modelMajor=new QSqlTableModel(this);
    modelMajor->setTable("majorinformation");
    modelMajor->select();
    qDebug()<<"hello1";
    comBoxMajor->addItem("null");
    for(int j=0;j<modelMajor->rowCount();j++)
    {
        QSqlRecord recordMajor=modelMajor->record(j);
        comBoxMajor->addItem(recordMajor.value(0).toString());
    }
    ui->tableWidget->setItem(rowcount,0,check); //插入复选框
    ui->tableWidget->setCellWidget(rowcount,3,comBoxSex);//插入combobox性别
    ui->tableWidget->setCellWidget(rowcount,4,comBoxMajor);//插入专业选择
    //connect(ui->NameLineEdit,SIGNAL(returnPressed()),this,SLOT(on_NameLineEdit_returnPressed()));//使用下面lineedit两行输入新信息
    //connect(ui->NameLineEdit,SIGNAL(returnPressed()),this,SLOT(clearSlot()));
    connect(comBoxMajor,SIGNAL(currentTextChanged(QString)),this,SLOT(setCourseSlot(QString)));
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(updataSlot(QTableWidgetItem* )));
    //ui->tableWidget->item(rowcount-1,5)->setFlags(Qt::NoItemFlags);
}
void StudentManage::updataSlot(QTableWidgetItem* temp)
{
    //bug 如果先选专业会出现学生已经存在的问题
    qDebug()<<"updataslot";
    qDebug()<<temp->row();
    if(temp->column()==1&&temp->text().length()!=8)
    {
        QMessageBox::warning(this,"错误","学号长度为8哦~",QMessageBox::Yes);
        temp->text().clear();
        return;
    }
    //如果不是第6列就直接返回不提交
    if(temp->column()!=5)
        return;
    int row=temp->row();
    //如果是第6列但是前面信息还是空也不提交
    if(temp->column()==5)
    {
        if(ui->tableWidget->item(row,1)==NULL||(ui->tableWidget->item(row,1)&&ui->tableWidget->item(row,1)->text().isEmpty()))
        {
            QMessageBox::warning(this,"警告","请先填写学号哦~",QMessageBox::Yes);
            return;
        }
        else if(ui->tableWidget->item(row,2)==NULL||(ui->tableWidget->item(row,2)&&ui->tableWidget->item(row,2)->text().isEmpty()))
        {
            QMessageBox::warning(this,"警告","请先填写名字哦~",QMessageBox::Yes);
            return;
        }
    }

    int rowcount=ui->tableWidget->rowCount();
    if(temp->row()==rowcount-1)
    qDebug()<<"gaibian";

    QString name=ui->tableWidget->item(rowcount-1,2)->text();
    QWidget* widget=ui->tableWidget->cellWidget(rowcount-1,3);
    widget=ui->tableWidget->cellWidget(rowcount-1,4);
    QString studentid=ui->tableWidget->item(rowcount-1,1)->text();
    if(name.isEmpty()||studentid.isEmpty())
        return;

    QComboBox* comBoxMajor1=(QComboBox*) widget;
    QString major = comBoxMajor1->currentText();
    widget=ui->tableWidget->cellWidget(rowcount-1,3);
    QComboBox* comBoxSex1=(QComboBox*) widget;
    QString sex=comBoxSex1->currentText();

    QString requiredcourse=ui->tableWidget->item(rowcount-1,5)->text();
    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    for(int i=0;i<model->rowCount();i++)
    {
        QSqlRecord record=model->record(i);
        qDebug()<<record.value(0);
        if(record.value(0)==studentid)
        {
            QMessageBox::warning(this,"警告","该学生信息已经存在了哦~",QMessageBox::Yes);
            ui->tableWidget->removeRow(rowcount-1);
            return ;
        }
    }
    QSqlQuery query;
    bool ok=query.prepare("INSERT INTO studentinformation (studentID, studentName, sex, major, RequiredCourse ) VALUES (:studentID, :studentName, :sex,:major,:RequireCourse)");
    query.bindValue(":studentID",studentid);
    query.bindValue(":studentName", name);
    query.bindValue(":sex", sex);
    query.bindValue(":major",major);
    query.bindValue(":RequireCourse", requiredcourse);
    ok=query.exec();
    if (ok)
    {
        addItemNum++;
        qDebug()<<"cha ru cheng gong \n";
    }
    else
    {
        qDebug()<<query.lastError();
        qDebug()<<"cha ru shi bai\n";
    }
}
/***********************************************
 * 在添加一个学生的一种方法中用到
void StudentManage::clearSlot()
{
    ui->NameLineEdit->clear();
    ui->StudentIDLineEdit->clear();
}
*************************************************/
void StudentManage::on_ChangeButton_clicked()
{
    ui->label1->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->StudentIDLineEdit->setVisible(false);
    ui->NameLineEdit->setVisible(false);
    ui->SexLineEdit->setVisible(false);
    ui->MajorLineEdit->setVisible(false);
    connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(inforchanged(int,int)));
}
/*********************
void StudentManage::on_MajorInformationButton_clicked()
{
    this->addmajor=new AddMajor;
    this->addmajor->show();
}
******************************/
/********************************************
 * 通过按钮实现显示的功能
void StudentManage::on_ShowInformation_clicked()
{
    //add=new AddStudent();
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("E:\\Study\\2015software\\software\\qtproject\\StudentManagementSystem\\student.db");
    if(!db.open())
    {
        qDebug()<<"数据库打开失败!";
    }
    else
        qDebug()<<"数据库打开成功!";
    QSqlQuery query;
    //QString sq = QString("CREATE TABLE studentInformation(studentID char(8) PRIMARY KEY,studentName varchar(20) ,sex varchar(2),major varchar(20),RequireCourse varchar(20))");
   // query.exec(sq);
    QString s = QString("select studentID, studentName, sex, major, RequireCourse from studentInfomation");
    query.exec(s);
    QSqlQueryModel *model=new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("select * from studentinformation"),this->db);
    //QSqlTableModel *model=new QSqlTableModel(ui->tableView);
    //model->setTable("studentInfomation");
    //model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("性别"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("专业"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("必修"));

    TableModel *pModel = new TableModel(this);
    ui->tableView->setModel(pModel);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //QAbstractTableModel table_model;
    QHeaderView *header = ui->tableView->horizontalHeader();
    ui->tableView->setHorizontalHeader(header);
    header->resizeSection(0,100);
    header->resizeSection(1,60);
    header->resizeSection(2,50);
    header->resizeSection(3,120);
    header->resizeSection(4,100);
    ui->tableView->horizontalHeader()->sectionResizeMode(QHeaderView::Fixed);
    //header->setStretchLastSection(true);
    //header->setResizeContentsPrecision()
    //ui->tableView->show();
    db.close();
}
*/
//对列进行排序的槽
void StudentManage::mySort(int coloum)
{
    ui->tableWidget->sortByColumn(coloum);
}
//全选的槽
void StudentManage::on_AllSelectButton_clicked()
{
    int rows=ui->tableWidget->rowCount();
    for(int i=0;i<rows;i++)
        ui->tableWidget->item(i,0)->setCheckState(Qt::Checked);
}
//删除选中的槽
void StudentManage::on_DeleteSelectedButton_clicked()
{
    /*******************************************
     * 方法一：通过行选中
    int rowIndex = ui->tableWidget->currentRow();
    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();

    QString major=ui->tableWidget->item(rowIndex,1)->text();
    if (rowIndex != -1)
    {
        QSqlQuery query;
        query.prepare("delete from studentinformation where studentid=:major");
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
    *******************************************************/
    //方法二：通过复选框选中

    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    qDebug()<<"come here";
    while(ui->tableWidget->rowCount()!=0)
    {//注意这里的选中多个的情况下删除会出现i失效的情况！！
        int row=ui->tableWidget->rowCount();
            qDebug()<<row;
        int i;
        for(i=0;i<row;i++)
        {
            qDebug()<<i;
            //qDebug()<<ui->tableWidget->item(i,1)->text();
            if(ui->tableWidget->item(i,0)->checkState()==Qt::Checked)
            {
                //如果名字或者学号为空那么就直接删掉这行返回
                //这里要注意的是在使用指针之前要先判断是不是空
                if(ui->tableWidget->item(i,1)==NULL||(ui->tableWidget->item(i,1))&&ui->tableWidget->item(i,1)->text().isEmpty())
                {
                    ui->tableWidget->removeRow(i);
                    break;
                }
                if(ui->tableWidget->item(i,2)==NULL||(ui->tableWidget->item(i,2))&&ui->tableWidget->item(i,2)->text().isEmpty())
                {
                    ui->tableWidget->removeRow(i);
                    break;
                }
                qDebug()<<"come here3";
                int index=i;
                if(ui->tableWidget->item(i,1)->text().isEmpty()||ui->tableWidget->item(i,2)->text().isEmpty())
                {
                    qDebug()<<"ru guo id he name wei kong";
                    ui->tableWidget->removeRow(index);
                    break;
                }
                QSqlQuery query;
                query.prepare("delete from studentinformation where studentID=:studentID");
                query.bindValue(":studentID",ui->tableWidget->item(i,1)->text());
                qDebug()<<i<<ui->tableWidget->item(i,1)->text();
                qDebug()<<"delete3";
                bool ok=query.exec();
                if (ok)
                {
                    deleteItemNum++;
                     qDebug()<<"shan chu cheng gong \n";
                }
                else
                {
                     qDebug()<<query.lastError();
                     qDebug()<<"shan chu shi bai\n";
                }
                ui->tableWidget->removeRow(index);
                break;
                qDebug()<<"come here4";
            }
        }
        if(i==row)
            break;
    }
}
/****************************************************
 * 添加学生方法的一种
void StudentManage::on_NameLineEdit_returnPressed()
{
    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    QString newname =ui->NameLineEdit->text();
    QString newid=ui->StudentIDLineEdit->text();
    qDebug()<<newname;
    qDebug()<<newid;
    for(int i=0;i<model->rowCount();i++)
    {
        qDebug()<<i;
        QSqlRecord record=model->record(i);
        if(record.value(1)==newname||
                record.value(0)==newid)
        {
            QMessageBox::information(this,"提示","该学生已经存在！",QMessageBox::Yes);
            return;
        }
    }
    int rowcount=ui->tableWidget->rowCount();
    ui->tableWidget->setItem(rowcount-1,2,new QTableWidgetItem(newname));
    qDebug()<<"hello";
    ui->tableWidget->setItem(rowcount-1,1,new QTableWidgetItem(newid));
}
**********************************************************************/
//查看专业信息的槽
void StudentManage::on_MajorInformationButton_2_clicked()
{
    //this->majorinfo=new MajorInformation;
    //this->majorinfo->show();
    MajorInformation *majorinfo=new MajorInformation;
    majorinfo->show();
}
//查询信息按钮的槽
void StudentManage::on_SelectButton_clicked()
{
    QMessageBox::information(this,"提示","请输入姓名或者学号按回车查询~",QMessageBox::Yes);
    ui->label1->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->StudentIDLineEdit->setVisible(true);
    ui->NameLineEdit->setVisible(true);
    ui->SexLineEdit->setVisible(true);
    ui->MajorLineEdit->setVisible(true);
    //通过输入学生的名字或者学号进行查询
    connect(ui->StudentIDLineEdit,SIGNAL(returnPressed()),this,SLOT(searchSlot()));
    connect(ui->NameLineEdit,SIGNAL(returnPressed()),this,SLOT(searchSlot()));
}
//查询信息的槽
void StudentManage::searchSlot()
{
    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    QString name =ui->NameLineEdit->text();
    QString id=ui->StudentIDLineEdit->text();
    if(!name.isEmpty())
    {
        int i;
        for(i=0;i<model->rowCount();i++)
        {
            qDebug()<<i;
            QSqlRecord record=model->record(i);
            if(record.value(1).toString()==name)
            {
                ui->StudentIDLineEdit->setText(record.value(0).toString());
                QString sex=record.value(2).toString();
                if(sex=="M")
                   ui->SexLineEdit->setText(QString("男生"));
                else if(sex=="F")
                    ui->SexLineEdit->setText(QString("女生"));
                ui->MajorLineEdit->setText(record.value(3).toString());
                break;
            }
        }
        if(i>=model->rowCount())
        {
            QMessageBox::warning(this,"警告!","未找到该学生的信息哦~",QMessageBox::Yes);
                return;
        }
    }
    else if(!id.isEmpty())
    {
         int i;
         for(i=0;i<model->rowCount();i++)
         {
             QSqlRecord record=model->record(i);
             if(record.value(0).toString()==id)
             {
                  ui->NameLineEdit->setText(record.value(1).toString());
                  QString sex=record.value(2).toString();
                  if(sex=="M")
                     ui->SexLineEdit->setText(QString("男生"));
                  else if(sex=="F")
                      ui->SexLineEdit->setText(QString("女生"));
                  ui->MajorLineEdit->setText(record.value(3).toString());
                  break;
             }
         }
         qDebug()<<i;
         if(i>=model->rowCount())
         {
              QMessageBox::warning(this,"警告!","未找到该学生的信息哦~",QMessageBox::Yes);
              return;
         }
    }
}
//提交的槽
void StudentManage::on_SubmitButton_clicked()
{
    qDebug()<<changeItemNum<<addItemNum<<deleteItemNum;
    QString changestr=QString::number(changeItemNum,10);
    QString addstr=QString::number(addItemNum,10);
    QString deletestr=QString::number(deleteItemNum,10);
    QString str1="修改条目个数:"+changestr;
    QString str2="增加学生人数:"+addstr;
    QString str3="删除学生人数:"+deletestr;
    QString str=str1+"\n"+str2+"\n"+str3;
    QMessageBox::question(this,"消息",str,QMessageBox::Yes);

}
//显示时间的槽
void StudentManage::displayTime()
{
    QDateTime dt;
    QTime time;
    QDate date;
    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());

    QString currentDate=dt.toString("yyyy:MM:dd:hh:mm:ss");
    ui->TimeLable->setText(currentDate);
}
//专业信息同步的槽，当在专业中进行添加修改后在主界面更新的槽
void StudentManage::toChangeMajor()
{
    qDebug()<<"wo shi lai geng xin combobox";

    model=new QSqlTableModel(this);
    model->setTable("studentinformation");
    model->select();
    int i=0;
    for(i=0;i<model->rowCount();i++)
    {
        QComboBox *comBoxMajor = new QComboBox();
        QSqlTableModel* modelMajor=new QSqlTableModel(this);
        modelMajor->setTable("majorinformation");
        modelMajor->select();
        for(int j=0;j<modelMajor->rowCount();j++)
        {
            QSqlRecord recordMajor=modelMajor->record(j);
            comBoxMajor->addItem(recordMajor.value(0).toString());
        }
        QSqlRecord record=model->record(i);
        QString major = record.value(3).toString();
        ui->tableWidget->setCellWidget(i,4,comBoxMajor);
        QWidget* widget=ui->tableWidget->cellWidget(i,4);
        QComboBox* comBoxMajor1=(QComboBox*) widget;
        int index=comBoxMajor1->findText(major);

        comBoxMajor1->setCurrentIndex(index);
    }
}
//判断信息是否完全的成员函数
bool StudentManage::studentinfoIsComplete(int rowcount)
{
    qDebug()<<"here";
    if(ui->tableWidget->item(rowcount-1,1)==NULL||(ui->tableWidget->item(rowcount-1,1)&&ui->tableWidget->item(rowcount-1,1)->text().isEmpty()))
    {
        qDebug()<<"here1";
        return false;
    }
    if(ui->tableWidget->item(rowcount-1,2)==NULL||(ui->tableWidget->item(rowcount-1,2)&&ui->tableWidget->item(rowcount-1,2)->text().isEmpty()))
    {
        qDebug()<<"here2";
        return false;
    }
    QWidget* widget=ui->tableWidget->cellWidget(rowcount-1,3);
    QComboBox* comBox=(QComboBox*) widget;
    if(ui->tableWidget->item(rowcount-1,3)&&comBox->currentText()==" ")
    {

        if(ui->tableWidget->item(rowcount-1,3)&&comBox->currentText()=="null")
            qDebug()<<"here31";
        return false;
    }
    widget=ui->tableWidget->cellWidget(rowcount-1,4);
    comBox=(QComboBox*) widget;
    if(ui->tableWidget->item(rowcount-1,4)&&comBox->currentText()=="null")
    {
        qDebug()<<"here4";
        return false;
     }

    return true;//信息输入完全
}
