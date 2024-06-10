#include "dynamictest.h"
#include "ui_dynamictest.h"



dynamictest::dynamictest(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dynamictest)
{

    ui->setupUi(this);
    colors = {"Red", "Blue", "Green"};
    fruits = {"Apple", "Banana", "Cherry", "Date", "Elderberry"};

    QFormLayout *formLayout = new QFormLayout(this);

    this->setLayout(formLayout);

    int counter = 0;

    for (int i = 0; i < 5; i++) {


        if(fruits[i] == "Banana") {
            dropdown = new QComboBox(this);
            dropdown->addItems(colors);
            formLayout->addRow(fruits[i], dropdown);
            dropdown->setVisible(true);
        }
        else{
            qle_list.append(new QLineEdit());
            qle_list[counter]->setVisible(true);
            formLayout->addRow(fruits[counter], qle_list[counter]);
            counter++;

        }
    }

    QPushButton *savebutton = new QPushButton();
    connect(savebutton,SIGNAL(clicked()),this,SLOT(savebuttonclicked()));

    savebutton->setText("Save File");
    formLayout->addWidget(savebutton);
    savebutton->setVisible(true);
}

dynamictest::~dynamictest()
{
    delete ui;
}

void dynamictest::savebuttonclicked()
{

    QFile file("C:/Users/2021n/Documents/TestProj/DynamicTest.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "File is not open");
    }

    QTextStream out(&file);

    int counter = 0;

    for (int i = 0; i < qle_list.size(); ++i) {
        if(fruits[i] == "Banana") {
            out << fruits[i] << " " << dropdown->currentText() <<Qt::endl;
        }
        else{

            out << fruits[i] << " " << qle_list[counter]->text() <<Qt::endl;
            counter++;
        }

    }
    file.flush();
    file.close();

    QMessageBox::information(this, "title", "File saved successfully");

}





