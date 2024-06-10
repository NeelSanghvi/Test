/********************************************************************************
** Form generated from reading UI file 'dynamicparameters.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICPARAMETERS_H
#define UI_DYNAMICPARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_dynamicparameters
{
public:

    void setupUi(QDialog *dynamicparameters)
    {
        if (dynamicparameters->objectName().isEmpty())
            dynamicparameters->setObjectName("dynamicparameters");
        dynamicparameters->resize(400, 300);

        retranslateUi(dynamicparameters);

        QMetaObject::connectSlotsByName(dynamicparameters);
    } // setupUi

    void retranslateUi(QDialog *dynamicparameters)
    {
        dynamicparameters->setWindowTitle(QCoreApplication::translate("dynamicparameters", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dynamicparameters: public Ui_dynamicparameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICPARAMETERS_H
