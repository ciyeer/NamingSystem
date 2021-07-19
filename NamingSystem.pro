#-------------------------------------------------
#
# Project created by QtCreator 2021-07-05T11:41:56
#
#-------------------------------------------------

QT       += core gui

# 使用qtxlsx源代码
include(qtxlsx/src/xlsx/qtxlsx.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NamingSystem

INCLUDEPATH += C:/software/boost_1_76_0/


TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 axcontainer

SOURCES += \
        config.cpp \
        main.cpp \
        namingsystem.cpp

HEADERS += \
        commonhelper.h \
        config.h \
        logger.h \
        logger/logger.h \
        logger/spdlog/async.h \
        logger/spdlog/async_logger-inl.h \
        logger/spdlog/async_logger.h \
        logger/spdlog/cfg/argv.h \
        logger/spdlog/cfg/env.h \
        logger/spdlog/cfg/helpers-inl.h \
        logger/spdlog/cfg/helpers.h \
        logger/spdlog/common-inl.h \
        logger/spdlog/common.h \
        logger/spdlog/details/backtracer-inl.h \
        logger/spdlog/details/backtracer.h \
        logger/spdlog/details/circular_q.h \
        logger/spdlog/details/console_globals.h \
        logger/spdlog/details/file_helper-inl.h \
        logger/spdlog/details/file_helper.h \
        logger/spdlog/details/fmt_helper.h \
        logger/spdlog/details/log_msg-inl.h \
        logger/spdlog/details/log_msg.h \
        logger/spdlog/details/log_msg_buffer-inl.h \
        logger/spdlog/details/log_msg_buffer.h \
        logger/spdlog/details/mpmc_blocking_q.h \
        logger/spdlog/details/null_mutex.h \
        logger/spdlog/details/os-inl.h \
        logger/spdlog/details/os.h \
        logger/spdlog/details/periodic_worker-inl.h \
        logger/spdlog/details/periodic_worker.h \
        logger/spdlog/details/registry-inl.h \
        logger/spdlog/details/registry.h \
        logger/spdlog/details/synchronous_factory.h \
        logger/spdlog/details/tcp_client-windows.h \
        logger/spdlog/details/tcp_client.h \
        logger/spdlog/details/thread_pool-inl.h \
        logger/spdlog/details/thread_pool.h \
        logger/spdlog/details/windows_include.h \
        logger/spdlog/fmt/bin_to_hex.h \
        logger/spdlog/fmt/bundled/args.h \
        logger/spdlog/fmt/bundled/chrono.h \
        logger/spdlog/fmt/bundled/color.h \
        logger/spdlog/fmt/bundled/compile.h \
        logger/spdlog/fmt/bundled/core.h \
        logger/spdlog/fmt/bundled/format-inl.h \
        logger/spdlog/fmt/bundled/format.h \
        logger/spdlog/fmt/bundled/locale.h \
        logger/spdlog/fmt/bundled/os.h \
        logger/spdlog/fmt/bundled/ostream.h \
        logger/spdlog/fmt/bundled/printf.h \
        logger/spdlog/fmt/bundled/ranges.h \
        logger/spdlog/fmt/bundled/xchar.h \
        logger/spdlog/fmt/chrono.h \
        logger/spdlog/fmt/compile.h \
        logger/spdlog/fmt/fmt.h \
        logger/spdlog/fmt/ostr.h \
        logger/spdlog/fmt/xchar.h \
        logger/spdlog/formatter.h \
        logger/spdlog/fwd.h \
        logger/spdlog/logger-inl.h \
        logger/spdlog/logger.h \
        logger/spdlog/pattern_formatter-inl.h \
        logger/spdlog/pattern_formatter.h \
        logger/spdlog/sinks/android_sink.h \
        logger/spdlog/sinks/ansicolor_sink-inl.h \
        logger/spdlog/sinks/ansicolor_sink.h \
        logger/spdlog/sinks/base_sink-inl.h \
        logger/spdlog/sinks/base_sink.h \
        logger/spdlog/sinks/basic_file_sink-inl.h \
        logger/spdlog/sinks/basic_file_sink.h \
        logger/spdlog/sinks/daily_file_sink.h \
        logger/spdlog/sinks/dist_sink.h \
        logger/spdlog/sinks/dup_filter_sink.h \
        logger/spdlog/sinks/hourly_file_sink.h \
        logger/spdlog/sinks/mongo_sink.h \
        logger/spdlog/sinks/msvc_sink.h \
        logger/spdlog/sinks/null_sink.h \
        logger/spdlog/sinks/ostream_sink.h \
        logger/spdlog/sinks/qt_sinks.h \
        logger/spdlog/sinks/ringbuffer_sink.h \
        logger/spdlog/sinks/rotating_file_sink-inl.h \
        logger/spdlog/sinks/rotating_file_sink.h \
        logger/spdlog/sinks/sink-inl.h \
        logger/spdlog/sinks/sink.h \
        logger/spdlog/sinks/stdout_color_sinks-inl.h \
        logger/spdlog/sinks/stdout_color_sinks.h \
        logger/spdlog/sinks/stdout_sinks-inl.h \
        logger/spdlog/sinks/stdout_sinks.h \
        logger/spdlog/sinks/syslog_sink.h \
        logger/spdlog/sinks/systemd_sink.h \
        logger/spdlog/sinks/tcp_sink.h \
        logger/spdlog/sinks/win_eventlog_sink.h \
        logger/spdlog/sinks/wincolor_sink-inl.h \
        logger/spdlog/sinks/wincolor_sink.h \
        logger/spdlog/spdlog-inl.h \
        logger/spdlog/spdlog.h \
        logger/spdlog/stopwatch.h \
        logger/spdlog/tweakme.h \
        logger/spdlog/version.h \
        namingsystem.h \
        spdlog/async.h \
        spdlog/async_logger-inl.h \
        spdlog/async_logger.h \
        spdlog/cfg/argv.h \
        spdlog/cfg/env.h \
        spdlog/cfg/helpers-inl.h \
        spdlog/cfg/helpers.h \
        spdlog/common-inl.h \
        spdlog/common.h \
        spdlog/details/backtracer-inl.h \
        spdlog/details/backtracer.h \
        spdlog/details/circular_q.h \
        spdlog/details/console_globals.h \
        spdlog/details/file_helper-inl.h \
        spdlog/details/file_helper.h \
        spdlog/details/fmt_helper.h \
        spdlog/details/log_msg-inl.h \
        spdlog/details/log_msg.h \
        spdlog/details/log_msg_buffer-inl.h \
        spdlog/details/log_msg_buffer.h \
        spdlog/details/mpmc_blocking_q.h \
        spdlog/details/null_mutex.h \
        spdlog/details/os-inl.h \
        spdlog/details/os.h \
        spdlog/details/periodic_worker-inl.h \
        spdlog/details/periodic_worker.h \
        spdlog/details/registry-inl.h \
        spdlog/details/registry.h \
        spdlog/details/synchronous_factory.h \
        spdlog/details/tcp_client-windows.h \
        spdlog/details/tcp_client.h \
        spdlog/details/thread_pool-inl.h \
        spdlog/details/thread_pool.h \
        spdlog/details/windows_include.h \
        spdlog/fmt/bin_to_hex.h \
        spdlog/fmt/bundled/args.h \
        spdlog/fmt/bundled/chrono.h \
        spdlog/fmt/bundled/color.h \
        spdlog/fmt/bundled/compile.h \
        spdlog/fmt/bundled/core.h \
        spdlog/fmt/bundled/format-inl.h \
        spdlog/fmt/bundled/format.h \
        spdlog/fmt/bundled/locale.h \
        spdlog/fmt/bundled/os.h \
        spdlog/fmt/bundled/ostream.h \
        spdlog/fmt/bundled/printf.h \
        spdlog/fmt/bundled/ranges.h \
        spdlog/fmt/bundled/xchar.h \
        spdlog/fmt/chrono.h \
        spdlog/fmt/compile.h \
        spdlog/fmt/fmt.h \
        spdlog/fmt/ostr.h \
        spdlog/fmt/xchar.h \
        spdlog/formatter.h \
        spdlog/fwd.h \
        spdlog/logger-inl.h \
        spdlog/logger.h \
        spdlog/pattern_formatter-inl.h \
        spdlog/pattern_formatter.h \
        spdlog/sinks/android_sink.h \
        spdlog/sinks/ansicolor_sink-inl.h \
        spdlog/sinks/ansicolor_sink.h \
        spdlog/sinks/base_sink-inl.h \
        spdlog/sinks/base_sink.h \
        spdlog/sinks/basic_file_sink-inl.h \
        spdlog/sinks/basic_file_sink.h \
        spdlog/sinks/daily_file_sink.h \
        spdlog/sinks/dist_sink.h \
        spdlog/sinks/dup_filter_sink.h \
        spdlog/sinks/hourly_file_sink.h \
        spdlog/sinks/mongo_sink.h \
        spdlog/sinks/msvc_sink.h \
        spdlog/sinks/null_sink.h \
        spdlog/sinks/ostream_sink.h \
        spdlog/sinks/qt_sinks.h \
        spdlog/sinks/ringbuffer_sink.h \
        spdlog/sinks/rotating_file_sink-inl.h \
        spdlog/sinks/rotating_file_sink.h \
        spdlog/sinks/sink-inl.h \
        spdlog/sinks/sink.h \
        spdlog/sinks/stdout_color_sinks-inl.h \
        spdlog/sinks/stdout_color_sinks.h \
        spdlog/sinks/stdout_sinks-inl.h \
        spdlog/sinks/stdout_sinks.h \
        spdlog/sinks/syslog_sink.h \
        spdlog/sinks/systemd_sink.h \
        spdlog/sinks/tcp_sink.h \
        spdlog/sinks/win_eventlog_sink.h \
        spdlog/sinks/wincolor_sink-inl.h \
        spdlog/sinks/wincolor_sink.h \
        spdlog/spdlog-inl.h \
        spdlog/spdlog.h \
        spdlog/stopwatch.h \
        spdlog/tweakme.h \
        spdlog/version.h

FORMS += \
        namingsystem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
