#ifndef __CONFIG_APPLICATION_CONFIG_H__
#define __CONFIG_APPLICATION_CONFIG_H__

#include <iostream>

using namespace std;

class ApplicationConfig {

private:

  // attributes
  string brokerURI;
  string queueName;

  // methods
  const char* loadFromEnv(const char* variable, const char* defaults);

public:

  ApplicationConfig();
  virtual ~ApplicationConfig();

  string getBrokerURI();
  string getQueueName();

};

#endif

