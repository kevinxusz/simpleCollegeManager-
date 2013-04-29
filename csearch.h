#ifndef CSEARCH_H
#define CSEARCH_H
#include <db.h>
#include <QMainWindow>

namespace Ui {
    class cSearch;
}

class cSearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit cSearch(QWidget *parent = 0);
    ~cSearch();

private:
    Ui::cSearch *ui;

private slots:
    void on_SearchButton_clicked();
    void on_BackButton_clicked();
};

#endif // CSEARCH_H
