#ifndef LOG_HPP
#define LOG_HPP
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"    // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging
#include "spdlog/spdlog.h"
#include <memory>

namespace project_global {
extern std::shared_ptr<spdlog::logger> logger;
extern bool initialized;
extern int init_log();
} // namespace project_global

#endif
