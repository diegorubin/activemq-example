#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "config.h"
#include "gateways/activemq/producer.h"

int main(int argc, char* argv[]) {
  Config configs;
  activemq::library::ActiveMQCPP::initializeLibrary();

  Producer producer(configs.getBrokerURI());
  producer.connect();

  for (int i = 0; i < 10; i++) {
    producer.publishText("text message");
  }

  producer.close();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
