/********************************************************************************
** Form generated from reading UI file 'dynamictest.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICTEST_H
#define UI_DYNAMICTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_dynamictest
{
public:

    void setupUi(QDialog *dynamictest)
    {
        if (dynamictest->objectName().isEmpty())
            dynamictest->setObjectName("dynamictest");
        dynamictest->resize(400, 300);

        retranslateUi(dynamictest);

        QMetaObject::connectSlotsByName(dynamictest);
    } // setupUi

    void retranslateUi(QDialog *dynamictest)
    {
        dynamictest->setWindowTitle(QCoreApplication::translate("dynamictest", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dynamictest: public Ui_dynamictest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICTEST_H
