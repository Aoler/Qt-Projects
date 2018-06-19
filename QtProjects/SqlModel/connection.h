#ifndef CONNECTION
#define CONNECTION

#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QCoreApplication>
#include<QSqlError>
static bool creatConnection(const char *dbName)
{
    QString dbpath= QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg(dbName);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","sqlModel");
    db.setDatabaseName(dbpath);
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open database",db.lastError().text(),QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query(db);
    query.exec(QString("create table student (id int primary key,name varchar,course int)"));
    query.exec(QString("insert into student values(1,'李强',11)"));
    query.exec(QString("insert into student values(2,'马良',11)"));
    query.exec(QString("insert into student values(8,'孙洪'，12)"));

    query.exec(QString("create table course (id int primary key,name varchar,teacher varchar)"));
    query.exec(QString("insert into course values(10,'数学','王老师')"));
    query.exec(QString("insert into course values(11,'英语','张老师')"));
    query.exec(QString("insert into course values(12,'计算机','白老师')"));
    return true;


}

#endif // CONNECTION

