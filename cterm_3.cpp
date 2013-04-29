#include "cterm_3.h"
#include "ui_cterm_3.h"

cTerm_3::cTerm_3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cTerm_3)
{
    ui->setupUi(this);
    reportStudents();
    reportLessons();
}

cTerm_3::~cTerm_3()
{
    delete ui;
}

void cTerm_3::on_BackButton_clicked()
{
    this->close();
}

void cTerm_3::reportStudents(){
    db stDb;
    stMap=stDb.stList_Term();
    QList<QString> stList;
    stList=stMap.keys();
    for(int i=0;i<stList.size();i++)
        ui->StudentCombo->addItem(stList[i]);
}

void cTerm_3::reportLessons(){
    db lessonDb;
    lessonMap=lessonDb.lessonList_Term();
    QList<QString> lessonList;
    lessonList=lessonMap.keys();
    for(int i=0;i<lessonList.size();i++)
        ui->LessonCombo->addItem(lessonList[i]);
}

void cTerm_3::on_SubmitButton_clicked()
{
    QString year = ui->YearList->text();
    QString term;

    if(ui->Term1Radio->isChecked())
        term='1';
    else if(ui->Term2Radio->isChecked())
        term='2';
    QString lesson=ui->LessonCombo->currentText();
    QString lessonNum=lessonMap.find(lesson).value();
    QString student=ui->StudentCombo->currentText();
    QString stNum=stMap.find(student).value();
    db termDb;
    termDb.TermStore(year,term,lessonNum,stNum);
    this->close();
}
