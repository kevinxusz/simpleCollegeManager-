#include "clessons_cinform.h"
#include "ui_clessons_cinform.h"

cLessons_cInform::cLessons_cInform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cLessons_cInform)
{
    ui->setupUi(this);
}

cLessons_cInform::~cLessons_cInform()
{
    delete ui;
}
