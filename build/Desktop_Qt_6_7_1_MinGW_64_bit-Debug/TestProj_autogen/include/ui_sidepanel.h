/********************************************************************************
** Form generated from reading UI file 'sidepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEPANEL_H
#define UI_SIDEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_sidepanel
{
public:

    void setupUi(QDialog *sidepanel)
    {
        if (sidepanel->objectName().isEmpty())
            sidepanel->setObjectName("sidepanel");
        sidepanel->resize(604, 525);

        retranslateUi(sidepanel);

        QMetaObject::connectSlotsByName(sidepanel);
    } // setupUi

    void retranslateUi(QDialog *sidepanel)
    {
        sidepanel->setWindowTitle(QCoreApplication::translate("sidepanel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sidepanel: public Ui_sidepanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEPANEL_H
