#ifndef DB_H
#define DB_H
#include <QtCore>
#include <QtSql>
#include<QtGui/QTableView>

class db
{
public:
    void StudentStore(QString fName,QString lName,QString stNum);
    void LessonStore(QString lessonName,QString unit,QString teacher);
    void TermStore(QString year,QString term,QString lessonNum,QString stNum);
    QString search(QString *info);
    QMultiMap<QString,QString> stList_Term();
    QMultiMap<QString,QString> lessonList_Term();
    db();
private:
    QSqlDatabase trDb;
    QString trQuery;
    QTableView *searchTable;
};

#endif // DB_H
