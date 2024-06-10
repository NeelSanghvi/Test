#include "dynamicparameters.h"
#include "ui_dynamicparameters.h"

dynamicparameters::dynamicparameters(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dynamicparameters)
{
    ui->setupUi(this);
    layout->addLayout(sidePanel);
    treeWidget->setColumnCount(1);

    ProjectNames = ParameterList.getProjectNames();

    gui::Parameter_List_Type aModule = gui::Parameter_List_Type::OPT;

    for (int iTreeWidget = 0; iTreeWidget < ProjectNames.size(); iTreeWidget++) {
        treeWidgetItems.append(new QTreeWidgetItem);
        treeWidgetItems[iTreeWidget]->setText
            (0,ProjectNames[iTreeWidget]);

        //treeWidgetItems[iTreeWidget]->(convertToQTreeWidgetItemList(ParameterList.getOuterSubParameterListName(aModule)));
        //tTreeWidgetItems.clear();
        aModule = static_cast<gui::Parameter_List_Type>(static_cast<int>(aModule) + 1);

    }
    treeWidget->addTopLevelItems(treeWidgetItems);
    treeWidget->setHeaderLabel("Project Names");
    sidePanel->addWidget(treeWidget);



}

dynamicparameters::~dynamicparameters()
{
    delete ui;
}

QList<QTreeWidgetItem *> dynamicparameters::convertToQTreeWidgetItemList(QStringList tStringList)
{
    //tTreeWidgetItems.resize(tStringList.size());

    //int t = tStringList.size();

    for (int i = 0; i < tStringList.size();i++) {
        tTreeWidgetItems.append(new QTreeWidgetItem);
        treeWidgetItems[i]->setText(0,tStringList[i]);
    }
    return tTreeWidgetItems;

}
