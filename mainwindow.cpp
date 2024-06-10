#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registerwindow.h"
#include "dynamictest.h"
#include "sidepanel.h"
#include "dynamicparameters.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_register_clicked()
{
    hide();

    registerwindow registerWindow;
    registerWindow.setModal(true);
    registerWindow.exec();

}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_name->text();
    QString pass = ui->lineEdit_pass->text();

    if(username=="Neel1234" && pass=="Neel"){
        QMessageBox::information(this, "Login", "Login Successfull");
    }
    else{
        QMessageBox::warning(this, "Login", "Login unsuccessfull");

    }
}


void MainWindow::on_pushButton_test_clicked()
{
    hide();

    dynamictest DynamicTest;
    DynamicTest.setModal(true);
    DynamicTest.exec();

}


void MainWindow::on_pushButton_clicked()
{
    hide();

    sidepanel sidePanel;
    sidePanel.setModal(true);
    sidePanel.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();

    dynamicparameters DynamicParameters;
    DynamicParameters.setModal(true);
    DynamicParameters.exec();
}

