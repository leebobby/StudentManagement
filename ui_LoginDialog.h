/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *QuitButton;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QLabel *TitileLabel;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *IDLabel;
    QLabel *PasswordLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *IDEdit;
    QLineEdit *PasswordEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        layoutWidget_2 = new QWidget(LoginDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 195, 341, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LoginButton = new QPushButton(layoutWidget_2);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));

        horizontalLayout->addWidget(LoginButton);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        RegisterButton = new QPushButton(layoutWidget_2);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));

        horizontalLayout->addWidget(RegisterButton);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        QuitButton = new QPushButton(layoutWidget_2);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        horizontalLayout->addWidget(QuitButton);

        layoutWidget_3 = new QWidget(LoginDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(47, 35, 306, 30));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_10 = new QSpacerItem(58, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        TitileLabel = new QLabel(layoutWidget_3);
        TitileLabel->setObjectName(QStringLiteral("TitileLabel"));
        TitileLabel->setScaledContents(false);

        horizontalLayout_4->addWidget(TitileLabel);

        horizontalSpacer_11 = new QSpacerItem(58, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 90, 201, 81));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        IDLabel = new QLabel(widget);
        IDLabel->setObjectName(QStringLiteral("IDLabel"));

        verticalLayout->addWidget(IDLabel);

        PasswordLabel = new QLabel(widget);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        verticalLayout->addWidget(PasswordLabel);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        IDEdit = new QLineEdit(widget);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));

        verticalLayout_2->addWidget(IDEdit);

        PasswordEdit = new QLineEdit(widget);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));

        verticalLayout_2->addWidget(PasswordEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
#ifndef QT_NO_TOOLTIP
        LoginButton->setToolTip(QApplication::translate("LoginDialog", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        LoginButton->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        RegisterButton->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", 0));
        QuitButton->setText(QApplication::translate("LoginDialog", "\351\200\200\345\207\272", 0));
        TitileLabel->setText(QApplication::translate("LoginDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#00007f;\">\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", 0));
        IDLabel->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", 0));
        PasswordLabel->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
