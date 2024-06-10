#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QComboBox>
#include <QScrollArea>


namespace Ui {
class sidepanel;
}

class sidepanel : public QDialog
{
    Q_OBJECT

public:
    explicit sidepanel(QWidget *parent = nullptr);
    ~sidepanel();

private slots:
    void addRed();
    void addBlue();
    void addGreen();
    void addGeometry();

    void RedClicked();
    void BlueClicked();
    void GreenClicked();

    void savebuttonclicked();
    void addProps();
    void removeProps();

    void setFormVisible(int, bool);


private:
    Ui::sidepanel *ui;
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *sidePanel = new QVBoxLayout();
    QList <QFormLayout*> formLayout;

    QStringList types, fruits, cars, cities, teams, geometry;
    QGroupBox* geometryGroup = new QGroupBox;

    QList <QPushButton*> sideButton;
    QList<QList <QLineEdit*>> qle_list;
    QList <QComboBox*> dropdown;
    QList<QWidget*> inner;
    QList <QScrollArea*> scrollArea;

    bool redCheck, blueCheck, greenCheck;
    int countProps_Red, countProps_Blue, countProps_Green;


};

#endif // SIDEPANEL_H
