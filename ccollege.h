#ifndef CCOLLEGE_H
#define CCOLLEGE_H

#include <QMainWindow>
#include "cinform.h"
#include "csearch.h"

namespace Ui {
    class cCollege;
}

class cCollege : public QMainWindow
{
    Q_OBJECT

public:
    explicit cCollege(QWidget *parent = 0);
    ~cCollege();

private:
    Ui::cCollege *ui;
    cInform *p_cInform;
    cSearch *p_cSearch;

private slots:
    void on_SearchButton_clicked();
    void on_ExitButton_clicked();
    void on_InformButtom_clicked();
};

#endif // CCOLLEGE_H
