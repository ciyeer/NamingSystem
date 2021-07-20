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
        QFile qss(strpath);
        if(!qss.open(QFile::ReadOnly)){
            qDebug("Open qss file failed");
            return ;
        }
        else{
            qApp->setStyleSheet(qss.readAll());
            qss.close();
        }
    }
};

#endif // COMMONHELPER_H
