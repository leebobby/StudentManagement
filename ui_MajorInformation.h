/********************************************************************************
** Form generated from reading UI file 'MajorInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAJORINFORMATION_H
#define UI_MAJORINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MajorInformation
{
public:
    QPushButton *AddButton;
    QPushButton *ChangeButton;
    QPushButton *DeleteButton;
    QPushButton *SureButton;
    QPushButton *CancelButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MajorInformation)
    {
        if (MajorInformation->objectName().isEmpty())
            MajorInformation->setObjectName(QStringLiteral("MajorInformation"));
        MajorInformation->resize(400, 286);
        AddButton = new QPushButton(MajorInformation);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(300, 50, 75, 23));
        ChangeButton = new QPushButton(MajorInformation);
        ChangeButton->setObjectName(QStringLiteral("ChangeButton"));
        ChangeButton->setGeometry(QRect(300, 90, 75, 23));
        DeleteButton = new QPushButton(MajorInformation);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(300, 130, 75, 23));
        SureButton = new QPushButton(MajorInformation);
        SureButton->setObjectName(QStringLiteral("SureButton"));
        SureButton->setGeometry(QRect(80, 230, 75, 23));
        CancelButton = new QPushButton(MajorInformation);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(190, 230, 75, 23));
        tableWidget = new QTableWidget(MajorInformation);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 256, 192));

        retranslateUi(MajorInformation);

        QMetaObject::connectSlotsByName(MajorInformation);
    } // setupUi

    void retranslateUi(QWidget *MajorInformation)
    {
        MajorInformation->setWindowTitle(QApplication::translate("MajorInformation", "Form", 0));
        AddButton->setText(QApplication::translate("MajorInformation", "\345\242\236\345\212\240\344\270\223\344\270\232", 0));
        ChangeButton->setText(QApplication::translate("MajorInformation", "\344\277\256\346\224\271\344\270\223\344\270\232", 0));
        DeleteButton->setText(QApplication::translate("MajorInformation", "\345\210\240\351\231\244\344\270\223\344\270\232", 0));
        SureButton->setText(QApplication::translate("MajorInformation", "\347\241\256\345\256\232", 0));
        CancelButton->setText(QApplication::translate("MajorInformation", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MajorInformation: public Ui_MajorInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAJORINFORMATION_H
