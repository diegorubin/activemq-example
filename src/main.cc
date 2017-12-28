#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "gateways/activemq/consumer.h"
#include "gateways/activemq/producer.h"

int main(int argc, char* argv[]) {
  activemq::library::ActiveMQCPP::initializeLibrary();

  std::string brokerURI = "failover:(tcp://localhost:61616)";

  Producer producer(brokerURI);
  producer.connect();
  producer.publishText("apenas um texto");
  producer.close();

  Consumer consumer(brokerURI);
  consumer.connect();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
