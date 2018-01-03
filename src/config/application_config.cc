#include "config/application_config.h"

static ApplicationConfig instance;

ApplicationConfig::ApplicationConfig() {
  brokerURI = string(loadFromEnv("BROKER_URI", "failover:(tcp://localhost:61616)"));
  queueName = string(loadFromEnv("QUEUE_NAME", "activemq.example.Binary"));
  loggerProperties = string(loadFromEnv("LOGGER_PROPERTIES", "~/example.properties"));
}

ApplicationConfig::~ApplicationConfig() {
}

string ApplicationConfig::getBrokerURI() {
  return brokerURI;
}

string ApplicationConfig::getQueueName() {
  return queueName;
}

string ApplicationConfig::getLoggerProperties() {
  return loggerProperties;
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

bool ApplicationConfig::existsLoggerProperties() {
  ifstream *properties = new ifstream(loggerProperties);
  return !!*properties;
}


ApplicationConfig ApplicationConfig::getInstance() {
  return instance;
}

