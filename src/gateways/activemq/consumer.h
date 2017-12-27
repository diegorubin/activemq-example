#ifndef __GATEWAYS_ACTIVEMQ_CONSUMER_H__
#define __GATEWYAS_ACTIVEMQ_CONSUMER_H__

#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <decaf/lang/Runnable.h>

using namespace activemq::core;

class Consumer : public ExceptionListener,
                 public MessageListener,
                 public Runnable {

};

#endif
