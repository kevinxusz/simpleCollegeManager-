#ifndef CLESSON_3_H
#define CLESSON_3_H
#include "db.h"
#include <QMainWindow>

namespace Ui {
    class cLesson_3;
}

class cLesson_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit cLesson_3(QWidget *parent = 0);
    ~cLesson_3();

private:
    Ui::cLesson_3 *ui;

private slots:
    void on_SubmitButton_clicked();
    void on_BackButton_clicked();
};

#endif // CLESSON_3_H
