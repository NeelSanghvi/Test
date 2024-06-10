#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


registerwindow::registerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_pushButton_back_login_clicked()
{
    this->hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

}


void registerwindow::on_pushButton_register_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_pass->text();
    QString username = ui->lineEdit_username->text();
    QString pass = ui->lineEdit_pass->text();
    QString repass = ui->lineEdit_repass->text();
    if(pass!=repass){
        QMessageBox::warning(this,"Registration unsuccessfull","Passwords do not match");
    }
    else{
        QMessageBox::information(this,"Registration successfull","Please go back to the login page");

        this->hide();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    }



}


void registerwindow::on_pushButton_clicked()
{
    QFile file("C:/Users/2021n/Documents/TestProj/Registration.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "File is not open");
    }
    QTextStream out(&file);
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_pass->text();
    QString username = ui->lineEdit_username->text();
    QString pass = ui->lineEdit_pass->text();
    QString repass = ui->lineEdit_repass->text();

    out << "Name: " << name << ", Surname: " << surname << ", Username: " << username << ", Password: " << pass;
    file.flush();
    file.close();

    QMessageBox::information(this, "title", "File saved successfully");

}

