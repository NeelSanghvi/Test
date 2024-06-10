#ifndef DYNAMICTEST_H
#define DYNAMICTEST_H

#include <QDialog>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QComboBox>

namespace Ui {
class dynamictest;
}

class dynamictest : public QDialog
{
    Q_OBJECT

public:
    explicit dynamictest(QWidget *parent = nullptr);
    ~dynamictest();

public slots:
    void savebuttonclicked();

private:
    Ui::dynamictest *ui;

    QList<QLineEdit*> qle_list;
    QComboBox* dropdown;
    QStringList colors;
    QStringList fruits;



};

#endif // DYNAMICTEST_H
