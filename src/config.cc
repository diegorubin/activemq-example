#include "config.h"

Config::Config() {
  brokerURI = string(loadFromEnv("BROKER_URI", "failover:(tcp://localhost:61616)"));
  queueName = string(loadFromEnv("QUEUE_NAME", "activemq.example.Binary"));
}

Config::~Config() {
}

string Config::getBrokerURI() {
  return brokerURI;
}

string Config::getQueueName() {
  return queueName;
}

const char* Config::loadFromEnv(const char* variable, const char* defaults) {
  const char* value = getenv(variable);
  if (!value) {
    cout << variable << "=" << defaults << endl;
    return defaults;
  }
  cout << variable << "=" << value << endl;
  return value;
}

