#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QApplication>

class CommonHelper
{
public:
    static void setCustomStyle(const QString &strpath){
        qDebug() << strpath;
        QFile qss(strpath);
        if(!qss.open(QFile::ReadOnly)){
            qDebug("Open failed");
            return ;
        }
        else{
            qApp->setStyleSheet(qss.readAll());
            qss.close();
        }
    }
};

#endif // COMMONHELPER_H
