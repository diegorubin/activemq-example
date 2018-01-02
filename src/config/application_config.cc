#include "config/application_config.h"

ApplicationConfig::ApplicationConfig() {
  brokerURI = string(loadFromEnv("BROKER_URI", "failover:(tcp://localhost:61616)"));
  queueName = string(loadFromEnv("QUEUE_NAME", "activemq.example.Binary"));
}

ApplicationConfig::~ApplicationConfig() {
}

string ApplicationConfig::getBrokerURI() {
  return brokerURI;
}

string ApplicationConfig::getQueueName() {
  return queueName;
}

const char* ApplicationConfig::loadFromEnv(const char* variable, const char* defaults) {
  const char* value = getenv(variable);
  if (!value) {
    cout << variable << "=" << defaults << endl;
    return defaults;
  }
  cout << variable << "=" << value << endl;
  return value;
}

