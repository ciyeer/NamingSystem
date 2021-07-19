#include "namingsystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    NamingSystem w;
    w.show();

    return a.exec();
}

//int main()
//{
//	// print log test, you can transfer any param to do format
//	int param = 1;

//	XLOG_TRACE("this is trace log record, param: {}", ++param); // int type param is ok
//	XLOG_DEBUG("this is debug log record, param: {}", ++param);
//	XLOG_INFO("this is info log record, param: {}", ++param);
//	XLOG_WARN("this is warn log record, param: {}", double(++param)); // double type param is ok
//	XLOG_ERROR("this is error log record, param: {}", std::to_string(++param)); // string type param is ok

//	return 0;
//}
