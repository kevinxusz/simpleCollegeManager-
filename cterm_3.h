#ifndef CTERM_3_H
#define CTERM_3_H

#include "db.h"
#include <QMainWindow>

namespace Ui {
    class cTerm_3;
}

class cTerm_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit cTerm_3(QWidget *parent = 0);
    ~cTerm_3();

private:
    Ui::cTerm_3 *ui;

    //Obtaining student informations and add them to studentcombobox
    void reportStudents();

    //Obtaining lesson informations and add them to lesssoncombobox
    void reportLessons();

    //this map keep student info and indicates them to stNum
    QMultiMap<QString,QString> stMap;

    //this map keep lesson info and indicates them to lessonNum
    QMultiMap<QString,QString> lessonMap;

private slots:
    void on_SubmitButton_clicked();
    void on_BackButton_clicked();
};

#endif // CTERM_3_H
