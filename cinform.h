#ifndef CINFORM_H
#define CINFORM_H

#include <QMainWindow>
#include "clesson_3.h"
#include "cstudent_3.h"
#include "cterm_3.h"

namespace Ui {
    class cInform;
}

class cInform : public QMainWindow
{
    Q_OBJECT

public:
    explicit cInform(QWidget *parent = 0);
    ~cInform();

private:
    Ui::cInform *ui;
    cLesson_3 *p_cLesson;
    cStudent_3 *p_cStudent;
    cTerm_3 *p_cTerm;


private slots:
    void on_TermsButton_clicked();
    void on_LessonsButton_clicked();
    void on_StudentsButton_clicked();
    void on_BackButton_clicked();
};

#endif // CINFORM_H
