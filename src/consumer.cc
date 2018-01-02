#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "config/application_config.h"
#include "gateways/activemq/consumer.h"

int main(int argc, char* argv[]) {
  ApplicationConfig configs;
  activemq::library::ActiveMQCPP::initializeLibrary();

  Consumer consumer(configs.getBrokerURI(), configs.getQueueName());
  consumer.connect();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
