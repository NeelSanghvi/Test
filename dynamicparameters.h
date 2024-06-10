#ifndef DYNAMICPARAMETERS_H
#define DYNAMICPARAMETERS_H

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
#include <QTreeWidget>

#include "parameterlist.h"

namespace Ui {
class dynamicparameters;
}

class dynamicparameters : public QDialog
{
    Q_OBJECT

public:
    explicit dynamicparameters(QWidget *parent = nullptr);
    ~dynamicparameters();


private:
    Ui::dynamicparameters *ui;

    parameterList ParameterList;
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *sidePanel = new QVBoxLayout();
    QTreeWidget *treeWidget = new QTreeWidget();

    QList<QTreeWidgetItem*> treeWidgetItems;
    QList<QList<QTreeWidgetItem*>> treeWidgetChildren;
    QStringList ProjectNames;

private slots:
    QList<QTreeWidgetItem*> convertToQTreeWidgetItemList(QStringList);

};

#endif // DYNAMICPARAMETERS_H
