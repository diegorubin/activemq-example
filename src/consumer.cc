#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "config/application_config.h"
#include "config/logger_config.h"
#include "gateways/activemq/consumer.h"

int main(int argc, char* argv[]) {
  ApplicationConfig configs = ApplicationConfig::getInstance();

  LoggerConfig::init();
  activemq::library::ActiveMQCPP::initializeLibrary();

  LoggerConfig::info("starting consumer");

  Consumer consumer(configs.getBrokerURI(), configs.getQueueName());
  consumer.connect();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
