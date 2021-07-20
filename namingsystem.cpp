#include "namingsystem.h"
#include "ui_namingsystem.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QFileDialog>
#include <QDir>
#include "logger.h"

NamingSystem::NamingSystem(QWidget *parent) :
    QWidget(parent),
    m_bPressedFlag(false),
    m_strExcelFileName("21041.xlsx"),
    m_bNamingFlag(false),
    ui(new Ui::NamingSystem)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    // print log test, you can transfer any param to do format
//    int param = 1;

//    LOG_TRACE("this is trace log record, param: {}", ++param); // int type param is ok
//    LOG_DEBUG("this is debug log record, param: {}", ++param);
//    LOG_INFO("this is info log record, param: {}", ++param);
//    LOG_WARNING("this is warn log record, param: {}", double(++param)); // double type param is ok
//    LOG_ERROR("this is error log record, param: {}", std::to_string(++param)); // string type param is ok

    QMap<int, QString> m = getIdInterToName(m_strExcelFileName);
    QMap<QString, QString> mapTopath = getIdInterToPath(m_strExcelFileName);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    // 获取范围内随机数
    int n = qrand()%getExcelRowNumber(m_strExcelFileName) + 1;
    QString strName = mapTopath[m[n]];
    m_strImagePath = QString(":/image/%1").arg(strName);

    QString strpath = QString("border-image: url(:/image/%1)").arg(strName);
    ui->labelAvantar->setStyleSheet(strpath);
    ui->labelName->setText(m[n]);

    m_pTimerSwitchImage = new QTimer(this);
    connect(m_pTimerSwitchImage, &QTimer::timeout, this, &NamingSystem::slotSetScrollImage);
    connect(ui->btnStart, &QPushButton::clicked, this, &NamingSystem::slotBtnStartStopNaming);

    //    QXlsx::Document xlsx("21041.xlsx");
    //    xlsx.write("A1", "Hello Qt!");
    //    xlsx.write("A2", 12345);
    //    xlsx.write("A3", "=44+33");
    //    xlsx.write("A4", true);
    //    xlsx.write("A5", "http://qt-project.org");
    //    xlsx.write("A6", QDate(2013, 12, 27));
    //    xlsx.write("A7", QTime(6, 30));

    //    xlsx.save();
}

QString NamingSystem::getExcelItemData(QString fileName, QString itemName)
{
    QXlsx::Document xlsx(fileName);
    QString itemData = xlsx.read(itemName).toString();
    //qDebug() << "[" << __FUNCTION__ <<__LINE__ << "] :" << itemData;
    return itemData;
}

// 获取excel的行数
int NamingSystem::getExcelRowNumber(QString fileName)
{
    // 载入 excel 文件
    QXlsx::Document xlsx(fileName);
    // 减1 是因为表格第一行不是学生信息
    return xlsx.dimension().rowCount() - 1;
}

// 随机显示图片
void NamingSystem::slotSetScrollImage()
{
    if(m_strExcelFileName == "")
        return;
    QMap<int, QString> m = getIdInterToName(m_strExcelFileName);
    QMap<QString, QString> mapTopath = getIdInterToPath(m_strExcelFileName);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    // 获取范围内随机数
    int n = qrand()%getExcelRowNumber(m_strExcelFileName) + 1;
    QString strName = mapTopath[m[n]];
    ui->labelAvantar->setStyleSheet(QString("border-image: url(:/image/%1)").arg(strName));
    ui->labelName->setText(m[n]);
}

// 开始点名
void NamingSystem::slotBtnStartStopNaming()
{
    if(m_bNamingFlag == false){
        m_pTimerSwitchImage->start(400);
        ui->btnStart->setText("停止点名");
    }
    else {
        m_pTimerSwitchImage->stop();
        ui->btnStart->setText("开始点名");
    }
    m_bNamingFlag = !m_bNamingFlag;
}

void NamingSystem::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_bPressedFlag = true;
        m_point = event->globalPos() - this->pos();
    }
}

void NamingSystem::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressedFlag) {
        move(event->globalPos() - m_point);
    }
}

void NamingSystem::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)     // 处理声明但没有使用的参数警告
    m_bPressedFlag = false;
}

QString NamingSystem::getExcelItemData(QString fileName, int row, int col)
{
    QString itemData ;
    if(row < 1 || col < 1)
    {
        return "-1";
    }
    QXlsx::Document  xlsx(fileName);/*打开一个 book1 的文件*/
    QStringList sheetList = xlsx.sheetNames();
    if (sheetList.size() > 0)
    {
        itemData = xlsx.read(row, col).toString();
        qDebug() << "[" << __FUNCTION__ <<__LINE__ << "] :" <<  itemData;
    }
    else
    {
        qDebug() << "[" << __FUNCTION__ <<__LINE__ << "] : read error!" ;
        return "-1";
    }

    return itemData;
}

QMap<QString, QString> NamingSystem::getIdInterToPath(QString fileName)
{
    //载入 excel 文件
    QXlsx::Document xlsx(fileName);
    // 存储键值对
    QMap<QString, QString> myMapTopath;

    //获取工作表数目，并且选择第一个
    QStringList sheetList = xlsx.sheetNames();
    if (sheetList.size() > 0) {

        xlsx.selectSheet(sheetList[0]);     // 获取数据表名字
        QXlsx::CellRange range = xlsx.dimension();  //获取表格行数和列数

        for (int i = 2; i < range.rowCount()+1; ++i) {
            // 读取工作表有用数据插入数据库
            if (xlsx.cellAt(i, 3) != 0) {
                myMapTopath.insert(xlsx.cellAt(i, 2)->value().toString(), xlsx.cellAt(i, 3)->value().toString());
            }
        }
    }
    return myMapTopath;
}

QMap<int, QString> NamingSystem::getIdInterToName(QString fileName)
{
    //载入 excel 文件
    QXlsx::Document xlsx(fileName);
    // 存储键值对
    QMap<int, QString> myMap;
    QMap<QString, QString> myMapTopath;

    //获取工作表数目，并且选择第一个
    QStringList sheetList = xlsx.sheetNames();
    if (sheetList.size() > 0) {
        //获取数据表名字
        xlsx.selectSheet(sheetList[0]);
        //获取表格行数和列数
        QXlsx::CellRange range = xlsx.dimension();

        for (int i = 2; i < range.rowCount()+1; ++i) {
            // 读取工作表有用数据插入数据库
            if (xlsx.cellAt(i, 2) != 0) {
                myMap.insert(xlsx.cellAt(i, 1)->value().toInt(), xlsx.cellAt(i, 2)->value().toString());
            }
        }

        for (int i = 2; i < range.rowCount()+1; ++i) {
            // 读取工作表有用数据插入数据库
            if (xlsx.cellAt(i, 3) != 0) {
                myMapTopath.insert(xlsx.cellAt(i, 1)->value().toString(), xlsx.cellAt(i, 3)->value().toString());
            }
        }
    }

    // qDebug() << "[" << __FUNCTION__ <<__LINE__ << "] :" <<  myMap;
    return myMap;
}

NamingSystem::~NamingSystem()
{
    delete ui;
    delete  m_pTimerSwitchImage;
    m_pTimerSwitchImage = nullptr;
}

void NamingSystem::on_btnChoose_clicked()
{
    //获取应用程序的路径
    QString curPath = QDir::currentPath(); // 获取系统当前目录
    QString dlgTitle= "选择文件";  // 对话框标题
    QString filter = "表格文件(*.xlsx *.xls);;所有文件(*.*)"; // 文件过滤器

    // QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
    // for (int i=0; i<fileList.count();i++)
    //    ui->fileNameLabel->setText(fileList.at(i));
    m_strExcelFileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    LOG_WARNING("select invailed excel file!");
}

void NamingSystem::on_btnClose_clicked()
{
    close();
}
