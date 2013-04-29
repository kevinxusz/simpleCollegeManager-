#ifndef CSTUDENT_3_H
#define CSTUDENT_3_H
#include "db.h"
#include <QMainWindow>

namespace Ui {
    class cStudent_3;
}

class cStudent_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit cStudent_3(QWidget *parent = 0);
    ~cStudent_3();

private:
    Ui::cStudent_3 *ui;

private slots:
    void on_SubmitButton_2_clicked();
    void on_BackButton_clicked();
};

#endif // CSTUDENT_3_H
