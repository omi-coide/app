#include "log.hpp"
#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/basic_file_sink.h"    // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <memory>
#include <vector>
bool project_global::initialized = false;
std::shared_ptr<spdlog::logger> project_global::logger;
int project_global::init_log() {
  char buffer[9];
  char *env;
  env = std::getenv("SPDLOG_LEVEL");
  if (env != nullptr)
    std::strncpy(buffer, env, 9);
  else
    std::strncpy(buffer, "info", 9);
  std::vector<spdlog::sink_ptr> sinks;
  auto sink1 = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
  sinks.push_back(sink1);
  auto sink2 = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
      "./app.log", 1024 * 1024 * 5, 3);
  sinks.push_back(sink2);

  logger = std::make_shared<spdlog::logger>("main", std::begin(sinks),
                                            std::end(sinks));
  spdlog::register_logger(logger);

  if (std::strncmp(buffer, "info", 5) == 0) {
    logger->set_level(spdlog::level::info);
    logger->flush_on(spdlog::level::info);
  } else if (std::strncmp(buffer, "error", 6) == 0) {
    logger->set_level(spdlog::level::err);
    logger->flush_on(spdlog::level::err);
  } else if (std::strncmp(buffer, "debug", 6) == 0) {
    logger->set_level(spdlog::level::debug);
    logger->flush_on(spdlog::level::debug);
  } else if (std::strncmp(buffer, "trace", 6) == 0) {
    logger->set_level(spdlog::level::trace);
    logger->flush_on(spdlog::level::trace);
  } else {
    logger->set_level(spdlog::level::info);
    logger->flush_on(spdlog::level::info);
  }
  logger->info("logger initialized!");
  /*
   logging level :

   */
  initialized = true;
  return 0;
}
