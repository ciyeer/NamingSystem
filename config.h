#ifndef CONFIG_H
#define CONFIG_H
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDir>

class Config
{
public:
    //    qDebug() << QDir::currentPath();
    //    qDebug() << QDir::homePath();
    //    qDebug() << QDir::rootPath();
    //    qDebug() << QDir::tempPath();

    explicit Config(QString strPath = QCoreApplication::applicationDirPath());
    // explicit Config(QString strPath = QDir::currentPath());
    ~Config();

public:
    void writeSettings(QString, QString, QVariant);
    QVariant readSettings(const QString&, const QString&);

private:
    QSettings *m_pSetting;
    QString m_strFilePath;
    QVariant m_varValue;
};

#endif // CONFIG_H
