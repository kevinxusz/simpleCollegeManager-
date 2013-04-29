#include "ccollege.h"
#include "ui_ccollege.h"
#include "cinform.h"
#include "csearch.h"
cCollege::cCollege(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cCollege)
{
    ui->setupUi(this);
}

cCollege::~cCollege()
{
    delete ui;
}

void cCollege::on_InformButtom_clicked()
{
    p_cInform= new cInform;
    p_cInform->show();
}

void cCollege::on_ExitButton_clicked()
{
    this->close();
}

void cCollege::on_SearchButton_clicked()
{
    p_cSearch= new cSearch;
    p_cSearch->show();
}
