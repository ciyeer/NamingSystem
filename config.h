#ifndef CONFIG_H
#define CONFIG_H
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDir>

class Config
{
public:

    explicit Config(QString strPath = QCoreApplication::applicationDirPath());
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
