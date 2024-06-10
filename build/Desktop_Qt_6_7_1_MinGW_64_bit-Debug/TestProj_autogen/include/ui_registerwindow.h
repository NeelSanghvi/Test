/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerwindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_surname;
    QLineEdit *lineEdit_name_2;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLabel *label_pass;
    QLineEdit *lineEdit_pass;
    QLabel *label_repass;
    QLineEdit *lineEdit_repass;
    QPushButton *pushButton_back_login;
    QPushButton *pushButton_register;
    QPushButton *pushButton;

    void setupUi(QDialog *registerwindow)
    {
        if (registerwindow->objectName().isEmpty())
            registerwindow->setObjectName("registerwindow");
        registerwindow->resize(400, 349);
        gridLayout = new QGridLayout(registerwindow);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(registerwindow);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName("lineEdit_name");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        label_surname = new QLabel(groupBox);
        label_surname->setObjectName("label_surname");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_surname);

        lineEdit_name_2 = new QLineEdit(groupBox);
        lineEdit_name_2->setObjectName("lineEdit_name_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_name_2);

        label_username = new QLabel(groupBox);
        label_username->setObjectName("label_username");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_username);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName("lineEdit_username");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_username);

        label_pass = new QLabel(groupBox);
        label_pass->setObjectName("label_pass");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_pass);

        lineEdit_pass = new QLineEdit(groupBox);
        lineEdit_pass->setObjectName("lineEdit_pass");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_pass);

        label_repass = new QLabel(groupBox);
        label_repass->setObjectName("label_repass");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_repass);

        lineEdit_repass = new QLineEdit(groupBox);
        lineEdit_repass->setObjectName("lineEdit_repass");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_repass);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        pushButton_back_login = new QPushButton(registerwindow);
        pushButton_back_login->setObjectName("pushButton_back_login");

        gridLayout->addWidget(pushButton_back_login, 4, 0, 1, 1);

        pushButton_register = new QPushButton(registerwindow);
        pushButton_register->setObjectName("pushButton_register");

        gridLayout->addWidget(pushButton_register, 3, 0, 1, 1);

        pushButton = new QPushButton(registerwindow);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);


        retranslateUi(registerwindow);

        QMetaObject::connectSlotsByName(registerwindow);
    } // setupUi

    void retranslateUi(QDialog *registerwindow)
    {
        registerwindow->setWindowTitle(QCoreApplication::translate("registerwindow", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registerwindow", "Register", nullptr));
        label_name->setText(QCoreApplication::translate("registerwindow", "Name:", nullptr));
        label_surname->setText(QCoreApplication::translate("registerwindow", "Last Name:", nullptr));
        label_username->setText(QCoreApplication::translate("registerwindow", "Username:", nullptr));
        label_pass->setText(QCoreApplication::translate("registerwindow", "Password:", nullptr));
        label_repass->setText(QCoreApplication::translate("registerwindow", "Re-enter Password:", nullptr));
        pushButton_back_login->setText(QCoreApplication::translate("registerwindow", "Back to Login", nullptr));
        pushButton_register->setText(QCoreApplication::translate("registerwindow", "Register", nullptr));
        pushButton->setText(QCoreApplication::translate("registerwindow", "Save details to a file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerwindow: public Ui_registerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
