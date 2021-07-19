#ifndef NAMINGSYSTEM_H
#define NAMINGSYSTEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include "xlsxdocument.h"

namespace Ui {
class NamingSystem;
}

class NamingSystem : public QWidget
{
    Q_OBJECT

public:
    explicit NamingSystem(QWidget *parent = nullptr);
    ~NamingSystem();

    QString getExcelItemData(QString fileName, QString itemName);
    QString getExcelItemData(QString fileName, int row, int col);

    QMap<int, QString> getIdInterToName(QString fileName);
    QMap<QString, QString> getIdInterToPath(QString fileName);

    // 获取excel行数(有多少人)
    int getExcelRowNumber(QString);

public slots:
    void slotSetScrollImage();
    void slotBtnStartStopNaming();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private slots:

    void on_btnChoose_clicked();

    void on_btnClose_clicked();

private:
    // 鼠标事件
    bool m_bPressedFlag;
    QPoint m_point;

    QTimer *m_pTimerSwitchImage;
    QString m_strImagePath;
    QString m_strExcelFileName;
    bool m_bNamingFlag;

private:
    Ui::NamingSystem *ui;
};

#endif // NAMINGSYSTEM_H
