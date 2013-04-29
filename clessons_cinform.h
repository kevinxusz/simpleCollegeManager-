#ifndef CLESSONS_CINFORM_H
#define CLESSONS_CINFORM_H

#include <QMainWindow>

namespace Ui {
    class cLessons_cInform;
}

class cLessons_cInform : public QMainWindow
{
    Q_OBJECT

public:
    explicit cLessons_cInform(QWidget *parent = 0);
    ~cLessons_cInform();

private:
    Ui::cLessons_cInform *ui;
};

#endif // CLESSONS_CINFORM_H
