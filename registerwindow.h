#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class registerwindow;
}

class registerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

private slots:
    void on_pushButton_back_login_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_clicked();

private:
    Ui::registerwindow *ui;

};

#endif // REGISTERWINDOW_H
