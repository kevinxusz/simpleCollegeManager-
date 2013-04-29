#include "cinform.h"
#include "ui_cinform.h"
#include "clesson_3.h"
#include "cstudent_3.h"
#include "cterm_3.h"

cInform::cInform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cInform)
{
    ui->setupUi(this);
}

cInform::~cInform()
{
    delete ui;
}

void cInform::on_BackButton_clicked()
{
    this->close();
}

void cInform::on_StudentsButton_clicked()
{
    p_cStudent= new cStudent_3;
    p_cStudent->show();
}

void cInform::on_LessonsButton_clicked()
{
    p_cLesson= new cLesson_3;
    p_cLesson->show();
}

void cInform::on_TermsButton_clicked()
{
    p_cTerm=new cTerm_3;
    p_cTerm->show();
}
