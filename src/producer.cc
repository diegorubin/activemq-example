#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "config.h"
#include "gateways/activemq/producer.h"

int main(int argc, char* argv[]) {
  Config configs;
  activemq::library::ActiveMQCPP::initializeLibrary();

  Producer producer(configs.getBrokerURI(), configs.getQueueName());
  producer.connect();

  for (int i = 0; i < 10; i++) {
    unsigned char *buffer = new unsigned char[4];
    buffer[0] = 0x0;
    buffer[1] = 0x0;
    buffer[2] = 0x0;
    buffer[3] = 0x1f;
    producer.publishBytes(buffer, 4);
  }

  producer.close();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
