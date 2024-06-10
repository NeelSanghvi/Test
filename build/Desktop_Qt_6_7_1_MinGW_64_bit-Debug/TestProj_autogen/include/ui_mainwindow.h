/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLabel *label_pass;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_pass;
    QPushButton *pushButton;
    QPushButton *pushButton_test;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(332, 267);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");

        gridLayout->addWidget(pushButton_login, 4, 0, 1, 1);

        pushButton_register = new QPushButton(centralwidget);
        pushButton_register->setObjectName("pushButton_register");

        gridLayout->addWidget(pushButton_register, 4, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        label_pass = new QLabel(groupBox);
        label_pass->setObjectName("label_pass");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_pass);

        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName("lineEdit_name");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        lineEdit_pass = new QLineEdit(groupBox);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_pass);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_test = new QPushButton(centralwidget);
        pushButton_test->setObjectName("pushButton_test");

        gridLayout->addWidget(pushButton_test, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 6, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 332, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "SIgn In", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_pass->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Side Panel", nullptr));
        pushButton_test->setText(QCoreApplication::translate("MainWindow", "Dynamic Test", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Dynamic Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
