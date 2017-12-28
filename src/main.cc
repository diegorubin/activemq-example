#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "gateways/activemq/consumer.h"

int main(int argc, char* argv[]) {
  activemq::library::ActiveMQCPP::initializeLibrary();

  std::string brokerURI = "failover:(tcp://localhost:61616)";

  Consumer consumer(brokerURI);
  Thread consumerThread(&consumer);
  consumerThread.start();

  consumerThread.join();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
