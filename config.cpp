#include "config.h"

Config::Config(QString strPath){
    m_strFilePath = strPath;
    m_pSetting = new QSettings(m_strFilePath, QSettings::IniFormat);
}

void Config::writeSettings(QString beginGroup, QString key, QVariant value){
    m_pSetting->beginGroup(beginGroup);
    m_pSetting->setValue(key, value);
    m_pSetting->endGroup();
}

QVariant Config::readSettings(const QString &beginGroup, const QString &key){
    m_pSetting->beginGroup(beginGroup);
    m_varValue = m_pSetting->value(key);
    m_pSetting->endGroup();
    return m_varValue;
}

Config::~Config(){
    delete m_pSetting;
    m_pSetting = nullptr;
}
