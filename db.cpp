#include "db.h"
#include <iostream>

db::db()
{
    QSqlQueryModel *p_Query = new QSqlQueryModel;
    //Provide college db
    trDb=QSqlDatabase::addDatabase("QSQLITE");
    trDb.setDatabaseName("college");
    if (!trDb.open())
    {
        //error widget about not connecting to db
    }

    // Creates three tables
    //----------------
    //create student table
    trQuery="CREATE TABLE if not exists student (fname TEXT(20) DEFAULT NULL,lastname TEXT(20) DEFAULT NULL,stnum integer  PRIMARY KEY DEFAULT NULL )";
    p_Query->setQuery(trQuery,trDb);

    //----------------
    //create term table

    trQuery="CREATE TABLE if not exists term (termnum integer  PRIMARY KEY AUTOINCREMENT DEFAULT NULL,year integer DEFAULT '1391',term integer DEFAULT '1',stnum integer DEFAULT NULL,lessonnum integer DEFAULT NULL )";
    p_Query->setQuery(trQuery,trDb);

    //-----------------
    //create lesson table

    trQuery="CREATE TABLE if not exists lesson (lessonnum integer  PRIMARY KEY AUTOINCREMENT DEFAULT NULL,lessonname text(20) DEFAULT NULL,unit integer DEFAULT '1',teacher text(20) DEFAULT NULL)";
    p_Query->setQuery(trQuery,trDb);
}


//This func is using in cstudent_3.cpp to store student informations
void db::StudentStore(QString fName,QString lName,QString stNum){
    QSqlQueryModel *p_Query = new QSqlQueryModel;
    trQuery="INSERT INTO student(fname,lastname,stnum) VALUES ('" +fName+ "','"+lName+"','"+stNum+"')";
    p_Query->setQuery(trQuery,trDb);
}

//This func is using in clesson_3.cpp to store lesson informations
void db::LessonStore(QString lessonName,QString unit,QString teacher){
    QSqlQueryModel *p_Query = new QSqlQueryModel;
    trQuery="INSERT INTO lesson (lessonname,unit,teacher) VALUES ('"+lessonName+"','"+unit+"','"+teacher+"')";
    p_Query->setQuery(trQuery,trDb);
}

//This func is using in cterm_3.cpp to store term informations
void db::TermStore(QString year,QString term,QString lessonNum,QString stNum){
    QSqlQueryModel *p_Query = new QSqlQueryModel;
    trQuery="INSERT INTO term (year,term,stnum,lessonnum) VALUES ('"+year+"','"+term+"','"+stNum+"','"+lessonNum+"')";
    p_Query->setQuery(trQuery,trDb);
}

//this function is used for obtain studnet information for showing in term form
QMultiMap<QString,QString> db::stList_Term(){
    QString fName,lName,stNum;
    QSqlQuery *p_Query = new QSqlQuery("SELECT fname,lastname,stnum FROM student",trDb);
    QSqlRecord record;
    QMultiMap<QString,QString> stMap;
    while(p_Query->next()){
        record=p_Query->record();
        fName=record.value("fname").toString();
        lName=record.value("lastname").toString();
        stNum=record.value("stnum").toString();
        stMap.insert(fName+"-"+lName+"-"+stNum,stNum);
    }
    return stMap;
}

//this function is used for obtain lesson information for showing in term form
QMultiMap<QString,QString> db::lessonList_Term(){
    QString lessonName,unit,teacher,lessonNum;
    QSqlQuery *p_Query = new QSqlQuery("SELECT lessonname,unit,teacher,lessonnum FROM lesson",trDb);
    QSqlRecord record;
    QMultiMap<QString,QString> lessonMap;
    while(p_Query->next()){
        record=p_Query->record();
        lessonName=record.value("lessonname").toString();
        unit=record.value("unit").toString();
        teacher=record.value("teacher").toString();
        lessonNum=record.value("lessonnum").toString();
        lessonMap.insert(lessonName+"-"+unit+"-"+teacher,lessonNum);
    }

    return lessonMap;
}


QString db::search(QString *info){
    QString fName=info[0];
    QString lName=info[1];
    QString stNum=info[2];
    QString lessonName=info[3];
    QString unit=info[4];
    QString teacher=info[5];
    QString year=info[6];
    QString term=info[7];

    QList<QString> conditionList;
    QString conditions;
    bool all=true;
    if(fName !=""){
        conditionList.append("student.fname = '"+fName+"'");
        all=false;}
    if (lName !=""){
        conditionList.append("student.lastname = '"+lName+"'");
        all=false;}
    if (stNum !=""){
        conditionList.append("student.stnum = '"+stNum+"'");
        all=false;}
    if (lessonName !=""){
        conditionList.append("lesson.lessonname = '"+lessonName+"'");
        all=false;}
    if (unit !="0"){
        conditionList.append("lesson.unit = '"+unit+"'");
        all=false;}
    if (teacher !=""){
        conditionList.append("lesson.teacher = '"+teacher+"'");
        all=false;}
    if (year !=""){
        conditionList.append("term.year = '"+year+"'");
        all=false;}
    if (term !=""){
        conditionList.append("term.term = '"+term+"'");
        all=false;}

    //this loop creates conditions for search db
    for(int i=0;i<conditionList.size();i++)
    {
        if(i!=conditionList.size()-1)
            conditions+=conditionList[i]+" and ";
        else if(i==conditionList.size()-1)
            conditions+=conditionList[i];
    }

    QSqlQueryModel *p_Query = new QSqlQueryModel;
    trQuery="SELECT * FROM student,lesson,term WHERE lesson.lessonnum=term.lessonnum and  student.stnum=term.stnum and ";
    trQuery+=conditions;

    if (all!=0){
        trQuery=" SELECT * FROM student,lesson,term WHERE lesson.lessonnum=term.lessonnum and  student.stnum=term.stnum ";
    }
    p_Query->setQuery(trQuery,trDb);
    searchTable=new QTableView;
    searchTable->setModel(p_Query);
    searchTable->show();
    return trQuery;
}


