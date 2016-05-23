#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H
#include "AddStudent.h"
#include "AddMajor.h"
#include "ChangePassword.h"
#include "MajorInformation.h"
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
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QComboBox>
#include <QTextCodec>
#include <QLabel>
namespace Ui {
class StudentManage;
}

class StudentManage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentManage(QWidget *parent = 0);
    ~StudentManage();
    bool studentinfoIsComplete(int row);
private slots:

    void on_ExitButton_clicked();

    void on_ReturnButton_clicked();

    //void on_InformationButton_clicked();

    //void on_SerachButton_clicked();

    void on_PasswordButton_clicked();
    //添加学生
    void on_AddButton_clicked();
    //添加学生的同时更新数据库
    void updataSlot(QTableWidgetItem* );
    //修改信息
    void on_ChangeButton_clicked();
    //排序
    void mySort(int);
    //全选
    void on_AllSelectButton_clicked();
    //删除选中
    void on_DeleteSelectedButton_clicked();
    //监测tablewidget中是否有信息改变
    void inforchanged(int,int);

    //void on_NameLineEdit_returnPressed();

    //void clearSlot();
    //点击专业后自动设置必修课
    void setCourseSlot(QString);
    //通过下拉选择改变性别信息
    void changeSexSlot(QString);
    //通过下拉选择改变专业信息
    void changeMajorSlot(QString);
    //专业信息
    void on_MajorInformationButton_2_clicked();
    //查询按钮
    void on_SelectButton_clicked();
    //查询
    void searchSlot();
    //提交按钮
    void on_SubmitButton_clicked();
    //显示当前时间
    void displayTime();
    //专业信息同步的槽，当在专业中进行添加修改后在主界面更新的槽
    void toChangeMajor();
    void comeLoginDialog(QString,QString);

signals:
    void toLoginDialog();
    void ReturnButtonSlot();
signals:
    void toAddStudent(QString,QString);
private:
    Ui::StudentManage *ui;
    QSqlDatabase db;
    AddStudent *add;
    //AddMajor *addmajor;
    ChangePassword *changepassword;
    QSqlTableModel *model;
    static int changeItemNum;
    static int addItemNum;
    static int deleteItemNum;
    //MajorInformation* majorinfo;
};

#endif // STUDENTMANAGE_H
