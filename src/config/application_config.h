#ifndef __CONFIG_APPLICATION_CONFIG_H__
#define __CONFIG_APPLICATION_CONFIG_H__

#include <iostream>
#include <fstream>

using namespace std;

class ApplicationConfig {

private:

  // attributes
  string brokerURI;
  string queueName;
  string loggerProperties;

  // methods
  const char* loadFromEnv(const char* variable, const char* defaults);

public:

  ApplicationConfig();
  virtual ~ApplicationConfig();

  string getBrokerURI();
  string getQueueName();
  string getLoggerProperties();

  bool existsLoggerProperties();

  static ApplicationConfig getInstance();
};

#endif

