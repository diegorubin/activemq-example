#ifndef __GATEWAYS_ACTIVEMQ_CONSUMER_H__
#define __GATEWYAS_ACTIVEMQ_CONSUMER_H__

#include <activemq/core/ActiveMQConnectionFactory.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <decaf/lang/Runnable.h>
#include <iostream>
#include <memory>

#include "config/logger_config.h"
#include "services/message_processor.h"

using namespace activemq::core;
using namespace cms;
using namespace decaf::lang;
using namespace std;

class Consumer : public ExceptionListener,
                 public MessageListener {

private:
  // attributes
  Connection* connection;
  Destination* destination;
  MessageConsumer* consumer;
  Session* session;
  string brokerURI;
  string queueName;

  // methods
  Consumer(const Consumer&);
  void cleanup();

public:
  Consumer(const string& brokerURI, const string& queueName);
  virtual ~Consumer();

  virtual void onMessage(const Message* message);
  virtual void onException(const CMSException& ex AMQCPP_UNUSED);

  void close();
  void connect();
};

#endif
