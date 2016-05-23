/********************************************************************************
** Form generated from reading UI file 'ChangePassword.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SureButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *userNameLabel;
    QLabel *newPasswordLabel;
    QLabel *sureNewPasswordLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *userNameLineEdit;
    QLineEdit *newPasswordLineEdit;
    QLineEdit *SureNewPasswordLineEdit;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QStringLiteral("ChangePassword"));
        ChangePassword->resize(356, 236);
        widget = new QWidget(ChangePassword);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 180, 204, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SureButton = new QPushButton(widget);
        SureButton->setObjectName(QStringLiteral("SureButton"));

        horizontalLayout_2->addWidget(SureButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        CancelButton = new QPushButton(widget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);

        widget1 = new QWidget(ChangePassword);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 30, 281, 121));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        userNameLabel = new QLabel(widget1);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));

        verticalLayout_2->addWidget(userNameLabel);

        newPasswordLabel = new QLabel(widget1);
        newPasswordLabel->setObjectName(QStringLiteral("newPasswordLabel"));

        verticalLayout_2->addWidget(newPasswordLabel);

        sureNewPasswordLabel = new QLabel(widget1);
        sureNewPasswordLabel->setObjectName(QStringLiteral("sureNewPasswordLabel"));

        verticalLayout_2->addWidget(sureNewPasswordLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        userNameLineEdit = new QLineEdit(widget1);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));

        verticalLayout->addWidget(userNameLineEdit);

        newPasswordLineEdit = new QLineEdit(widget1);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));

        verticalLayout->addWidget(newPasswordLineEdit);

        SureNewPasswordLineEdit = new QLineEdit(widget1);
        SureNewPasswordLineEdit->setObjectName(QStringLiteral("SureNewPasswordLineEdit"));

        verticalLayout->addWidget(SureNewPasswordLineEdit);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Form", 0));
        SureButton->setText(QApplication::translate("ChangePassword", "\347\241\256\345\256\232", 0));
        CancelButton->setText(QApplication::translate("ChangePassword", "\345\217\226\346\266\210", 0));
        userNameLabel->setText(QApplication::translate("ChangePassword", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", 0));
        newPasswordLabel->setText(QApplication::translate("ChangePassword", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\346\226\260\345\257\206\347\240\201</span></p></body></html>", 0));
        sureNewPasswordLabel->setText(QApplication::translate("ChangePassword", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
