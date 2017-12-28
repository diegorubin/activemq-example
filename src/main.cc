#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <iostream>

#include "config.h"
#include "gateways/activemq/consumer.h"

int main(int argc, char* argv[]) {
  Config configs;
  activemq::library::ActiveMQCPP::initializeLibrary();

  activemq::library::ActiveMQCPP::shutdownLibrary();
	return 0;
}
