#include "sidepanel.h"
#include "ui_sidepanel.h"

sidepanel::sidepanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sidepanel)
{
    ui->setupUi(this);
    layout->addLayout(sidePanel);

    types = {"Red", "Blue", "Green", "Add Props", "Remove Props", "Save to File"}; //Buttons on the navigation bar to be added
    fruits = {"Apple", "Banana", "Cherry", "Date", "Elderberry"}; //Types of properties you can edit in "Red" form
    teams = {"Real Madrid", "Barcelona", "Manchester United"}; //This adds to a combo box in the "Red" form
    cars = {"Toyota", "Nissan", "Ferrari", "Cadillac"}; //Types of properties you can edit in "Blue" form
    cities = {"New York", "London", "Mumbai"}; //Types of properties you can edit in "Green" form
    geometry = {"length", "width", "height"}; //Geometry field in the "Red" form (This is static i.e. we can't add more properties of this)


    for(int i = 0; i < types.size(); i++) {

    /*
     *Iterating through the types to make corresponding number of buttons
     *The sidebuttons are added to a QList (it's basically an array)
     */

        sideButton.append(new QPushButton());
        sideButton[i]->setVisible(true);
        sideButton[i]->setText(types[i]);
        sidePanel->addWidget(sideButton[i]);

        if (i < 3) {
            formLayout.append(new QFormLayout); //this is a QList of form layouts

            /*
             *inner is a blank widget to enable scrolling
             *everything is added to inner
             *and inner is added to the scrollArea
             *and scrollArea is then added to the main layout "layout"
             *idk but this was the only way it seemed to work
             */
            inner.append(new QWidget);
            scrollArea.append(new QScrollArea);
            inner[i]->setLayout(formLayout[i]);
            scrollArea[i]->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
            scrollArea[i]->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);
            scrollArea[i]->setWidgetResizable (true);
            scrollArea[i]->setWidget(inner[i]);
            layout->addWidget(scrollArea[i]);

            /*
             * qle_list is a list of list of line edit fields
             * The first layer (qle_list[i]) corresponds to the form ("Red", "Blue", "Green")
             * The second layer (qle_list[i][j]) corresponds to the line edit fields inside the ith form
             */

            QList<QLineEdit*> list;
            qle_list.append(list);

            //This only enables the "Red" form when this window is initiallly opened

            if (i == 0) {
                formLayout[i]->setEnabled(true);

            }
            else {
                formLayout[i]->setEnabled(false);
            }

        }
    }

    addGeometry(); //This function is a constant staying group that never changes i.e. when "Add Props" is clicked this is not added
    addRed(); //This function adds the rest of the elements of the "Red" form

    // I am only adding the buttons to the "Red" form initially to save time

    //This checks the first time the user enters the "Blue"/"Green" form
    //Once they click the form for the first time, addBlue() and addGreen() is ran through and this is set to false
    blueCheck = true;
    greenCheck = true;


    //Function to set the form visible or not (I made this, it's not in Qt)
    setFormVisible(0,true);
    setFormVisible(1,false);
    setFormVisible(2,false);

    //Keeps track of the number of properties are added in each form
    countProps_Red = 1;
    countProps_Blue = 1;
    countProps_Green = 1;


    //Signals and slots to connect to each form
    connect(sideButton[0],SIGNAL(clicked()),this,SLOT(RedClicked()));
    connect(sideButton[1],SIGNAL(clicked()),this,SLOT(BlueClicked()));
    connect(sideButton[2],SIGNAL(clicked()),this,SLOT(GreenClicked()));
    connect(sideButton[3],SIGNAL(clicked()),this,SLOT(addProps()));
    connect(sideButton[4],SIGNAL(clicked()),this,SLOT(removeProps()));
    connect(sideButton[5],SIGNAL(clicked()),this,SLOT(savebuttonclicked()));



}

sidepanel::~sidepanel()
{
    delete ui;
}

void sidepanel::addRed()
{
    //This is called everytime we want to add properties to the "Red" form

    //Looping through the fruits array
    for (int i = 0; i < fruits.size(); i++) {

        //Keeps track of the index of the last element of the qle_list and dropdown
        int counter = qle_list[0].size();
        int counter_dropdown = dropdown.size();

        //If we want a Combo box for the Banana
        //This enables a Combo box or LineEdit field
        if(fruits[i] == "Banana") {
            dropdown.append(new QComboBox(this));
            dropdown[counter_dropdown]->addItems(teams);
            formLayout[0]->addRow(fruits[i], dropdown[counter_dropdown]);
            dropdown[counter_dropdown]->setVisible(true);
            counter_dropdown++;
        }
        else{
            qle_list[0].append(new QLineEdit());
            qle_list[0][counter]->setVisible(true);
            formLayout[0]->addRow(fruits[i], qle_list[0][counter]);
            counter++;

        }
    }

}

void sidepanel::addBlue()
{
    //This is called everytime we want to add properties to the "Blue" form

    int counter = qle_list[1].size();

    for (int i = 0; i < cars.length();i++) {
        qle_list[1].append(new QLineEdit());
        qle_list[1][i]->setVisible(true);
        formLayout[1]->addRow(cars[i], qle_list[1][i+counter]);
    }

}

void sidepanel::addGreen()
{
    //This is called everytime we want to add properties to the "Green" form

    int counter = qle_list[2].size();

    for (int i = 0; i < cities.length();i++) {
        qle_list[2].append(new QLineEdit());
        qle_list[2][i]->setVisible(true);
        formLayout[2]->addRow(cities[i], qle_list[2][i+counter]);
    }

}

void sidepanel::addGeometry()
{
    formLayout.append(new QFormLayout);
    geometryGroup = new QGroupBox;

    for (int i = 0; i < geometry.length();i++) {
        qle_list[0].append(new QLineEdit());
        qle_list[0][i]->setVisible(true);
        formLayout[3]->addRow(geometry[i],qle_list[0][i]);
    }
    geometryGroup->setLayout(formLayout[3]);
    geometryGroup->setTitle("Geometry");
    formLayout[0]->addWidget(geometryGroup);
}

void sidepanel::RedClicked()
{
    //This function enables and makes the "Red" form visible

    //Ignore this, earlier I was clearing the entire thing and rebuilding whenever I wanted to go to another form
    // while (formLayout->rowCount() > 0)
    // {
    //     formLayout->removeRow(0);
    // }
    // qle_list.clear();
    // dropdown.clear();

    formLayout[0]->setEnabled(true);
    formLayout[1]->setEnabled(false);
    formLayout[2]->setEnabled(false);
    setFormVisible(0,true);
    setFormVisible(1,false);
    setFormVisible(2,false);

    // countProps_Blue = 1;
    // countProps_Green = 1;


}

void sidepanel::BlueClicked()
{

    //This function enables and makes the "Blue" form visible

    //When the user enters the "Blue" form for the first time, the properties are added
    if (blueCheck){
        addBlue();
    }
    blueCheck = false;


    // while (formLayout->rowCount() > 0)
    // {
    //     formLayout->removeRow(0);
    // }
    // qle_list.clear();

    // countProps_Red = 1;
    // countProps_Green = 1;

    formLayout[0]->setEnabled(false);
    formLayout[1]->setEnabled(true);
    formLayout[2]->setEnabled(false);
    setFormVisible(0,false);
    setFormVisible(1,true);
    setFormVisible(2,false);

    // if(countProps_Blue > 1) {
    //     for (int j = 0; j < countProps_Blue; j++) {
    //         for (int i = 0; i < cars.length();i++) {
    //             qle_list.append(new QLineEdit());
    //             qle_list[i+cars.size()*j]->setVisible(true);
    //             formLayout->addRow(cars[i], qle_list[i+cars.size()*j]);
    //         }
    //     }
    // }
    // else {
    //     for (int i = 0; i < cars.length();i++) {
    //         qle_list.append(new QLineEdit());
    //         qle_list[i]->setVisible(true);
    //         formLayout->addRow(cars[i], qle_list[i]);
    //     }
    // }


}

void sidepanel::GreenClicked()
{
    //This function enables and makes the "Green" form visible

    //When the user enters the "Green" form for the first time, the properties are added

    if (greenCheck) {
        addGreen();
    }
    greenCheck = false;

    // while (formLayout->rowCount() > 0)
    // {
    //     formLayout->removeRow(0);
    // }
    // qle_list.clear();

    // countProps_Red = 1;
    // countProps_Blue = 1;

    formLayout[0]->setEnabled(false);
    formLayout[1]->setEnabled(false);
    formLayout[2]->setEnabled(true);
    setFormVisible(0,false);
    setFormVisible(1,false);
    setFormVisible(2,true);

    // if (countProps_Green > 1) {
    //     for (int j = 0; j < countProps_Green; j++) {
    //         for (int i = 0; i < cities.size();i++) {
    //             qle_list.append(new QLineEdit());
    //             qle_list[i+cities.size()*j]->setVisible(true);
    //             formLayout->addRow(cities[i], qle_list[i + cities.size()*j]);
    //         }
    //     }
    // }
    // else {
    //     for (int i = 0; i < cities.length();i++) {
    //         qle_list.append(new QLineEdit());
    //         qle_list[i]->setVisible(true);
    //         formLayout->addRow(cities[i], qle_list[i]);
    //     }
    // }


}

void sidepanel::savebuttonclicked()
{

    // When the save button is clicked this runs to print to a file

    QFile file("C:/Users/2021n/Documents/TestProj/sidepanel.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "File is not open");
    }

    QTextStream out(&file);

    int counter = 0;
    int counter_dropdown = 0;

    if(formLayout[0]->isEnabled()) {
        for (int i = 0; i < qle_list[0].size() + dropdown.size(); ++i) {

            if(fruits[i] == "Banana") {
                out << fruits[i] << " " << dropdown[counter_dropdown]->currentText() <<Qt::endl;
                counter_dropdown++;
            }
            else{

                out << fruits[i] << " " << qle_list[0][counter]->text() <<Qt::endl;
                counter++;
            }
        }
    }
    else if (formLayout[1]->isEnabled()) {
        for (int i = 0; i < qle_list[1].size(); ++i) {
            out << cars[i] << " " << qle_list[1][i]->text() <<Qt::endl;
        }
    }
    else {
        for (int i = 0; i < qle_list[2].size(); ++i) {
            out << cities[i] << " " << qle_list[2][i]->text() <<Qt::endl;
        }

    }
    file.flush();
    file.close();

    QMessageBox::information(this, "title", "File saved successfully");

}

void sidepanel::addProps()
{
    //When the addProps button is clicked this runs to add a new set of Properties
    //to the form that the user is on

    if (formLayout[0]->isEnabled()) {
        countProps_Red++;
        addRed();
        RedClicked();
    }
    else if (formLayout[1]->isEnabled()) {
        countProps_Blue++;
        addBlue();
        BlueClicked();
    }
    else {
        countProps_Green++;
        addGreen();
        GreenClicked();
    }

}

void sidepanel::removeProps()
{

    //Literally the reverse of addProps
    if (formLayout[0]->isEnabled()) {
        if (countProps_Red <= 1) {
            QMessageBox::warning(this, "title", "Cannot remove more properties");
        }
        else {
            countProps_Red--;
            for (int i = 0; i < fruits.size();i++) {
                formLayout[0]->removeRow(formLayout[0]->rowCount()-1);
                if(fruits[i] == "Banana") {
                    dropdown.removeLast();
                }
                else{
                    qle_list[0].removeLast();

                }

            }
            RedClicked();

        }
    }
    else if (formLayout[1]->isEnabled()) {
        if (countProps_Blue <= 1) {
            QMessageBox::warning(this, "title", "Cannot remove more properties");
        }
        else {
            countProps_Blue--;
            for (int i = 0; i < cars.size();i++) {
                formLayout[1]->removeRow(formLayout[1]->rowCount()-1);
                qle_list[1].removeLast();

            }
            BlueClicked();

        }
    }
    else {
        if (countProps_Green <= 1) {
            QMessageBox::warning(this, "title", "Cannot remove more properties");
        }
        else {
            countProps_Green--;
            for (int i = 0; i < cities.size();i++) {
                formLayout[2]->removeRow(formLayout[2]->rowCount()-1);
                qle_list[2].removeLast();

            }
            GreenClicked();

        }

    }




}

void sidepanel::setFormVisible(int a, bool check)
{

    //"a" checks the form number
    //"check" checks whether it should turn visible or invisible

    for (int i=0;i<formLayout[a]->rowCount();i++){
        formLayout[a]->setRowVisible(i,check);

    }
    inner[a]->setVisible(check);
    scrollArea[a]->setVisible(check);
}


