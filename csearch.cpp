#include "csearch.h"
#include "ui_csearch.h"

cSearch::cSearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cSearch)
{
    ui->setupUi(this);
}

cSearch::~cSearch()
{
    delete ui;
}

void cSearch::on_BackButton_clicked()
{
    this->close();
}

void cSearch::on_SearchButton_clicked()
{
    QString info[8];
    info[0]=ui->FnameText->text();
    info[1]=ui->LnameText->text();
    info[2]=ui->StnumText->text();
    info[3]=ui->LessonText->text();
    info[4]=ui->UnitList->text();
    info[5]=ui->TecherText->text();
    info[6]=ui->YearList->text();
    if(ui->Term1Radio->isChecked())
        info[7]="1";
    else if(ui->Term2Radio->isChecked())
        info[7]="2";
    else if(ui->Term0Radio->isChecked())
        info[7]="";

    db searchDb;
    QString tr=searchDb.search(info);
}

