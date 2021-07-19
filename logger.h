#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <time.h>
#include <chrono>
#include <string>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no color needed
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"


static inline int nowTimeToInt()
{
    time_t now;
    time(&now);
    // choose thread save version in each platform
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_int = p.tm_hour * 10000 + p.tm_min * 100 + p.tm_sec;
    return now_int;
}

static inline int nowDateToInt()
{
    time_t now;
    time(&now);

    // choose thread save version in each platform
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32
    int now_date = (1900 + p.tm_year) * 10000 + (p.tm_mon + 1) * 100 + p.tm_mday;
    return now_date;
}

static inline int nowMonTime()
{
    time_t now;
    time(&now);
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_mon = p.tm_mon;
    return now_mon;
}

static inline int nowDayTime()
{
    time_t now;
    time(&now);
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_day = p.tm_mday;
    return now_day;
}

static inline int nowYearTime()
{
    time_t now;
    time(&now);
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_year = p.tm_year;
    return now_year;
}

class Logger
{
public:
    static Logger* getInstance(){
        static Logger logger;
        return &logger;
    }

    std::shared_ptr<spdlog::logger> getLogger(){
        return m_logger;
    }

private:
    // make constructor private to avoid outside instance
    Logger()
    {
        // should create the folder if not exist
        const std::string log_dir = "./log/" + std::to_string(nowYearTime() + 1900)
                + "/" + std::to_string(nowMonTime() + 1) + "/";
        // decide print to console or log file
        bool console = false;

        // decide the log level
        std::string level = "debug";

        try
        {
            // const std::string logger_name = logger_name_prefix + std::to_string(date) + "_" + std::to_string(time);
            //const std::string logger_name = std::to_string(nowMonTime()) + std::to_string(nowDayTime());

            const std::string logger_name = std::to_string(nowDateToInt());
            if (console)
                m_logger = spdlog::stdout_color_st(logger_name); // single thread console output faster
            else
                m_logger = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(logger_name, log_dir + "/" + logger_name + ".log", 100 * 1024 * 1024, 1000); // multi part log files, with every part 500M, max 1000 files

            // custom format
            // m_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%f] <thread %t> [%l] [%@] %v"); // with timestamp, thread_id, filename and line number
            m_logger->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v"); // with timestamp, thread_id, filename and line number

            if (level == "trace")
            {
                m_logger->set_level(spdlog::level::trace);
                m_logger->flush_on(spdlog::level::trace);
            }
            else if (level == "debug")
            {
                m_logger->set_level(spdlog::level::debug);
                m_logger->flush_on(spdlog::level::debug);
            }
            else if (level == "info")
            {
                m_logger->set_level(spdlog::level::info);
                m_logger->flush_on(spdlog::level::info);
            }
            else if (level == "warn")
            {
                m_logger->set_level(spdlog::level::warn);
                m_logger->flush_on(spdlog::level::warn);
            }
            else if (level == "error")
            {
                m_logger->set_level(spdlog::level::err);
                m_logger->flush_on(spdlog::level::err);
            }
        }
        catch (const spdlog::spdlog_ex& ex)
        {
            std::cout << "Log initialization failed: " << ex.what() << std::endl;
        }
    }

    ~Logger()
    {
        spdlog::drop_all(); // must do this
    }

    void *operator new(size_t size){

    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    std::shared_ptr<spdlog::logger> m_logger;
};

// use embedded macro to support file and line number
#define LOG_TRACE(...) SPDLOG_LOGGER_CALL(Logger::getInstance()->getLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_CALL(Logger::getInstance()->getLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_CALL(Logger::getInstance()->getLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARNING(...) SPDLOG_LOGGER_CALL(Logger::getInstance()->getLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_CALL(Logger::getInstance()->getLogger().get(), spdlog::level::err, __VA_ARGS__)
