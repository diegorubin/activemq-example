#ifndef __GATEWAYS_ACTIVEMQ_PRODUCER_H__
#define __GATEWYAS_ACTIVEMQ_PRODUCER_H__

#include <activemq/core/ActiveMQConnectionFactory.h>
#include <cms/ExceptionListener.h>

using namespace activemq::core;
using namespace cms;
using namespace std;

class Producer {

private:
  // attributes
  Connection* connection;
  Destination* destination;
  MessageProducer* producer;
  Session* session;
  string brokerURI;

  // methods
  Producer(const Producer&);
  void cleanup();

public:
  Producer(const string& brokerURI);
  virtual ~Producer();

  void connect();
  void close();
  void publishText(string text);
};

#endif

