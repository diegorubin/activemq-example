#include "config/logger_config.h"

static LoggerPtr logger(Logger::getLogger("ActiveMQExample"));

void LoggerConfig::init() {
  ApplicationConfig configs = ApplicationConfig::getInstance();

  if (configs.existsLoggerProperties()) {
    PropertyConfigurator::configure(configs.getLoggerProperties());
  } else {
    BasicConfigurator::configure();
  }
}

void LoggerConfig::info(std::string message) {
  LOG4CXX_INFO(logger, message)
}

