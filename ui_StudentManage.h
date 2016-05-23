/********************************************************************************
** Form generated from reading UI file 'StudentManage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMANAGE_H
#define UI_STUDENTMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentManage
{
public:
    QLabel *TimeLable;
    QLabel *UsernameLable;
    QTableWidget *tableWidget;
    QPushButton *SubmitButton;
    QToolBox *toolBox;
    QWidget *widget;
    QPushButton *MajorInformationButton_2;
    QPushButton *AddButton;
    QPushButton *ChangeButton;
    QPushButton *SelectButton;
    QPushButton *AllSelectButton;
    QPushButton *DeleteSelectedButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *PasswordButton;
    QPushButton *ReturnButton;
    QPushButton *ExitButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QLineEdit *StudentIDLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *NameLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *SexLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *MajorLineEdit;

    void setupUi(QWidget *StudentManage)
    {
        if (StudentManage->objectName().isEmpty())
            StudentManage->setObjectName(QStringLiteral("StudentManage"));
        StudentManage->resize(815, 577);
        TimeLable = new QLabel(StudentManage);
        TimeLable->setObjectName(QStringLiteral("TimeLable"));
        TimeLable->setGeometry(QRect(600, 10, 151, 20));
        TimeLable->setMinimumSize(QSize(151, 20));
        UsernameLable = new QLabel(StudentManage);
        UsernameLable->setObjectName(QStringLiteral("UsernameLable"));
        UsernameLable->setGeometry(QRect(420, 10, 151, 20));
        tableWidget = new QTableWidget(StudentManage);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(140, 80, 621, 351));
        SubmitButton = new QPushButton(StudentManage);
        SubmitButton->setObjectName(QStringLiteral("SubmitButton"));
        SubmitButton->setGeometry(QRect(680, 460, 81, 31));
        toolBox = new QToolBox(StudentManage);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 80, 101, 271));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 101, 245));
        MajorInformationButton_2 = new QPushButton(widget);
        MajorInformationButton_2->setObjectName(QStringLiteral("MajorInformationButton_2"));
        MajorInformationButton_2->setGeometry(QRect(0, 20, 91, 21));
        MajorInformationButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        AddButton = new QPushButton(widget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(0, 50, 91, 21));
        AddButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        ChangeButton = new QPushButton(widget);
        ChangeButton->setObjectName(QStringLiteral("ChangeButton"));
        ChangeButton->setGeometry(QRect(0, 80, 91, 21));
        ChangeButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        SelectButton = new QPushButton(widget);
        SelectButton->setObjectName(QStringLiteral("SelectButton"));
        SelectButton->setGeometry(QRect(0, 110, 91, 21));
        SelectButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        AllSelectButton = new QPushButton(widget);
        AllSelectButton->setObjectName(QStringLiteral("AllSelectButton"));
        AllSelectButton->setGeometry(QRect(0, 140, 91, 21));
        AllSelectButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        DeleteSelectedButton = new QPushButton(widget);
        DeleteSelectedButton->setObjectName(QStringLiteral("DeleteSelectedButton"));
        DeleteSelectedButton->setGeometry(QRect(0, 170, 91, 21));
        DeleteSelectedButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
"\n"
"\n"
""));
        toolBox->addItem(widget, QStringLiteral("Page 1"));
        layoutWidget = new QWidget(StudentManage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 40, 266, 16));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        PasswordButton = new QPushButton(layoutWidget);
        PasswordButton->setObjectName(QStringLiteral("PasswordButton"));
        PasswordButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
""));

        horizontalLayout_8->addWidget(PasswordButton);

        ReturnButton = new QPushButton(layoutWidget);
        ReturnButton->setObjectName(QStringLiteral("ReturnButton"));
        ReturnButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
""));

        horizontalLayout_8->addWidget(ReturnButton);

        ExitButton = new QPushButton(layoutWidget);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(0, 0, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(255, 170, 127); }\n"
""));

        horizontalLayout_8->addWidget(ExitButton);

        widget1 = new QWidget(StudentManage);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(230, 450, 361, 111));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label1 = new QLabel(widget1);
        label1->setObjectName(QStringLiteral("label1"));

        horizontalLayout->addWidget(label1);

        StudentIDLineEdit = new QLineEdit(widget1);
        StudentIDLineEdit->setObjectName(QStringLiteral("StudentIDLineEdit"));

        horizontalLayout->addWidget(StudentIDLineEdit);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        NameLineEdit = new QLineEdit(widget1);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));

        horizontalLayout_2->addWidget(NameLineEdit);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        SexLineEdit = new QLineEdit(widget1);
        SexLineEdit->setObjectName(QStringLiteral("SexLineEdit"));

        horizontalLayout_3->addWidget(SexLineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        MajorLineEdit = new QLineEdit(widget1);
        MajorLineEdit->setObjectName(QStringLiteral("MajorLineEdit"));

        horizontalLayout_4->addWidget(MajorLineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(StudentManage);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentManage);
    } // setupUi

    void retranslateUi(QWidget *StudentManage)
    {
        StudentManage->setWindowTitle(QApplication::translate("StudentManage", "Form", 0));
        TimeLable->setText(QApplication::translate("StudentManage", "<html><head/><body><p><br/></p></body></html>", 0));
        UsernameLable->setText(QApplication::translate("StudentManage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600; text-decoration: underline; color:#55007f;\">\347\256\241\347\220\206\345\221\230\346\202\250\345\245\275\357\274\232</span></p></body></html>", 0));
        SubmitButton->setText(QApplication::translate("StudentManage", "\346\217\220\344\272\244", 0));
#ifndef QT_NO_TOOLTIP
        toolBox->setToolTip(QApplication::translate("StudentManage", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        MajorInformationButton_2->setText(QApplication::translate("StudentManage", "\346\237\245\347\234\213\344\270\223\344\270\232\344\277\241\346\201\257", 0));
        AddButton->setText(QApplication::translate("StudentManage", "\346\267\273\345\212\240\345\255\246\347\224\237", 0));
        ChangeButton->setText(QApplication::translate("StudentManage", "\344\277\256\346\224\271\344\277\241\346\201\257", 0));
        SelectButton->setText(QApplication::translate("StudentManage", "\346\237\245\350\257\242\344\277\241\346\201\257", 0));
        AllSelectButton->setText(QApplication::translate("StudentManage", "\345\205\250\351\200\211", 0));
        DeleteSelectedButton->setText(QApplication::translate("StudentManage", "\345\210\240\351\231\244\351\200\211\344\270\255", 0));
        toolBox->setItemText(toolBox->indexOf(widget), QApplication::translate("StudentManage", "Page 1", 0));
        PasswordButton->setText(QApplication::translate("StudentManage", "   \344\277\256\346\224\271\345\257\206\347\240\201    ", 0));
        ReturnButton->setText(QApplication::translate("StudentManage", "   \346\263\250\351\224\200   ", 0));
        ExitButton->setText(QApplication::translate("StudentManage", "   \351\200\200\345\207\272\347\263\273\347\273\237    ", 0));
        label1->setText(QApplication::translate("StudentManage", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\255\246\345\217\267</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("StudentManage", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\247\223\345\220\215</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("StudentManage", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\346\200\247\345\210\253</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("StudentManage", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\344\270\223\344\270\232</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentManage: public Ui_StudentManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMANAGE_H
