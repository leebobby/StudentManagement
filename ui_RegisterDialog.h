/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

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

class Ui_RegisterDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *TitleLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *StudentNumberLabel;
    QLabel *NameLabel;
    QLabel *PasswordLabel;
    QLabel *SurePasswordLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QLineEdit *PasswordLineEdit;
    QLineEdit *SurePasswordLineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *CodeLabel;
    QLineEdit *CodeLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SureButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(274, 307);
        layoutWidget = new QWidget(RegisterDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 221, 251));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        TitleLabel = new QLabel(layoutWidget);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));

        verticalLayout_4->addWidget(TitleLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        StudentNumberLabel = new QLabel(layoutWidget);
        StudentNumberLabel->setObjectName(QStringLiteral("StudentNumberLabel"));

        verticalLayout->addWidget(StudentNumberLabel);

        NameLabel = new QLabel(layoutWidget);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        verticalLayout->addWidget(NameLabel);

        PasswordLabel = new QLabel(layoutWidget);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        verticalLayout->addWidget(PasswordLabel);

        SurePasswordLabel = new QLabel(layoutWidget);
        SurePasswordLabel->setObjectName(QStringLiteral("SurePasswordLabel"));

        verticalLayout->addWidget(SurePasswordLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        UserNameLineEdit = new QLineEdit(layoutWidget);
        UserNameLineEdit->setObjectName(QStringLiteral("UserNameLineEdit"));

        verticalLayout_2->addWidget(UserNameLineEdit);

        NameLineEdit = new QLineEdit(layoutWidget);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));

        verticalLayout_2->addWidget(NameLineEdit);

        PasswordLineEdit = new QLineEdit(layoutWidget);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        verticalLayout_2->addWidget(PasswordLineEdit);

        SurePasswordLineEdit = new QLineEdit(layoutWidget);
        SurePasswordLineEdit->setObjectName(QStringLiteral("SurePasswordLineEdit"));

        verticalLayout_2->addWidget(SurePasswordLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        CodeLabel = new QLabel(layoutWidget);
        CodeLabel->setObjectName(QStringLiteral("CodeLabel"));

        verticalLayout_3->addWidget(CodeLabel);

        CodeLineEdit = new QLineEdit(layoutWidget);
        CodeLineEdit->setObjectName(QStringLiteral("CodeLineEdit"));

        verticalLayout_3->addWidget(CodeLineEdit);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SureButton = new QPushButton(layoutWidget);
        SureButton->setObjectName(QStringLiteral("SureButton"));

        horizontalLayout_2->addWidget(SureButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        CancelButton = new QPushButton(layoutWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", 0));
        TitleLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\346\263\250\345\206\214</span></p></body></html>", 0));
        StudentNumberLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", 0));
        NameLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\247\223\345\220\215</span></p></body></html>", 0));
        PasswordLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", 0));
        SurePasswordLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\347\241\256\350\256\244\345\257\206\347\240\201</span></p></body></html>", 0));
        CodeLabel->setText(QApplication::translate("RegisterDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\351\252\214\350\257\201\347\240\201</span></p></body></html>", 0));
        SureButton->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244", 0));
        CancelButton->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
