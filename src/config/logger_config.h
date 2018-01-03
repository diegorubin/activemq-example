#ifndef __CONFIG_LOGGER_H__
#define __CONFIG_LOGGER_H__

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>

#include "config/application_config.h"

using namespace log4cxx;

class LoggerConfig {

public:
  static void init();

  static void info(std::string message);

};

#endif

