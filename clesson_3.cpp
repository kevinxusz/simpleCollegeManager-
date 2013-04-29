#include "clesson_3.h"
#include "ui_clesson_3.h"

cLesson_3::cLesson_3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cLesson_3)
{
    ui->setupUi(this);
}

cLesson_3::~cLesson_3()
{
    delete ui;
}

void cLesson_3::on_BackButton_clicked()
{
    this->close();
}

void cLesson_3::on_SubmitButton_clicked()
{
    QString lessonName = ui->LessonText->text();
    QString unit = ui->UnitList->text();
    QString teacher = ui->TecherText->text();
    db leDb;
    leDb.LessonStore(lessonName,unit,teacher);
    this->close();
}
