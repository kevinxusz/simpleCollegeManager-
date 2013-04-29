#include "cstudent_3.h"
#include "ui_cstudent_3.h"

cStudent_3::cStudent_3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cStudent_3)
{
    ui->setupUi(this);
}

cStudent_3::~cStudent_3()
{
    delete ui;
}

void cStudent_3::on_BackButton_clicked()
{
    this->close();
}

void cStudent_3::on_SubmitButton_2_clicked()
{
    QString fName = ui->FnameText->text();
    QString lName = ui->LnameText->text();
    QString stNum = ui->StnumText->text();
    db stDb;
    stDb.StudentStore(fName,lName,stNum);
    this->close();
}
